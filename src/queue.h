#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>

typedef struct {
  int *data;
  int front;
  int rear;
  size_t size;
  size_t capacity;
} Queue;

Queue *queue_create(size_t capacity);

void queue_enqueue(Queue *queue, int value);

int queue_dequeue(Queue *queue);

int queue_peek(Queue *queue);

int queue_is_empty(Queue *queue);

void queue_destroy(Queue *queue);

#endif
