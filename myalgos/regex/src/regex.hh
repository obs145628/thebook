#pragma once

#include <string>
#include <memory>

class RegexNode;
using RegexPtr = std::unique_ptr<RegexNode>;

class RegexNode
{
public:

  virtual void dump() = 0;
  
};


class RegexConcat : public RegexNode
{
public:
  RegexConcat(RegexPtr&& left, RegexPtr&& right)
    : _left(std::move(left))
    , _right(std::move(right))
  {}

  void dump() override;

  const RegexNode& left() const { return *_left; }
  const RegexNode& right() const { return *_right; }

private:
  RegexPtr _left;
  RegexPtr _right;
};

class RegexOr : public RegexNode
{
public:
  RegexOr(RegexPtr&& left, RegexPtr&& right)
    : _left(std::move(left))
    , _right(std::move(right))
  {}

  void dump() override;

  const RegexNode& left() const { return *_left; }
  const RegexNode& right() const { return *_right; }

private:
  RegexPtr _left;
  RegexPtr _right;
};

class RegexKleene : public RegexNode
{
public:
  RegexKleene(RegexPtr&& left)
    : _left(std::move(left))
  {}

  void dump() override;

  const RegexNode& left() const { return *_left; }

private:
  RegexPtr _left;
};

class RegexChar : public RegexNode
{
public:
  RegexChar(char c):
    _c(c)
  {}

  void dump() override;

  char c() const { return _c; }

private:
  char _c;
};



class RegexParser
{

public:
  RegexParser(const std::string& str)
    : _str(str)
    , _pos(0)
  {}

  /*
   * res: ors
   * ors: ands | ['|' ands]*
   * ands: uni+
   * uni: atom '*'*

   * atom: <char> | '(' res ')'
   */
  RegexPtr parse();

private:
  std::string _str;
  std::size_t _pos;

  int _peek();
  int _next();

  RegexPtr _res();
  RegexPtr _ors();
  RegexPtr _ands();
  RegexPtr _uni();
  RegexPtr _atom();
  
};
