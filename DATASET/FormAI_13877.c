//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

bool visited[SIZE];
int distance[SIZE];
int parent[SIZE];

typedef struct node {
    int val;
    int weight;
    struct node* next;
} Node;

Node* adj_list[SIZE];

void add_edge(int src, int dest, int weight) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = dest;
    newNode->weight = weight;
    newNode->next = adj_list[src];
    adj_list[src] = newNode;
}

int min_distance() {
    int min = __INT_MAX__, min_index;
  
    for (int v = 0; v < SIZE; v++)
        if (visited[v] == false && distance[v] <= min) {
            min = distance[v];
            min_index = v;
        }
    return min_index;
}

void dijkstra(int start) {
    for (int i = 0; i < SIZE; i++) {
        visited[i] = false;
        distance[i] = __INT_MAX__;
    }
  
    distance[start] = 0;
  
    for (int count = 0; count < SIZE - 1; count++) {
        int u = min_distance();
        visited[u] = true;
  
        Node* ptr = adj_list[u];
  
        while (ptr != NULL) {
            int v = ptr->val;
            int weight = ptr->weight;
  
            if (!visited[v] && distance[u] != __INT_MAX__ && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
            ptr = ptr->next;
        }
    }
}

void printPath(int j) {
    if (parent[j] == - 1) {
        printf("%d ", j);
        return;
    }
  
    printPath(parent[j]);
  
    printf("%d ", j);
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        visited[i] = false;
        distance[i] = __INT_MAX__;
        parent[i] = -1;
    }

    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 2, 8);
    add_edge(1, 7, 11);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(2, 5, 4);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);

    dijkstra(0);
  
    printf("Vertex\t Distance\tPath");
    for (int i = 1; i < SIZE; i++) {
        printf("\n%d -> %d \t\t %d\t\t%d ", 0, i, distance[i], 0);
        printPath(i);
    }

    return 0;
}