#include <stdio.h>
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

// Create a new node
node *linked_list_node_new(int val) {
  node *n = malloc(sizeof(node));
  if (n == NULL) {
    return NULL;
  }
  n->value = val;
  n->next = NULL;
  return n;
}

// Create a new linked list
linkedList *linked_list_new() {
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
void linked_list_free(linkedList *ll) {
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
node *linked_list_append(linkedList *ll, int val) {
  if (ll == NULL) {
    return NULL;
  }
  node *n = linked_list_node_new(val);
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
void linked_list_print(linkedList *ll) {
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
int linked_list_contains(linkedList *ll, int val) {
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
node *linked_list_find(linkedList *ll, int val) {
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
int linked_list_remove(linkedList *ll, int val) {
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

void linked_list_sort(linkedList *ll) {
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
  linkedList *ll = linked_list_new();
  linked_list_append(ll, 5);
  linked_list_append(ll, 3);
  linked_list_append(ll, 8);
  linked_list_append(ll, 1);
  linked_list_append(ll, 2);
  linked_list_append(ll, 4);
  linked_list_append(ll, 7);
  linked_list_append(ll, 6);
  linked_list_append(ll, 9);
  linked_list_append(ll, 10);
  assert(ll->length == 10, "expected length to be 10");
  linked_list_print(ll);
  linked_list_sort(ll);
  assert(ll->head->value == 1, "expected head to be 1");
  assert(ll->tail->value == 10, "expected tail to be 10");
  linked_list_print(ll);
  linked_list_remove(ll, 5);
  assert(!linked_list_contains(ll, 5), "expected 5 to be removed");
  linked_list_print(ll);
  linked_list_free(ll);
  return 0;
}
