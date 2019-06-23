#ifndef _VERTEX_H_
#define _VERTEX_H_

typedef struct vertex Vertex;
typedef struct adj_list AdjList;
typedef struct adj_list_node AdjListNode;


///////////////// VERTEX ///////////////////
/* Returns a pointer to a vertex object if successfull, NULL otherwise */
Vertex *v_init(unsigned int index);
/* Returns the index of the vertex */
unsigned int v_get_index(Vertex *v);
/* Returns the adjacenct list */
AdjList *v_get_adj_list(Vertex *v);
/* Set the distance of the node */
void v_set_dist(Vertex *v, unsigned int dist);
/* Adds a neigbour to adjacency list */
void v_add_adj_list(Vertex *v, Vertex *n, unsigned int weight);
/* Compares two vertices based on dist */
int v_cmp_dist(Vertex *v, Vertex *w);
/* Destorys a verte object */
void v_destroy(Vertex *v);

////////////////// Adjacency list node ////////////

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

////////////////// Adjacency list ////////////////

/* Returns a pointer to a adjacency list if successfull, NULL otherwise */
AdjList *adj_list_init();
/* Adds a new vertex to the adjacency list, returns 1/0 for success/failure */
int adj_list_add(AdjList *list, Vertex *v, unsigned int weight);
/* Prints the adjacency list */
void adj_list_print(AdjList *list);
/* Destorys an adjacency list */
void adj_list_destroy(AdjList *list);

#endif
