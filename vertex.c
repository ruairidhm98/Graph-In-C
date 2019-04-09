#include "vertex.h"
#include "adj_list.h"
#include <stdlib.h>
#include <stdio.h>

/* Vertex in the graph */
struct vertex {
  unsigned int dist;  // used in shortest path algorithms
  unsigned int index; // index into the graph array
  AdjList *adj_list;  // neighbours of the vertex
};

Vertex *v_init(unsigned int index) {

  Vertex *v = (Vertex *)malloc(sizeof(Vertex));
  
  if (v) {
    v->dist = 0;
    v->index = index;
    v->adj_list = adj_list_init();
  }

  return v;
}

unsigned int v_get_index(Vertex *v) { return v ? v->index : __INT_MAX__; }

AdjList *v_get_adj_list(Vertex *v) { return v ? v->adj_list : NULL; }

void v_set_dist(Vertex *v, unsigned int dist) { v ? v->dist = dist : -1; }

void v_add_adj_list(Vertex *v, Vertex *n, unsigned int weight) {
  v && n ? adj_list_add(v->adj_list, n, weight) : 0; 
}

void v_destroy(Vertex *v) {
  adj_list_destroy(v->adj_list);
  free(v);
}
