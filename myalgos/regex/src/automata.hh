#pragma once

#include <vector>
#include "regex.hh"

class Automata
{

public:
  using vertex_t = std::size_t;
  static constexpr int TRANS_EPS = 666;
  
  struct AdjList
  {
    AdjList* next;
    vertex_t other;
    int trans;
  };

public:
  void add_vertex(vertex_t v, bool is_final = false);
  void add_edge(vertex_t u, vertex_t v, int trans);
  void set_final(vertex_t v, bool is_final);
  const AdjList* adj(vertex_t v) const;

  vertex_t nb_vertices() const { return _adjs.size(); }

  void dump();
		
private:
  std::vector<int> _final;
  std::vector<AdjList*> _adjs;  
};


//thompsons algorithm
Automata res_to_nfa(const RegexPtr& node); 


//
Automata nfa_to_dfa(const Automata& src);
