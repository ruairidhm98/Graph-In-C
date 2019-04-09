#ifndef _ADJ_LIST_H_
#define _ADJ_LIST_H_

#include "vertex.h"

/* Returns a pointer to a adjacency list if successfull, NULL otherwise */
AdjList *adj_list_init();
/* Adds a new vertex to the adjacency list, returns 1/0 for success/failure */
int adj_list_add(AdjList *list, Vertex *v, unsigned int weight);
/* Prints the adjacency list */
void adj_list_print(AdjList *list);
/* Destorys an adjacency list */
void adj_list_destroy(AdjList *list);

#endif
