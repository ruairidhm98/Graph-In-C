#include "vertex.h"
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
    v->adj_list = NULL;
  }

  return v;
}

unsigned int v_get_index(Vertex *v) { return v ? v->index : __INT_MAX__; }

void v_set_dist(Vertex *v, unsigned int dist) { v ? v->dist = dist : -1; }

void v_add_adj_list(Vertex *v, Vertex *n) { v && n ? /*  */ 1 : 2; }

void v_destroy(Vertex *v) {
  free(v);
}

int main() {
  Vertex *v = v_init(2);
  printf("index = %d\n", v_get_index(v));
  v_set_dist(v, 10);
  printf("dist = %d\n", v->dist);
  v_destroy(v);
  return 0;
}