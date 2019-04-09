#ifndef _ADJ_LIST_NODE_H_
#define _ADJ_LIST_NODE_H_

#include "vertex.h"

/* Returns a pointer to an adjacency list node if successfull, NULL otherwise */
AdjListNode *adj_node_init(Vertex *v, unsigned int weight);
/* Return the next node */
AdjListNode *adj_node_get_next(AdjListNode *n);
/* Returns the vertex at the node */
Vertex *adj_node_get_vertex(AdjListNode *n);
/* Returns the weight of the edge */
unsigned int adj_node_get_weight(AdjListNode *n);
/* Set the neighbour of the adjacency list node */
void adj_node_set_next(AdjListNode *n, AdjListNode *next);

#endif
