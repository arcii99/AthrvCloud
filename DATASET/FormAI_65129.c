//FormAI DATASET v1.0 Category: Syntax parsing ; Style: curious
#include <stdio.h>

// This program parses a C syntax tree and prints out the structure in a curious style.

typedef struct Node {
  char type[10];
  struct Node* children[10];
  int num_children;
} Node;

void print_indent(int indent) {
  for (int i = 0; i < indent; i++) {
    printf("  ");
  }
}

void print_node(Node* node, int indent) {
  print_indent(indent);
  printf("<%s>\n", node->type);

  for (int i = 0; i < node->num_children; i++) {
    print_node(node->children[i], indent + 1);
  }

  print_indent(indent);
  printf("</%s>\n", node->type);
}

int main() {
  // Build the syntax tree from some imaginary C code
  Node* root = (Node*) malloc(sizeof(Node));
  strcpy(root->type, "Program");

  Node* functions = (Node*) malloc(sizeof(Node));
  strcpy(functions->type, "Functions");
  root->children[0] = functions;
  root->num_children++;

  Node* main_func = (Node*) malloc(sizeof(Node));
  strcpy(main_func->type, "Function");
  functions->children[0] = main_func;
  functions->num_children++;

  Node* block = (Node*) malloc(sizeof(Node));
  strcpy(block->type, "Block");
  main_func->children[0] = block;
  main_func->num_children++;

  Node* print_statement = (Node*) malloc(sizeof(Node));
  strcpy(print_statement->type, "Print Statement");
  block->children[0] = print_statement;
  block->num_children++;

  Node* string_literal = (Node*) malloc(sizeof(Node));
  strcpy(string_literal->type, "String Literal");
  print_statement->children[0] = string_literal;
  print_statement->num_children++;

  // Print out the syntax tree in a curious style
  printf("Welcome! Today, we will be exploring the mysterious C syntax tree.\n\n");
  printf("Behold, in all its glory:\n\n");

  print_node(root, 0);

  printf("\nAmazing, isn't it?\n\n");
  printf("I hope you enjoyed this tour of the C syntax tree. Until next time!\n");

  return 0;
}