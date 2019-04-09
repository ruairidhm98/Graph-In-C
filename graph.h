#ifndef _GRAPH_H_
#define _GRAPH_H_

typedef struct graph Graph;

/* Returns a pointer to a new graph object if successfull, NULL otherwise */
Graph *graph_init(unsigned int matrix[6][6], unsigned int size);
/* Prints the graph object */
void graph_print(Graph *g);
/* Destroys the graph */
void graph_destroy(Graph *g);

#endif
