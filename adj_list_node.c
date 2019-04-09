#include "adj_list_node.h"
#include <stdio.h>
#include <stdlib.h>

/* Node in adjacency list */
struct adj_list_node {
  const Vertex *v;            // the neigbour
  unsigned int weight;        // weight of the edge between neighbours
  struct adj_list_node *next; // pointer to next node
};

AdjListNode *adj_node_init(Vertex *v, unsigned int weight) {

  AdjListNode *node = (AdjListNode *)malloc(sizeof(AdjListNode));

  if (node) {
    node->v = v;
    node->weight = weight;
    node->next = NULL;
  }

  return node;
}

AdjListNode *adj_node_get_next(AdjListNode *n) { return n ? n->next : NULL; }

unsigned int adj_node_get_weight(AdjListNode *n) { return n ? n->weight : __INT_MAX__; }

void adj_node_set_next(AdjListNode *n, AdjListNode *next) { n ? n->next = next : NULL; }
