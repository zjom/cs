#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stack_create(size_t capacity) {
  Stack *stack = malloc(sizeof(Stack));
  stack->data = malloc(capacity * sizeof(int));
  stack->size = 0;
  stack->capacity = capacity;
  return stack;
}

void stack_push(Stack *stack, int value) {
  if (stack->size == stack->capacity) {
    fprintf(stderr, "Error: Stack overflow\n");
    exit(1);
  }
  stack->data[stack->size++] = value;
}

int stack_pop(Stack *stack) {
  if (stack->size == 0) {
    fprintf(stderr, "Error: Stack underflow\n");
    exit(1);
  }
  int value = stack->data[--stack->size];
  stack->data[stack->size] = 0;
  return value;
}

int stack_peek(Stack *stack) {
  if (stack->size == 0) {
    fprintf(stderr, "Error: Stack underflow\n");
    exit(1);
  }

  return stack->data[stack->size - 1];
}

int stack_is_empty(Stack *stack) { return stack->size == 0; }

void stack_destroy(Stack *stack) {
  free(stack->data);
  free(stack);
}

int main() {
  Stack *stack = stack_create(10);
  stack_push(stack, 1);
  stack_push(stack, 2);
  stack_push(stack, 3);
  stack_push(stack, 4);
  stack_push(stack, 5);
  while (!stack_is_empty(stack)) {
    printf("%d\n", stack_pop(stack));
  }
  stack_destroy(stack);
  return 0;
}
