#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  int front;
  int rear;
  size_t size;
  size_t capacity;
} Queue;

Queue *queue_create(size_t capacity) {
  Queue *queue = malloc(sizeof(Queue));
  queue->data = malloc(sizeof(int) * capacity);
  queue->front = 0;
  queue->rear = 0;
  queue->size = 0;
  queue->capacity = capacity;
  return queue;
}

void queue_enqueue(Queue *queue, int value) {
  if (queue->size == queue->capacity) {
    fprintf(stderr, "Error: Queue overflow\n");
    exit(1);
  }

  queue->data[queue->rear] = value;
  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->size++;

  return;
}

int queue_dequeue(Queue *queue) {
  if (queue->size == 0) {
    fprintf(stderr, "Error: Queue underflow\n");
    exit(1);
  }

  int value = queue->data[queue->front];
  queue->data[queue->front] = 0;
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size--;

  return value;
}

int queue_peek(Queue *queue) {
  if (queue->size == 0) {
    fprintf(stderr, "Error: Queue underflow\n");
    exit(1);
  }

  return queue->data[queue->front];
}

int queue_is_empty(Queue *queue) { return queue->size == 0; }

void queue_destroy(Queue *queue) {
  free(queue->data);
  free(queue);
}

int main() {
  Queue *queue = queue_create(5);

  queue_enqueue(queue, 1);
  queue_enqueue(queue, 2);
  queue_enqueue(queue, 3);
  queue_enqueue(queue, 4);
  queue_enqueue(queue, 5);

  while (!queue_is_empty(queue)) {
    printf("%d\n", queue_dequeue(queue));
  }

  queue_destroy(queue);

  return 0;
}
