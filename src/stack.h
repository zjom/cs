#ifndef STACK_H
#define STACK_H
#include <stdlib.h>

typedef struct {
  int *data;
  int size;
  int capacity;
} Stack;

Stack *stack_create(int capacity);

void stack_push(Stack *stack, int value);

int stack_pop(Stack *stack);

int stack_peek(Stack *stack);

int stack_is_empty(Stack *stack);

void stack_destroy(Stack *stack);

#endif
