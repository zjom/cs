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
node *newNode(int val);
linkedList *newLinkedList();
void freeLL(linkedList *ll);
node *append(linkedList *ll, int val);
void printLL(linkedList *ll);
int contains(linkedList *ll, int val);
node *find(linkedList *ll, int val);
int removeNode(linkedList *ll, int val);
void sort(linkedList *ll);
#endif
