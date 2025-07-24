//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
    int id;
    char *name;
    int status;
} Node;

typedef struct {
    Node nodes[MAX_NODES];
    int size;
} NodeList;

void initialize(NodeList *list) {
    list->size = 0;
}

void addNode(NodeList *list, Node node) {
    if (list->size < MAX_NODES) {
        list->nodes[list->size++] = node;
    }
}

void printNode(Node node) {
    printf("ID: %d, Name: %s, Status: %d\n", node.id, node.name, node.status);
}

void printList(NodeList list) {
    for (int i = 0; i < list.size; i++) {
        printNode(list.nodes[i]);
    }
}

int main() {
    NodeList nodeList;
    initialize(&nodeList);
    Node node1 = {1, "Neo", 1};
    Node node2 = {2, "Trinity", 1};
    Node node3 = {3, "Morpheus", 0};
    addNode(&nodeList, node1);
    addNode(&nodeList, node2);
    addNode(&nodeList, node3);
    printf("Before Update:\n");
    printList(nodeList);
    printf("\n\n");
    node1.status = 0;
    node2.status = 0;
    node3.status = 1;
    printf("After Update:\n");
    printList(nodeList);

    return 0;
}