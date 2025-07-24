//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point node;
    int f_score;
} Node;

Node came_from[MAX_ROWS][MAX_COLS];
int g_score[MAX_ROWS][MAX_COLS];
int f_score[MAX_ROWS][MAX_COLS];
bool closed_set[MAX_ROWS][MAX_COLS];

int heuristic(Point start, Point end) {
    return abs(start.row - end.row) + abs(start.col - end.col);
}

Node node_create(Point node, int f_score) {
    Node n;
    n.node = node;
    n.f_score = f_score;
    return n;
}

void a_star(Point start, Point end) {
    memset(closed_set, false, sizeof(closed_set));
    memset(g_score, INT_MAX, sizeof(g_score));
    memset(f_score, INT_MAX, sizeof(f_score));

    Node current_node = node_create(start, 0);
    f_score[start.row][start.col] = g_score[start.row][start.col] = 0;

    while (true) {
        bool new_path_found = false;
        int lowest_f_score = INT_MAX;
        Point neighbor_nodes[4] = {
            {current_node.node.row - 1, current_node.node.col},
            {current_node.node.row + 1, current_node.node.col},
            {current_node.node.row, current_node.node.col - 1},
            {current_node.node.row, current_node.node.col + 1}
        };

        for (int i = 0; i < 4; ++i) {
            Point neighbor = neighbor_nodes[i];

            if (neighbor.row >= MAX_ROWS || neighbor.col >= MAX_COLS || neighbor.row < 0 || neighbor.col < 0) {
                continue;
            }

            if (closed_set[neighbor.row][neighbor.col]) {
                continue;
            }

            int tentative_g_score = g_score[current_node.node.row][current_node.node.col] + 1;

            if (tentative_g_score >= g_score[neighbor.row][neighbor.col]) {
                continue;
            }

            came_from[neighbor.row][neighbor.col] = current_node;
            g_score[neighbor.row][neighbor.col] = tentative_g_score;
            f_score[neighbor.row][neighbor.col] = tentative_g_score + heuristic(neighbor, end);

            if (f_score[neighbor.row][neighbor.col] < lowest_f_score) {
                lowest_f_score = f_score[neighbor.row][neighbor.col];
                current_node = node_create(neighbor, lowest_f_score);
            }

            if (neighbor.row == end.row && neighbor.col == end.col) {
                new_path_found = true;
                break;
            }
        }

        if (new_path_found) {
            break;
        }

        if (lowest_f_score == INT_MAX) {
            printf("No path found.\n");
            break;
        }

        closed_set[current_node.node.row][current_node.node.col] = true;
    }

    // if we get here, it means that the goal was found
    printf("Path found. Length: %d\n", g_score[end.row][end.col]);

    while (current_node.node.row != start.row || current_node.node.col != start.col) {
        printf("(%d, %d)\n", current_node.node.row, current_node.node.col);
        current_node = came_from[current_node.node.row][current_node.node.col];
    }

    printf("(%d, %d)\n", start.row, start.col);
}

int main() {
    Point start = {0, 0};
    Point end = {5, 5};

    a_star(start, end);

    return 0;
}