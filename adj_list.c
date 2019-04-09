#include "adj_list.h"
#include "adj_list_node.h"
#include <stdio.h>
#include <stdlib.h>

/* Adjacency list represented as a singly linked list */
struct adj_list {
  AdjListNode *head; // pointer to the head of the list
  AdjListNode *tail; // pointer to the tail of the list
  unsigned int size; // size counter
};

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
