#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h>

// Node structure
typedef struct node {
  int value;
  struct node *next;
} node;

// Linked list structure
typedef struct {
  node *head;
  node *tail;
  size_t length;
} linkedList;

// function prototypes
linkedList *linked_list_new();
void linked_list_free(linkedList *ll);
node *linked_list_append(linkedList *ll, int val);
void linked_list_print(linkedList *ll);
int linked_list_contains(linkedList *ll, int val);
node *linked_list_find(linkedList *ll, int val);
int linked_list_remove(linkedList *ll, int val);
void linked_list_sort(linkedList *ll);
#endif
