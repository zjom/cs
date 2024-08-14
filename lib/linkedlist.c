#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new node
node *newNode(int val) {
  node *n = malloc(sizeof(node));
  if (n == NULL) {
    return NULL;
  }
  n->value = val;
  n->next = NULL;
  return n;
}

// Create a new linked list
linkedList *newLinkedList() {
  linkedList *ll = malloc(sizeof(linkedList));
  if (ll == NULL) {
    return NULL;
  }
  ll->head = NULL;
  ll->tail = NULL;
  ll->length = 0;
  return ll;
}

// Free the linked list
void freeLL(linkedList *ll) {
  if (ll == NULL) {
    return;
  }
  node *current = ll->head;
  node *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  free(ll);
}

// Append a new node to the linked list
node *append(linkedList *ll, int val) {
  if (ll == NULL) {
    return NULL;
  }
  node *n = newNode(val);
  if (n == NULL) {
    return NULL;
  }
  if (ll->head == NULL) {
    ll->head = n;
    ll->tail = n;
  } else {
    ll->tail->next = n;
    ll->tail = n;
  }
  ll->length++;
  return n;
}

// Print the linked list
void printLL(linkedList *ll) {
  if (ll == NULL) {
    return;
  }
  node *n = ll->head;
  while (n != NULL) {
    printf("%d ", n->value);
    n = n->next;
  }
  printf("\n");
}

// Check if the linked list contains a value
int contains(linkedList *ll, int val) {
  if (ll == NULL) {
    return 0;
  }
  node *n = ll->head;
  while (n != NULL) {
    if (n->value == val) {
      return 1;
    }
    n = n->next;
  }
  return 0;
}

// Find a node with a specific value
node *find(linkedList *ll, int val) {
  if (ll == NULL) {
    return NULL;
  }
  node *n = ll->head;
  while (n != NULL) {
    if (n->value == val) {
      return n;
    }
    n = n->next;
  }
  return NULL;
}

// Remove a node from the linked list
int removeNode(linkedList *ll, int val) {
  if (ll == NULL) {
    return 0;
  }

  node *current = ll->head;
  node *prev = NULL;

  while (current != NULL) {
    if (current->value == val) {
      if (prev == NULL) {
        ll->head = current->next;
      } else {
        prev->next = current->next;
      }
      if (current->next == NULL) {
        ll->tail = prev;
      }
      free(current);
      ll->length--;
      return 1;
    }
    prev = current;
    current = current->next;
  }

  return 0;
}

void sort(linkedList *ll) {
  if (ll == NULL) {
    return;
  }

  node *current = ll->head;
  node *index = NULL;
  int temp;

  if (ll->head == NULL) {
    return;
  } else {
    while (current != NULL) {
      index = current->next;

      while (index != NULL) {
        if (current->value > index->value) {
          temp = current->value;
          current->value = index->value;
          index->value = temp;
        }
        index = index->next;
      }
      current = current->next;
    }
  }
}

void assert(int condition, char *message) {
  if (!condition) {
    printf("Assertion failed: %s\n", message);
    exit(1);
  }
}

int main() {
  linkedList *ll = newLinkedList();
  append(ll, 5);
  append(ll, 3);
  append(ll, 8);
  append(ll, 1);
  append(ll, 2);
  append(ll, 4);
  append(ll, 7);
  append(ll, 6);
  append(ll, 9);
  append(ll, 10);
  assert(ll->length == 10, "expected length to be 10");
  printLL(ll);
  sort(ll);
  assert(ll->head->value == 1, "expected head to be 1");
  assert(ll->tail->value == 10, "expected tail to be 10");
  printLL(ll);
  removeNode(ll, 5);
  assert(!contains(ll, 5), "expected 5 to be removed");
  printLL(ll);
  freeLL(ll);
  return 0;
}
