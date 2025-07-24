//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char* name;
    struct node* next;
    struct node* adj_list; // adjacent nodes
} Node;

Node* create_node(char* name) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->name = (char*) malloc(strlen(name)*sizeof(char));
    strcpy(new_node->name, name);
    new_node->adj_list = NULL;
    new_node->next = NULL;
    return new_node;
}

Node* search_node(Node* head, char* name) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_edge(Node* from, Node* to) {
    Node* current = from->adj_list;
    while (current != NULL) {
        if (current == to) {
            return;
        }
        current = current->next;
    }
    Node* new_edge = (Node*) malloc(sizeof(Node));
    new_edge->name = to->name;
    new_edge->adj_list = NULL;
    new_edge->next = from->adj_list;
    from->adj_list = new_edge;
}

void print_adj_list(Node* node) {
    Node* current = node->adj_list;
    printf("Adjacent nodes for %s:\n", node->name);
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}

void print_graph(Node* head) {
    Node* current_head = head;
    while (current_head != NULL) {
        printf("Node: %s\n", current_head->name);
        print_adj_list(current_head);
        current_head = current_head->next;
    }
}

int main() {
    Node* node1 = create_node("Node 1");
    Node* node2 = create_node("Node 2");
    Node* node3 = create_node("Node 3");
    Node* node4 = create_node("Node 4");

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    add_edge(node1, node2);
    add_edge(node1, node3);
    add_edge(node2, node3);
    add_edge(node3, node4);

    print_graph(node1);
    return 0;
}