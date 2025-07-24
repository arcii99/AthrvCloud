//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surprised
#include <stdio.h>
#define ROW 5
#define COL 5

int heuristic(int from_x, int from_y, int to_x, int to_y) {
    return (abs(from_x - to_x) + abs(from_y - to_y));
} 

int search(int cells[][COL], int start_x, int start_y, int end_x, int end_y) {

    int closed[ROW][COL];
    memset(closed, 0, sizeof(closed));

    int open[ROW * COL][4], oIndex = 0;

    open[0][0] = start_x;
    open[0][1] = start_y;

    open[0][2] = heuristic(start_x, start_y, end_x, end_y);
    open[0][3] = 0;

    closed[start_x][start_y] = 1;

    while (oIndex >= 0) {
        int cur_x = open[oIndex][0], cur_y = open[oIndex][1], cur_step = open[oIndex][3];

        if (cur_x == end_x && cur_y == end_y) {
            printf("Path found! Total steps: %d\n", cur_step);
            return cur_step;
        }

        oIndex--;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;
                if (cur_x + i < 0 || cur_x + i >= ROW) continue;
                if (cur_y + j < 0 || cur_y + j >= COL) continue;
                if (closed[cur_x + i][cur_y + j]) continue;
                open[++oIndex][0] = cur_x + i;
                open[oIndex][1] = cur_y + j;
                open[oIndex][2] = cur_step + 1 + heuristic(cur_x + i, cur_y + j, end_x, end_y);
                open[oIndex][3] = cur_step + 1;
                closed[cur_x + i][cur_y + j] = 1;
            }
        }

        for (int i = 0; i <= oIndex; i++) {
            for (int j = i+1; j <= oIndex; j++) {
                if (open[i][2] > open[j][2]) {
                    int t[4] = {open[i][0], open[i][1], open[i][2], open[i][3]};
                    open[i][0] = open[j][0];
                    open[i][1] = open[j][1];
                    open[i][2] = open[j][2];
                    open[i][3] = open[j][3];
                    open[j][0] = t[0];
                    open[j][1] = t[1];
                    open[j][2] = t[2];
                    open[j][3] = t[3];
                }
            }
        }

        printf("Step: %d, Current position: (%d, %d)\n", cur_step, cur_x, cur_y);
    }

    printf("Path not found!\n");
    return -1;
}

int main() {
    int cells[ROW][COL] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };
    int start_x = 0, start_y = 0, end_x = 4, end_y = 4;

    search(cells, start_x, start_y, end_x, end_y);

    return 0;
}