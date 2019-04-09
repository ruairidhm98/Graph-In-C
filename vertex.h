#ifndef _VERTEX_H_
#define _VERTEX_H_

typedef struct vertex Vertex;
typedef struct adj_list AdjList;
typedef struct adj_list_node AdjListNode;

/* Returns a pointer to a vertex object if successfull, NULL otherwise */
Vertex *v_init(unsigned int index);
/* Returns the index of the vertex */
unsigned int v_get_index(Vertex *v);
/* Set the distance of the node */
void v_set_dist(Vertex *v, unsigned int dist);
/* Adds a neigbour to adjacency list */
void v_add_adj_list(Vertex *v, Vertex *n);
/* Destorys a verte object */
void v_destroy(Vertex *v);


#endif
