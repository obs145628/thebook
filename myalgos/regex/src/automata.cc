#include "automata.hh"
#include <set>
#include <cassert>
#include <iostream>

void Automata::add_vertex(vertex_t v, bool is_final)
{
  assert(_adjs.size() == v);
  _adjs.push_back(nullptr);
  _final.push_back(is_final);
}

void Automata::add_edge(vertex_t u, vertex_t v, int trans)
{
  assert(u < _adjs.size());
  assert(v < _adjs.size());
  auto l = &_adjs[u];
  while (*l)
  {
    auto node = *l;
    if (node->other == v && node->trans == trans)
      return;
    l = &(node->next);
  }

  auto new_node = new AdjList;
  new_node->next = nullptr;
  new_node->other = v;
  new_node->trans = trans;
  *l = new_node;
}

void Automata::set_final(vertex_t v, bool is_final)
{
  assert(v < _adjs.size());
  _final[v] = is_final;
}

const Automata::AdjList* Automata::adj(vertex_t v) const
{
  assert(v < _adjs.size());
  return _adjs[v];
}

void Automata::dump()
{
  for (std::size_t i = 0; i < _adjs.size(); ++i)
  {
    if (_final[i])
      std::cout << "[" << i << "]";
    else
      std::cout << i;
    std::cout << ": ";
    auto node = _adjs[i];
    
    while (node)
    {
      std::cout << node->other << " (";
      if (node->trans == TRANS_EPS)
	std::cout << "<<E>>";
      else
	std::cout << static_cast<char>(node->trans);
      std::cout << ")";
      if (node->next)
	std::cout << " -> ";
      node = node->next;
    }
    std::cout << std::endl;
  }
}


namespace
{

  struct NfaConst
  {
    Automata::vertex_t beg;
    Automata::vertex_t end;
  };
  NfaConst res_to_nfa_rec(Automata& aut, const RegexNode& node);
  

  NfaConst res_to_nfa_char(Automata& aut, const RegexChar& node)
  {
    auto u = aut.nb_vertices();
    auto v = u + 1;
    aut.add_vertex(u, false);
    aut.add_vertex(v, false);
    aut.add_edge(u, v, node.c());

    struct NfaConst res;
    res.beg = u;
    res.end = v;
    return res;
  }

  NfaConst res_to_nfa_concat(Automata& aut, const RegexConcat& node)
  {
    auto left = res_to_nfa_rec(aut, node.left());
    auto right = res_to_nfa_rec(aut, node.right());

    aut.add_edge(left.end, right.beg, Automata::TRANS_EPS);
    struct NfaConst res;
    res.beg = left.beg;
    res.end = right.end;
    return res;
  }

  NfaConst res_to_nfa_or(Automata& aut, const RegexOr& node)
  {
    auto left = res_to_nfa_rec(aut, node.left());
    auto right = res_to_nfa_rec(aut, node.right());

    auto u = aut.nb_vertices();
    auto v = u + 1;
    aut.add_vertex(u, false);
    aut.add_vertex(v, false);
    aut.add_edge(u, left.beg, Automata::TRANS_EPS);
    aut.add_edge(u, right.beg, Automata::TRANS_EPS);
    aut.add_edge(left.end, v, Automata::TRANS_EPS);
    aut.add_edge(right.end, v, Automata::TRANS_EPS);

    struct NfaConst res;
    res.beg = u;
    res.end = v;
    return res;
  }

  NfaConst res_to_nfa_kleene(Automata& aut, const RegexKleene& node)
  {
    auto left = res_to_nfa_rec(aut, node.left());
    auto u = aut.nb_vertices();
    auto v = u + 1;
    aut.add_vertex(u, false);
    aut.add_vertex(v, false);
    
    aut.add_edge(u, left.beg, Automata::TRANS_EPS);
    aut.add_edge(u, v, Automata::TRANS_EPS);
    aut.add_edge(left.end, left.beg, Automata::TRANS_EPS);

    struct NfaConst res;
    res.beg = u;
    res.end = v;
    return res;
  }
  

  NfaConst res_to_nfa_rec(Automata& aut, const RegexNode& node)
  {
    if (auto node_char = dynamic_cast<const RegexChar*>(&node))
      return res_to_nfa_char(aut, *node_char);
    else if (auto node_concat = dynamic_cast<const RegexConcat*>(&node))
      return res_to_nfa_concat(aut, *node_concat);
    else if (auto node_or = dynamic_cast<const RegexOr*>(&node))
      return res_to_nfa_or(aut, *node_or);
    else if (auto node_kleene = dynamic_cast<const RegexKleene*>(&node))
      return res_to_nfa_kleene(aut, *node_kleene);
    else
      throw std::runtime_error {"res_to_nfa: unreachable"};
  }
  
}


Automata res_to_nfa(const RegexPtr& node)
{
  Automata res;
  auto full = res_to_nfa_rec(res, *node);
  res.set_final(full.end, true);
  return res;
}

namespace
{

  using vertex_t = Automata::vertex_t;

  #if 0
  void eps_closure(const Automata& src, vertex_t v, std::set<vertex_t>& out)
  {
    if (out.insert(v).second != true)
      return;

    auto adj = src.adj(v);
    while (adj)
    {
      if (adj->trans == Automata::TRANS_EPS)
	eps_closure(src, adj->other, out);
      adj = adj->next;
    }
  }

  std::set<vertex_t> eps_closure(const Automata& src, const std::set<vertex_t>& in)
  {
    std::set<vertex_t> out;
    for (auto x : in)
      eps_closure(src, x, out);
    return out;
  }
  #endif
  
  
}


Automata nfa_to_dfa(const Automata& src)
{
  //TODO
  return src;
}
