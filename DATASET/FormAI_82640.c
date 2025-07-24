//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row, col;
} Point;

typedef struct {
    Point parent;
    double f, g, h;
    bool closed;
} Node;

Node nodes[ROWS][COLS];

double heuristic(Point p1, Point p2) {
    int dx = abs(p1.col - p2.col);
    int dy = abs(p1.row - p2.row);
    return dx + dy;
}

void reconstruct_path(Point start, Point goal) {
    Point current = goal;
    while (current.row != start.row || current.col != start.col) {
        printf("-> (%d, %d) ", current.row, current.col);
        current = nodes[current.row][current.col].parent;
    }
    printf("-> (%d, %d)\n", start.row, start.col);
}

void astar(Point start, Point goal) {
    int r, c;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            nodes[r][c] = (Node){{-1, -1}, 0, 0, 0, false};
        }
    }

    Node *start_node = &nodes[start.row][start.col];
    start_node->g = 0;
    start_node->h = heuristic(start, goal);
    start_node->f = start_node->g + start_node->h;

    while (true) {
        double min_f = ROWS * COLS;
        Node *current_node = NULL;

        // Pick the node with lowest f to expand
        for (r = 0; r < ROWS; r++) {
            for (c = 0; c < COLS; c++) {
                Node *n = &nodes[r][c];
                if (!n->closed && n->f < min_f) {
                    min_f = n->f;
                    current_node = n;
                }
            }
        }

        if (current_node == NULL) {
            printf("Path not found\n");
            return;
        }

        // Goal reached
        if (current_node->parent.row == goal.row && current_node->parent.col == goal.col) {
            reconstruct_path(start, goal);
            return;
        }

        current_node->closed = true;
        for (r = -1; r <= 1; r++) {
            for (c = -1; c <= 1; c++) {
                if (r == 0 && c == 0)
                    continue;

                int nr = current_node->parent.row + r;
                int nc = current_node->parent.col + c;

                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS) {
                    Node *neighbor = &nodes[nr][nc];

                    if (!neighbor->closed) {
                        double g_score = current_node->g + 1; // Cost of moving to neighbor is always 1
                        double h_score = heuristic((Point){nr, nc}, goal);
                        double f_score = g_score + h_score;

                        bool is_better = false;
                        if (neighbor->f == 0) {
                            neighbor->f = f_score;
                            is_better = true;
                        } else if (f_score < neighbor->f) {
                            is_better = true;
                        }

                        if (is_better) {
                            neighbor->parent = current_node->parent;
                            neighbor->g = g_score;
                            neighbor->h = h_score;
                            neighbor->f = f_score;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    Point start = {0, 0};
    Point goal = {ROWS - 1, COLS - 1};

    astar(start, goal);

    return 0;
}