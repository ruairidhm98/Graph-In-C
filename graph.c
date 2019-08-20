#include "graph.h"
#include "vertex.h"
#include <stdio.h>
#include <stdlib.h>

/* Helper function, prints the shortest path */
static void print_path(int *pred, int curr);

/* Graph represented as an array of pointers, where each pointer
   is a pointer to a vertex object */
struct graph
{
  Vertex **graph;    // the graph
  unsigned int size; // number of vertices
};

Graph *graph_init(unsigned int **matrix, unsigned int size)
{

  Graph *g = (Graph *)malloc(sizeof(Graph));
  unsigned int i, j, weight;
  AdjList *adj_list;

  if (g)
  {
    g->graph = (Vertex **)malloc(sizeof(Vertex *)*size);
    if (g->graph)
    {
      g->size = size;
      // initialise each vertex
      for (i = 0; i < size; i++) g->graph[i] = v_init(i);
      // set up the adjacency lists
      for (i = 0; i < size; i++)
      {
        adj_list = v_get_adj_list(g->graph[i]);            
        for (j = 0; j < size; j++)
        {
          if (matrix[i][j])
          {
            weight = matrix[i][j];
            adj_list_add(adj_list, g->graph[j], weight);
          }
        }
      }
      return g;
    }
  }

  return NULL;
}

void graph_print(Graph *g)
{

  for (unsigned int i = 0; i < g->size; i++)
  {
    printf("----------\n");
    printf("Vertex %d\n", v_get_index(g->graph[i]));
    adj_list_print(v_get_adj_list(g->graph[i]));
    printf("----------\n");
  }

}
/*
unsigned int dijktras(Graph *g, unsigned int start, unsigned int dest) {
  return 0;
}*/

void graph_destroy(Graph *g)
{

  AdjList *adj_list;
  for (unsigned int i = 0; i < g->size; i++)
  {
    adj_list = v_get_adj_list(g->graph[i]);
    adj_list_destroy(adj_list);
  }
  free(g->graph);
  free(g);

  return 0;
}
