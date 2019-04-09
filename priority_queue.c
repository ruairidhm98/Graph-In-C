#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

/* Moves nodes in case of insertion */
static void pqify_up(PriorityQueue *pq);
/* Moves nodes in case of deletion */
static void pqify_down(PriorityQueue *pq);
/* Helper function */
static int get_left_child_index(int);
/* Helper function */
static int get_right_child_index(int);
/* Helper function */
static int get_parent_index(int);
/* Helper function */
static int has_left_child(PriorityQueue *, int);
/* Helper function */
static int has_right_child(PriorityQueue *, int);
/* Helper function */
static int has_parent(int);
/* Helper function */
static int get_parent(PriorityQueue *, int);
/* Helper function */
static int get_left_child(PriorityQueue *, int);
/* Helper function */
static int get_right_child(PriorityQueue *, int);
/* Helper function */
static void swap(int *ele, int i, int j);

/* Priority queue implemented with a min pq */
struct pqueue {
  int *queue;                       // the queue
  unsigned int size;                // size counter
  unsigned int capacity;            // capacity of the queue
  int (*cmp)(Vertex *v, Vertex *n); // comparison function used to order the queue
};


PriorityQueue *pq_init(unsigned int capacity, int (*cmp)(Vertex *v, Vertex *n)) { 

  PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
  if (pq) {
    pq->queue = (int *)malloc(sizeof(int)*capacity);
    if (pq->queue) {
      pq->size = 0;
      pq->capacity = capacity;
      pq->cmp = cmp;
      return pq;
    }
  }

  return NULL;
}


void pq_add(PriorityQueue *pq, unsigned int item) {



}


unsigned int pq_poll(PriorityQueue *pq) {

}


void pq_decrease(unsigned int index, unsigned int new_prio) {

}

void pq_destroy(PriorityQueue *pq) {
  free(pq->queue);
  free(pq);
}




/* Bubbles elements up */
static void pqify_up(PriorityQueue *pq) {

  int index;

  index = pq->size - 1;
  /* Loop until correct position has been found */
  while (has_parent(index) && get_parent(pq, index) > pq->queue[index]) {
    /* Swaps with parent node if parent is greater than node being bubbled */
    swap(pq->queue, get_parent_index(index), index);
    index = get_parent_index(index);
  }
}

/* Bubbles elements down */
static void pqify_down(PriorityQueue *pq) {

  int index, smaller_child_index;

  index = 0;
  /* Loop until node is in correct place */
  while (has_left_child(pq, index)) {

    smaller_child_index = get_left_child_index(index);
    /* The right child is smaller */
    if (has_right_child(pq, index) &&
        get_right_child(pq, index) < get_left_child(pq, index))
      smaller_child_index = get_right_child(pq, index);

    /* Correct place has been found */
    if (pq->queue[index] < pq->queue[smaller_child_index])
      break;
    else
      swap(pq->queue, index, smaller_child_index);

    index = smaller_child_index;
  }
}


/* Helper function, gets index of left child */
static int get_left_child_index(int parent_index) {
  return 2 * parent_index + 1;
}

/* Helper function, gets index of right child */
static int get_right_child_index(int parent_index) {
  return 2 * parent_index + 2;
}

/* Helper function, gets index of parent node */
static int get_parent_index(int child_index) { return (child_index - 1) / 2; }

/* Helper function, checks if parent node has a left child */
static int has_left_child(PriorityQueue *pq, int index) {
  return get_left_child_index(index) < pq->size;
}

/* Helper function, checks if parent node has a right child */
static int has_right_child(PriorityQueue *pq, int index) {
  return get_right_child_index(index) < pq->size;
}

/* Helper function, checks if a given node has a parent */
static int has_parent(int index) { return get_parent_index(index) >= 0; }

/* Helper function, gets the left child of a parent node */
static int get_left_child(PriorityQueue *pq, int index) {
  return pq->queue[get_left_child_index(index)];
}

/* Helper function, gets the right child of a parent node */
static int get_right_child(PriorityQueue *pq, int index) {
  return pq->queue[get_right_child_index(index)];
}

/* Helper function, gets the parent of a given node */
static int get_parent(PriorityQueue *pq, int index) {
  return pq->queue[get_parent_index(index)];
}

/* Helper function, swaps two elements */
static void swap(int *ele, int i, int j) {

  int temp;

  temp = ele[i];
  ele[i] = ele[j];
  ele[j] = temp;
}
