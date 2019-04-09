#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include "vertex.h"

typedef struct pqueue PriorityQueue;

/* Returns a pointer to an empty priority queue if successfull, NULL otherwise */
PriorityQueue *pq_init(unsigned int capacity, int (*cmp)(Vertex *v, Vertex *n));
/* Adds a new element to the queue */
void pq_add(PriorityQueue *pq, unsigned int item);
/* Removes the front of the queue */
unsigned int pq_poll(PriorityQueue *pq);
/* Decreases the priorty of an element and reorders */
void pq_decrease_priority(unsigned int index, unsigned int new_prio);
/* Destroys a priority queue object */
void pq_destroy(PriorityQueue *pq);


#endif
