//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 10

typedef struct node {
    int x, y, f_score, g_score;
    struct node *parent;
} node;

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void a_star(int map[ROWS][COLS], node *start, node *end) {
    node *open_list[ROWS * COLS] = {NULL};
    node *closed_list[ROWS * COLS] = {NULL};
    int open_count = 0, closed_count = 0;
    node *current_node = start;
    current_node->g_score = 0;
    current_node->f_score = heuristic(start->x, start->y, end->x, end->y);
    open_list[open_count++] = current_node;

    while (open_count > 0 && current_node != end) {
        // Find the node with the lowest f_score
        int lowest_f_score = 999999;
        int current_index = -1;
        for (int i = 0; i < open_count; i++) {
            if (open_list[i]->f_score < lowest_f_score) {
                lowest_f_score = open_list[i]->f_score;
                current_index = i;
            }
        }

        current_node = open_list[current_index];
        open_list[current_index] = NULL;
        open_count--;

        // Add current node to closed list
        closed_list[closed_count++] = current_node;

        // Check neighbor nodes
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if ((i == 0 && j == 0) || 
                    current_node->x + i < 0 || current_node->x + i >= ROWS || 
                    current_node->y + j < 0 || current_node->y + j >= COLS ||
                    map[current_node->x + i][current_node->y + j] == 1) {
                    continue;
                }
                int tentative_g_score = current_node->g_score + 1;
                int found = 0;
                for (int k = 0; k < open_count; k++) {
                    if (open_list[k]->x == current_node->x + i && open_list[k]->y == current_node->y + j) {
                        found = 1;
                        if (tentative_g_score < open_list[k]->g_score) {
                            open_list[k]->g_score = tentative_g_score;
                            open_list[k]->f_score = tentative_g_score + heuristic(open_list[k]->x, open_list[k]->y, end->x, end->y);
                            open_list[k]->parent = current_node;
                        }
                        break;
                    }
                }
                if (!found) {
                    node *new_node = (node*) malloc(sizeof(node));
                    new_node->x = current_node->x + i;
                    new_node->y = current_node->y + j;
                    new_node->g_score = tentative_g_score;
                    new_node->f_score = tentative_g_score + heuristic(new_node->x, new_node->y, end->x, end->y);
                    new_node->parent = current_node;
                    open_list[open_count++] = new_node;
                }
            }
        }
    }

    if (current_node == end) {
        printf("Path found! The path is:\n");
        node *path[ROWS * COLS];
        int path_count = 0;
        while (current_node != NULL) {
            path[path_count++] = current_node;
            current_node = current_node->parent;
        }
        for (int i = path_count - 1; i >= 0; i--) {
            printf("(%d, %d) ", path[i]->x, path[i]->y);
        }
        printf("\n");
    } else {
        printf("Path not found!\n");
    }

    // Free memory
    for (int i = 0; i < open_count; i++) {
        free(open_list[i]);
    }
    for (int i = 0; i < closed_count; i++) {
        free(closed_list[i]);
    }
}

int main() {
    int map[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    node start_node = {0, 0, 0, 0, NULL};
    node end_node = {9, 9, 0, 0, NULL};
    a_star(map, &start_node, &end_node);
    return 0;
}