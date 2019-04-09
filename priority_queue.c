#include "priority_queue.h"
#include <stdio.h>
#include <stdlib.h>

/* Priority queue implemented with a min heap */
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
