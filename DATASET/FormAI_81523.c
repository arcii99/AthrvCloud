//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int x;
    int y;
    struct node* parent;
    double g;
    double h;
    double f;
} Node;

Node* create_node(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->parent = NULL;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    return node;
}

double distance(Node* a, Node* b) {
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

void a_star(Node* start, Node* goal, Node** nodes, int num_nodes) {
    Node* open_set[num_nodes];
    int num_open = 0;
    Node* closed_set[num_nodes];
    int num_closed = 0;

    open_set[num_open] = start;
    num_open++;

    while (num_open > 0) {
        // Find the node with the lowest f value in the open set
        int best_node_index = 0;
        double best_f = open_set[0]->f;
        for (int i = 1; i < num_open; i++) {
            if (open_set[i]->f < best_f) {
                best_node_index = i;
                best_f = open_set[i]->f;
            }
        }

        Node* current = open_set[best_node_index];

        // Check if we've reached the goal
        if (current == goal) {
            return;
        }

        // Move the current node from the open set to the closed set
        open_set[best_node_index] = open_set[num_open - 1];
        num_open--;
        closed_set[num_closed] = current;
        num_closed++;

        // Check the neighbors of the current node
        for (int i = 0; i < num_nodes; i++) {
            Node* neighbor = nodes[i];

            // Skip the node if it's in the closed set or it's not traversable
            if (neighbor == current->parent || neighbor->g == -1) {
                continue;
            }

            double tentative_g = current->g + distance(current, neighbor);

            int in_open = 0;
            for (int j = 0; j < num_open; j++) {
                if (open_set[j] == neighbor) {
                    in_open = 1;
                    break;
                }
            }

            if (!in_open || tentative_g < neighbor->g) {
                neighbor->parent = current;
                neighbor->g = tentative_g;
                neighbor->h = distance(neighbor, goal);
                neighbor->f = neighbor->g + neighbor->h;

                if (!in_open) {
                    open_set[num_open] = neighbor;
                    num_open++;
                }
            }
        }
    }
}

int main() {
    Node* nodes[5];
    nodes[0] = create_node(0, 0);
    nodes[1] = create_node(1, 1);
    nodes[2] = create_node(2, 2);
    nodes[3] = create_node(3, 3);
    nodes[4] = create_node(4, 4);

    // Set node 2 to be impassable
    nodes[2]->g = -1;

    a_star(nodes[0], nodes[4], nodes, 5);

    // Print the path
    Node* current = nodes[4];
    while (current != NULL) {
        printf("(%d, %d)\n", current->x, current->y);
        current = current->parent;
    }

    // Free memory
    for (int i = 0; i < 5; i++) {
        free(nodes[i]);
    }

    return 0;
}