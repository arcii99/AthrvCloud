//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100

int vertexColors[MAX_VERTICES];

typedef struct adjacency_list_node {
    int vertex;
    struct adjacency_list_node* next;
} adjacency_list_node;

typedef struct adjacency_list {
    int num_neighbors;
    adjacency_list_node* head;
} adjacency_list;

void init_colors() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        vertexColors[i] = -1;
    }
}

int get_random_color(int k) {
    int randColor = rand() % k;
    return randColor;
}

int is_valid_color(int v, int color, adjacency_list graph[]) {
    adjacency_list_node* currNode = graph[v].head;
    while (currNode != NULL) {
        int neighbor = currNode->vertex;
        if (vertexColors[neighbor] == color) {
            return 0;
        }
        currNode = currNode->next;
    }
    return 1;
}

int get_valid_color(int v, int k, adjacency_list graph[]) {
    for (int i = 0; i < k; i++) {
        if (is_valid_color(v, i, graph)) {
            return i;
        }
    }
}

void color_graph(adjacency_list graph[], int num_vertices, int num_colors) {
    for (int i = 0; i < num_vertices; i++) {
        vertexColors[i] = get_valid_color(i, num_colors, graph);
    }
}

void print_colors(int num_vertices) {
    printf("Here are the colors for each vertex:\n");
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: Color %d\n", i, vertexColors[i]);
    }
}

int main() {
    srand(time(NULL));
    init_colors();

    printf("Welcome to the Surrealist Graph Coloring Problem!\n");
    printf("In this surreal world, we have a graph with random connections and colors.\n");
    printf("You must determine how many colors it takes to color this unique graph!\n\n");

    int num_vertices = rand() % MAX_VERTICES + 1;

    adjacency_list graph[num_vertices];

    for (int i = 0; i < num_vertices; i++) {
        graph[i].num_neighbors = 0;
        graph[i].head = NULL;
    }

    for (int i = 0; i < num_vertices; i++) {
        int num_neighbors = rand() % num_vertices;
        for (int j = 0; j < num_neighbors; j++) {
            int neighbor = rand() % num_vertices;
            adjacency_list_node* newNode = malloc(sizeof(adjacency_list_node));
            newNode->vertex = neighbor;
            newNode->next = graph[i].head;
            graph[i].head = newNode;
            graph[i].num_neighbors++;
        }
    }

    int num_colors = rand() % num_vertices + 1;
    if (num_colors == 1) {
        printf("This graph can be colored with only 1 color!\n");
    } else {
        printf("This graph cannot be colored with only 1 color.\n");
    }

    color_graph(graph, num_vertices, num_colors);
    print_colors(num_vertices);

    return 0;
}