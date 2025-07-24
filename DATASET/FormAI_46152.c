//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node* next;
} Node;

void connect(Node* n1, Node* n2) {
  n1->next = n2;
}

int main() {
  int num_nodes;
  printf("Enter number of nodes: ");
  scanf("%d", &num_nodes);

  Node* nodes = (Node*) malloc(sizeof(Node) * num_nodes);

  int i;
  for(i=0; i<num_nodes; i++) {
    printf("Enter value for node %d: ", i+1);
    scanf("%d", &(nodes[i].value));
    nodes[i].next = NULL;
  }

  for(i=0; i<num_nodes-1; i++) {
    connect(&nodes[i], &nodes[i+1]);
  }

  printf("Nodes connected!\n");

  free(nodes);

  return 0;
}