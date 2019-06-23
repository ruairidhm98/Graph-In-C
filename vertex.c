#include "vertex.h"
#include <stdlib.h>
#include <stdio.h>

/* Vertex in the graph */
struct vertex {
  unsigned int dist;  // used in shortest path algorithms
  unsigned int index; // index into the graph array
  AdjList *adj_list;  // neighbours of the vertex
};

/* Node in adjacency list */
struct adj_list_node {
  Vertex *v;                  // the neigbour
  unsigned int weight;        // weight of the edge between neighbours
  struct adj_list_node *next; // pointer to next node
};

/* Adjacency list represented as a singly linked list */
struct adj_list {
  AdjListNode *head; // pointer to the head of the list
  AdjListNode *tail; // pointer to the tail of the list
  unsigned int size; // size counter
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

Vertex *adj_node_get_vertex(AdjListNode *n) { return n ? n->v : NULL; }

unsigned int adj_node_get_weight(AdjListNode *n) { return n ? n->weight : __INT_MAX__; }

void adj_node_set_next(AdjListNode *n, AdjListNode *next) { n ? n->next = next : NULL; }

AdjList *adj_list_init() {

  AdjList *list = (AdjList *)malloc(sizeof(AdjList));

  if (list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
  }

  return list;
}

int adj_list_add(AdjList *list, Vertex *v, unsigned int weight) {

  if (list) {
    AdjListNode *adj_node = adj_node_init(v, weight);
    if (adj_node) {
      if (!list->head) {
        list->head = adj_node;
        list->tail = list->head;
      }
      else {
        adj_node_set_next(list->tail, adj_node);
        list->tail = adj_node;
      }
      list->size++;
      return 1;
    }
  }

  return 0;
}

void adj_list_print(AdjList *list) {
  
  AdjListNode *cursor = list->head;

  while (cursor) {
    printf("%d ", v_get_index(adj_node_get_vertex(cursor)));
    cursor = adj_node_get_next(cursor);
  }
  printf("\n");

}

void adj_list_destroy(AdjList *list) {
  
  AdjListNode *cursor = list->head, *temp;
  
  while (cursor) {
    temp = cursor;
    cursor = adj_node_get_next(cursor);
    free(temp);
  }
  free(list);

}
