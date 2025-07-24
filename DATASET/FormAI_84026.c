//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
  char *tag_name;
  char *value;
  struct Node *parent;
  struct Node *children;
  struct Node *next;
} Node;

Node* parse_xml(char* str);
void print_node(Node* node, int level);

int main() {
  // Example string to parse
  char* xml_str = "<html><head><title>My Title</title></head><body><p>Body text</p></body></html>";

  // Parse the XML string
  Node* root = parse_xml(xml_str);

  // Print the parse tree
  print_node(root, 0);

  return 0;
}

Node* parse_xml(char* str) {
  Node* root = NULL;
  Node* curr_node = NULL;
  char* token = strtok(str, "<>");
  while (token != NULL) {
    if (strncmp(token, "/", 1) == 0) {
      // End tag
      curr_node = curr_node->parent;
    } else if (strcmp(token, "") != 0) {
      // Start tag
      Node* new_node = (Node*) malloc(sizeof(Node));
      new_node->tag_name = strdup(token);
      new_node->value = NULL;
      new_node->parent = curr_node;
      new_node->children = NULL;
      new_node->next = NULL;
      if (curr_node == NULL) {
        // This is the root node
        root = new_node;
      } else {
        // Add node to parent's child list
        if (curr_node->children == NULL) {
          curr_node->children = new_node;
        } else {
          Node* child = curr_node->children;
          while (child->next != NULL) {
            child = child->next;
          }
          child->next = new_node;
        }
      }
      curr_node = new_node;
    } else {
      // Text node
      if (curr_node->value == NULL) {
        curr_node->value = strdup(token);
      } else {
        char* new_value = (char*) malloc(strlen(curr_node->value) + strlen(token) + 1);
        strcpy(new_value, curr_node->value);
        strcat(new_value, token);
        free(curr_node->value);
        curr_node->value = new_value;
      }
    }
    token = strtok(NULL, "<>");
  }
  return root;
}

void print_node(Node* node, int level) {
  if (node == NULL) {
    return;
  }
  for (int i = 0; i < level; i++) {
    printf("  ");
  }
  printf("[%s", node->tag_name);
  if (node->value != NULL) {
    printf(": %s", node->value);
  }
  printf("]\n");
  Node* child = node->children;
  while (child != NULL) {
    print_node(child, level + 1);
    child = child->next;
  }
}