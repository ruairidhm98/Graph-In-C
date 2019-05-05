#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

/* Moves nodes in case of insertion */
static void pqify_up(PriorityQueue *pq);
/* Moves nodes in case of deletion */
static void pqify_down(PriorityQueue *pq);
/* Helper function */
static unsigned int get_left_child_index(int i);
/* Helper function */
static unsigned int get_right_child_index(int i);
/* Helper function */
static unsigned int get_parent_index(int i);
/* Helper function */
static unsigned int has_left_child(PriorityQueue *pq, int i);
/* Helper function */
static unsigned int has_right_child(PriorityQueue *pq, int i);
/* Helper function */
static unsigned int has_parent(int i);
/* Helper function */
static int get_parent(PriorityQueue *pq, int);
/* Helper function */
static int get_left_child(PriorityQueue *pq, int);
/* Helper function */
static int get_right_child(PriorityQueue *pq, int);
/* Helper function */
static void swap(int *ele, int i, int j);
/* Helper function */
static int pq_realloc(PriorityQueue *pq);

/* Priority queue implemented with a min pq */
struct pqueue {
  int *queue;                       // the queue
  unsigned int size;                // size counter
  unsigned int capacity;            // capacity of heap
};


PriorityQueue *pq_init(unsigned int capacity) { 

  PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
  if (pq) {
    pq->queue = (int *)malloc(sizeof(int)*capacity);
    if (pq->queue) {
      pq->size = 0;
      pq->capacity = capacity;
      return pq;
    }
  }

  return NULL;
}


void pq_add(PriorityQueue *pq, unsigned int item) {

  if (pq) {
    if (pq->size == pq->capacity)
      if (!pq_realloc(pq))
        return;  
    pq->queue[pq->size++] = item;
    pqify_up(pq);
  }

}


unsigned int pq_poll(PriorityQueue *pq) {
  
  unsigned int root = pq->queue[0];
  pq->queue[0] = pq->queue[--pq->size];
  pqify_down(pq);

  return root;
}

/*
void pq_decrease(unsigned int index, unsigned int new_prio) {

}*/

void pq_print(PriorityQueue *pq) {
  if (pq) {
    printf("[ ");
    for (unsigned int i = 0; i < pq->size; i++) {
      printf("%d ", pq->queue[i]);
    }
    printf("]\n");
  }
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
      smaller_child_index = get_right_child_index(index);

    /* Correct place has been found */
    if (pq->queue[index] <= pq->queue[smaller_child_index])
      break;
    else
      swap(pq->queue, index, smaller_child_index);

    index = smaller_child_index;
  }
}


/* Helper function, gets index of left child */
static unsigned int get_left_child_index(int parent_index) {
  return 2 * parent_index + 1;
}

/* Helper function, gets index of right child */
static unsigned int get_right_child_index(int parent_index) {
  return 2 * parent_index + 2;
}

/* Helper function, gets index of parent node */
static unsigned int get_parent_index(int child_index) { return (child_index - 1) / 2; }

/* Helper function, checks if parent node has a left child */
static unsigned int has_left_child(PriorityQueue *pq, int index) {
  return get_left_child_index(index) < pq->size;
}

/* Helper function, checks if parent node has a right child */
static unsigned int has_right_child(PriorityQueue *pq, int index) {
  return get_right_child_index(index) < pq->size;
}

/* Helper function, checks if a given node has a parent */
static unsigned int has_parent(int index) { return get_parent_index(index) >= 0; }

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

  int temp = ele[i];
  ele[i] = ele[j];
  ele[j] = temp;

}

/* Helper function, reallocates memory for heap if it becomes full */
static int pq_realloc(PriorityQueue *pq) {
  if (pq) {
    pq->capacity = 2 * pq->capacity;
    pq->queue = (int *)realloc(pq->queue, pq->capacity);
    if (pq->queue)
      return 1;
  }
  return 0;
}

int main() {

  PriorityQueue *pq = pq_init(10);

  for (int i = 0; i < 11; i++) {
    pq_add(pq, rand() % 100);
  }
  pq_print(pq);
  while (pq->size) {
    printf("%d ", pq_poll(pq));
  }
  printf("\n");


  return 0;
}