//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int cost[ROW][COL] = {
    { 1, 2, 1, 1, 5 },
    { 2, 3, 2, 3, 2 },
    { 3, 2, 1, 2, 1 },
    { 4, 1, 2, 2, 3 },
    { 2, 3, 1, 3, 1 }
};

void printMap(bool map[ROW][COL]) {
    printf("_________________\n");
    for (int row = 0; row < ROW; row++) {
        for (int col = 0; col < COL; col++) {
            if (row == 0 && col == 0) printf("S ");
            else if (row == ROW - 1 && col == COL - 1) printf("E ");
            else printf(map[row][col] ? "* " : ". ");
        }
        printf("\n");
    }
    printf("_________________\n");
}

int heuristic(int row, int col) {
    return abs(ROW - 1 - row) + abs(COL - 1 - col);
}

void aStar() {
    bool closed[ROW][COL];
    bool open[ROW][COL];
    int x = 0, y = 0;
    int g = 0, h = 0, f = 0;
    int minF, minRow, minCol;

    for (int row = 0; row < ROW; row++)
        for (int col = 0; col < COL; col++)
            open[row][col] = closed[row][col] = false;

    open[y][x] = true;

    while (open[y][x]) {
        g++;

        if (x == ROW - 1 && y == COL - 1) {
            printf("Path found!\n");
            bool map[ROW][COL];
            for (int row = 0; row < ROW; row++)
                for (int col = 0; col < COL; col++)
                    map[row][col] = false;

            while (!(x == 0 && y == 0)) {
                map[y][x] = true; // mark path
                int prev_x = x, prev_y = y;
                int minF = 999999;

                for (int row = -1; row <= 1; row++) {
                    for (int col = -1; col <= 1; col++) {
                        if ((row == 0 || col == 0) && !(row == 0 && col == 0)) {
                            int adj_y = y + row;
                            int adj_x = x + col;
                            if (adj_x >= 0 && adj_y >= 0 && adj_x < ROW && adj_y < COL && closed[adj_y][adj_x]) {
                                int adj_f = cost[adj_y][adj_x] + g + heuristic(adj_y, adj_x);
                                if (adj_f <= minF) {
                                    minF = adj_f;
                                    x = adj_x;
                                    y = adj_y;
                                }
                            }
                        }
                    }
                }
                cost[prev_y][prev_x] = minF - g - heuristic(prev_y, prev_x);
            }
            map[y][x] = true;
            printMap(map);
            return;
        }

        closed[y][x] = true;
        open[y][x] = false;
        minF = 999999;

        for (int row = -1; row <= 1; row++) {
            for (int col = -1; col <= 1; col++) {
                if ((row == 0 || col == 0) && !(row == 0 && col == 0)) {
                    int adj_y = y + row;
                    int adj_x = x + col;
                    if (adj_x >= 0 && adj_y >= 0 && adj_x < ROW && adj_y < COL && !closed[adj_y][adj_x]) {
                        int adj_f = cost[adj_y][adj_x] + g + heuristic(adj_y, adj_x);
                        if (adj_f <= minF) {
                            minF = adj_f;
                            minRow = adj_y;
                            minCol = adj_x;
                        }
                        open[minRow][minCol] = true;
                    }
                }
            }
        }
        x = minCol;
        y = minRow;
    }

}

int main() {
    aStar();
    return 0;
}