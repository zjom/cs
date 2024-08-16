#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} Vector;

Vector *vector_create(size_t capacity) {
  Vector *vector = malloc(sizeof(Vector));
  if (vector == NULL || capacity == 0) {
    return NULL;
  }
  vector->capacity = capacity;
  vector->data = malloc(capacity * sizeof(int));
  vector->size = 0;
  return vector;
}

void vector_destroy(Vector *vector) {
  if (vector == NULL) {
    return;
  }
  free(vector->data);
  free(vector);
}

void resize(Vector *vector) {
  if (vector == NULL) {
    return;
  }

  // keep pointer to old data
  int *data = vector->data;

  // allocate larger memory
  vector->data = malloc(vector->capacity * 2);

  // copy old data to new
  for (size_t i = 0; i < vector->size; i++) {
    vector->data[i] = data[i];
    // clear old data
    data[i] = 0;
  }

  return;
}

void vector_push_back(Vector *vector, int val) {
  if (vector == NULL) {
    return;
  }

  if (vector->size == vector->capacity) {
    resize(vector);
  }

  vector->data[++vector->size - 1] = val;

  return;
}

void vector_pop_back(Vector *vector) {
  if (vector == NULL) {
    return;
  }

  vector->data[--vector->size] = 0;
}

void vector_print(Vector *vector) {
  if (vector == NULL) {
    printf("[NULL]");
  }

  printf("[");
  for (size_t i = 0; i < vector->size; i++) {
    if (i == vector->size - 1) {
      printf("%d", vector->data[i]);
      break;
    }
    printf("%d ", vector->data[i]);
  }
  printf("]\n");
}

int main() {
  Vector *vec = vector_create(3);
  vector_print(vec);
  vector_push_back(vec, 0);
  vector_print(vec);
  vector_push_back(vec, 1);
  vector_print(vec);
  vector_push_back(vec, 2);
  vector_print(vec);
  vector_push_back(vec, 3);
  vector_print(vec);
  vector_push_back(vec, 4);
  vector_print(vec);
  vector_push_back(vec, 5);
  vector_print(vec);

  vector_pop_back(vec);
  vector_print(vec);
  vector_pop_back(vec);
  vector_print(vec);
}
