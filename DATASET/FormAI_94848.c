//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// node structure for building Huffman trees
typedef struct node {
  int value;
  char letter;
  struct node * left;
  struct node * right;
} node;

// Huffman tree structure
typedef struct tree {
  int size;
  node * root;
  node * nodes;
} tree;

// function to create a new Huffman tree node
node * new_node(int value, char letter) {
  node * n = (node *) malloc(sizeof(node));
  n->value = value;
  n->letter = letter;
  n->left = NULL;
  n->right = NULL;
  return n;
}

// function to create a new Huffman tree from a string of characters
tree * new_tree(char * input) {
  int i, j, length, size, unique_letters;
  node ** nodes;
  tree * t = (tree *) malloc(sizeof(tree));
  length = strlen(input);
  nodes = (node **) malloc(sizeof(node *) * length);
  for (i = 0; i < length; i++) {
    nodes[i] = new_node(1, input[i]);
  }
  size = length;
  while (size > 1) {
    unique_letters = 0;
    for (i = 0; i < size; i++) {
      if (nodes[i]->value > 0) {
        unique_letters++;
        for (j = i + 1; j < size; j++) {
          if (nodes[i]->value == nodes[j]->value && nodes[j]->value > 0) {
            nodes[i]->value++;
            nodes[j]->value = 0;
          }
        }
      }
    }
    if (unique_letters == 1) {
      break;
    }
    node ** new_nodes = (node **) malloc(sizeof(node *) * size - (unique_letters - 1));
    j = 0;
    for (i = 0; i < size; i++) {
      if (nodes[i]->value > 0) {
        new_nodes[j] = nodes[i];
        j++;
      }
    }
    size = j;
    for (i = 0; i < size; i++) {
      if (i == size - 1) {
        new_nodes[i]->right = new_nodes[0];
      } else {
        new_nodes[i]->right = new_nodes[i + 1];
      }
      new_nodes[i]->left = new_nodes[(i * 2) % (size - 1)]; 
      new_nodes[i]->value = new_nodes[i]->left->value + new_nodes[i]->right->value;
    }
    nodes = new_nodes;
  }
  t->size = size;
  t->root = nodes[0];
  t->nodes = nodes;
  return t;
}

// function to print the Huffman codes for each character in a given tree
void print_codes(node * n, char * code, int index) {
  if (n->letter != '\0') {
    code[index] = '\0';
    printf("%c: %s\n", n->letter, code);
  } else {
    code[index] = '0';
    print_codes(n->left, code, index + 1);
    code[index] = '1';
    print_codes(n->right, code, index + 1);
  }
}

// main function
int main() {
  char * input = "this is a test string";
  tree * t = new_tree(input);
  char * code = (char *) malloc(sizeof(char) * t->size);
  print_codes(t->root, code, 0);
  free(t->nodes);
  free(t);
  free(code);
  return 0;
}