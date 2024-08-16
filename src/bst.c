#include <stdlib.h>

typedef struct Node {
  int val;
  struct Node *left;
  struct Node *right;
} Node;

Node *tree_new(int val) {
  Node *n = malloc(sizeof(Node));
  if (n == NULL) {
    return NULL;
  }

  n->val = val;
  n->right = NULL;
  n->left = NULL;

  return n;
}

void tree_destroy(Node *node) {
  if (node == NULL) {
    return;
  }

  if (node->left != NULL) {
    tree_destroy(node->left);
  }

  if (node->right != NULL) {
    tree_destroy(node->right);
  }

  free(node);
}

void tree_insert(int val) {}
