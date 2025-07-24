//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 50
#define MAX_ATTR_LEN 50
#define MAX_ATTR_NUM 10
#define MAX_VALUE_LEN 100

// Struct to store attributes
typedef struct {
  char name[MAX_ATTR_LEN];
  char value[MAX_VALUE_LEN];
} Attribute;

// Struct to store non-leaf nodes
typedef struct node {
  char tag[MAX_TAG_LEN];
  Attribute attrs[MAX_ATTR_NUM];
  int num_attrs;
  struct node* children;
} Node;

// Function to create a new node
Node* new_node(char tag[MAX_TAG_LEN]) {
  Node* node = (Node*) malloc(sizeof(Node));
  strcpy(node->tag, tag);
  node->num_attrs = 0;
  node->children = NULL;
  return node;
}

// Function to add attribute to a node
void add_attr(Node* node, char name[MAX_ATTR_LEN], char value[MAX_VALUE_LEN]) {
  Attribute attr;
  strcpy(attr.name, name);
  strcpy(attr.value, value);
  node->attrs[node->num_attrs++] = attr;
}

// Function to add child to a node
void add_child(Node* node, Node* child) {
  Node* children = node->children;
  if (children == NULL) {
    node->children = child;
    return;
  }
  while (children->children != NULL) {
    children = children->children;
  }
  children->children = child;
}

// Function to parse XML string and create a tree of nodes
Node* parse_xml(char* xml) {
  Node* root = NULL;
  Node* current = NULL;

  char* token = strtok(xml, "<>");
  while (token != NULL) {
    if (token[0] == '/') {
      current = current->children; // Go back up one level
    } else if (token[0] == '?') {
    } else if (token[0] == '!') {
    } else if (token[0] == ' ') {
      char name[MAX_ATTR_LEN], value[MAX_VALUE_LEN];
      sscanf(token, " %[^=]=\"%[^\"]\"", name, value);
      add_attr(current, name, value);
    } else {
      Node* node = new_node(token);
      if (root == NULL) {
        root = node;
        current = node;
      } else {
        add_child(current, node);
        current = node;
      }
    }

    token = strtok(NULL, "<>");
  }

  return root;
}

int main() {
  char xml[] = "<books><book type=\"fiction\" year=\"2001\"><title>Battlefield Earth</title><author>L. Ron Hubbard</author></book><book type=\"non-fiction\"><title>Crime and Punishment</title><author>Fyodor Dostoevsky</author></book></books>";
  Node* root = parse_xml(xml);

  // Traverse the tree and print node values
  Node* current = root;
  while (current != NULL) {
    printf("<%s", current->tag);
    for (int i = 0; i < current->num_attrs; i++) {
      printf(" %s=\"%s\"", current->attrs[i].name, current->attrs[i].value);
    }
    printf(">");

    if (current->children != NULL) {
      current = current->children;
    } else {
      printf("</%s>", current->tag);
      if (current->children == NULL && current->children != root) {
        current = current->children;
      }
    }
  }

  return 0;
}