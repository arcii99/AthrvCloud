//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row, col;
} Point;

/* A* algorithm implementation */
int astar(int map[][COLS], Point start, Point goal) {
    int g = 0;
    bool success = false;
    Point current = start;
    Point open_set[ROWS * COLS];
    int f_score[ROWS][COLS];
    int g_score[ROWS][COLS];
    int h_score[ROWS][COLS];
    int open_size = 0;
    bool closed_set[ROWS][COLS];

    /* Initialize g, f, and h scores */
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            g_score[i][j] = 1000; /* set initial g scores very high */
            h_score[i][j] = abs(i - goal.row) + abs(j - goal.col);
            f_score[i][j] = g_score[i][j] + h_score[i][j];
        }
    }

    /* Start with the starting point */
    g_score[start.row][start.col] = 0;
    f_score[start.row][start.col] = h_score[start.row][start.col];
    open_set[open_size++] = start;

    /* Continue searching while there are still points in the open set */
    while (open_size > 0) {
        /* Find the point in the open set with the lowest f score */
        int lowest_f = f_score[open_set[0].row][open_set[0].col];
        int current_index = 0;
        for (int i = 1; i < open_size; i++) {
            if (f_score[open_set[i].row][open_set[i].col] < lowest_f) {
                lowest_f = f_score[open_set[i].row][open_set[i].col];
                current_index = i;
            }
        }
        current = open_set[current_index];

        /* Check if we have reached the goal */
        if (current.row == goal.row && current.col == goal.col) {
            success = true;
            break;
        }

        /* Remove current from the open set */
        open_size--;
        for (int i = current_index; i < open_size; i++) {
            open_set[i] = open_set[i + 1];
        }

        /* Add current to the closed set */
        closed_set[current.row][current.col] = true;

        /* Check the neighbor points */
        Point neighbors[4] = {{current.row - 1, current.col},
                              {current.row, current.col + 1},
                              {current.row + 1, current.col},
                              {current.row, current.col - 1}};

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];
            if (neighbor.row < 0 || neighbor.row >= ROWS || 
                neighbor.col < 0 || neighbor.col >= COLS) {
                continue;
            }
            if (map[neighbor.row][neighbor.col] == 1 || 
                closed_set[neighbor.row][neighbor.col]) {
                continue;
            }
            int tentative_g = g_score[current.row][current.col] + 1;
            if (tentative_g >= g_score[neighbor.row][neighbor.col]) {
                continue;
            }

            /* This path is the best so far, record it */
            g_score[neighbor.row][neighbor.col] = tentative_g;
            h_score[neighbor.row][neighbor.col] = abs(neighbor.row - goal.row) + 
                                                   abs(neighbor.col - goal.col);
            f_score[neighbor.row][neighbor.col] = g_score[neighbor.row][neighbor.col] + 
                                                   h_score[neighbor.row][neighbor.col];
            open_set[open_size++] = neighbor;
        }

        g++;
    }

    if (success) {
        return g_score[goal.row][goal.col];
    } else {
        return -1;
    }
}

int main() {
    int map[ROWS][COLS] = {{0,0,1,0,0,0,0,0,0,0},
                           {0,0,1,0,0,0,0,0,0,0},
                           {0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,0,0,1,0,0,0},
                           {0,0,0,0,0,0,1,0,0,0},
                           {0,0,0,0,0,0,0,0,1,0},
                           {0,0,0,0,0,0,0,0,1,0},
                           {0,0,0,0,0,0,0,0,0,0},
                           {0,0,0,0,0,0,0,0,0,0}};

    int path_length = astar(map, (Point){0,0}, (Point){9,9});
    printf("Path length: %d\n", path_length);

    return 0;
}