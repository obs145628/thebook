#include "regex.hh"
#include <cstdio>
#include <iostream>
#include <stdexcept>

namespace
{
  bool is_regex_char(char c)
  {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
  }
}


void RegexConcat::dump()
{
  std::cout << "(";
  _left->dump();
  std::cout << ")(";
  _right->dump();
  std::cout << ")";
}

void RegexOr::dump()
{
  std::cout << "(";
  _left->dump();
  std::cout << ")|(";
  _right->dump();
  std::cout << ")";
}

void RegexKleene::dump()
{
  std::cout << "(";
  _left->dump();
  std::cout << ")*";
}

void RegexChar::dump()
{
  std::cout << _c;
}




RegexPtr RegexParser::parse()
{
  auto val = _res();
  if (_next() != EOF)
    throw std::runtime_error {"RegexParser::parse(): Expected EOF"};
  return val;
}

int RegexParser::_peek()
{
  return _pos == _str.size() ? EOF : _str[_pos];
}

int RegexParser::_next()
{
  return _pos == _str.size() ? EOF : _str[_pos++];
}

RegexPtr RegexParser::_res()
{
  return _ors();
}

RegexPtr RegexParser::_ors()
{
  auto res = _ands();
  for (;;)
  {
    auto c = _peek();
    if (c != '|')
      break;
    _next();
    res = std::make_unique<RegexOr>(std::move(res), _ands());
  }
  
  return res;
}

RegexPtr RegexParser::_ands()
{
  auto res = _uni();
  for (;;)
  {
    int c = _peek();
    if (!is_regex_char(c) && c != '(')
      break;

    res = std::make_unique<RegexConcat>(std::move(res), _uni());
  }

  return res;
}

RegexPtr RegexParser::_uni()
{
  auto res = _atom();
  while (_peek() == '*')
  {
    _next();
    res = std::make_unique<RegexKleene>(std::move(res));
  }
  return res;
}

RegexPtr RegexParser::_atom()
{
  int c = _peek();
  if (is_regex_char(c))
    return std::make_unique<RegexChar>(_next());

  if (_next() != '(')
    throw std::runtime_error{"RegexParser::_atom(): Expected '('"};
  auto val = _res();
  if (_next() != ')')
    throw std::runtime_error{"RegexParser::_atom(): Expected ')'"};
  return val;
}
