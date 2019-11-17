#include <iostream>

#include "automata.hh"
#include "regex.hh"

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    std::cerr << "Usage: ./res <regex>" << std::endl;
    return 1;
  }

  std::string arg(argv[1]);
  RegexParser parser(arg);

  auto res = parser.parse();
  res->dump();
  std::cout << std::endl;

  auto nfa = res_to_nfa(res);
  nfa.dump();
  std::cout << std::endl;
  
  return 0;
}
