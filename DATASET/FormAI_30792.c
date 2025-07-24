//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: excited
#include <stdio.h>
#define ROWS 10
#define COLS 10

int main() {
    int map[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    int start_row = 0;
    int start_col = 0;
    int end_row = 9;
    int end_col = 9;

    int queue[ROWS*COLS][2];
    int head = 0;
    int tail = 0;
    queue[tail][0] = start_row;
    queue[tail][1] = start_col;
    tail++;

    int visited[ROWS][COLS] = {{0}};
    visited[start_row][start_col] = 1;

    int found = 0;

    int dirs[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    while (head != tail) {
        int row = queue[head][0];
        int col = queue[head][1];
        head++;

        if (row == end_row && col == end_col) {
            found = 1;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int new_row = row + dirs[i][0];
            int new_col = col + dirs[i][1];

            if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS) {
                if (!visited[new_row][new_col] && map[new_row][new_col] == 0) {
                    visited[new_row][new_col] = 1;
                    queue[tail][0] = new_row;
                    queue[tail][1] = new_col;
                    tail++;
                }
            }
        }
    }

    if (found) {
        printf("Path found!\n");
    } else {
        printf("Path not found.\n");
    }

    return 0;
}