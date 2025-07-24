//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 30

int maze[ROW][COL];

void draw_maze() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_maze(int row, int col) {
    srand(time(NULL));
    int i, j, r, c;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            maze[i][j] = 0;
        }
    }

    r = rand() % row;
    c = rand() % col;
    maze[r][c] = 1;

    while (1) {
        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int cnt = 0, flag = 0;
        for (i = 0; i < 4; i++) {
            int x = r + dirs[i][0], y = c + dirs[i][1];
            if (x >= 0 && x < row && y >= 0 && y < col && maze[x][y] == 0) {
                cnt++;
            }
        }

        if (cnt == 0) {
            break;
        }

        int dir = rand() % 4;
        for (i = 0; i < 4; i++) {
            int x = r + dirs[(dir + i) % 4][0], y = c + dirs[(dir + i) % 4][1];
            if (x >= 0 && x < row && y >= 0 && y < col && maze[x][y] == 0) {
                maze[x][y] = 1;
                maze[r + dirs[dir][0] / 2][c + dirs[dir][1] / 2] = 1;
                r = x;
                c = y;
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            dir = (dir + 1) % 4;
        }
    }
}

int main() {
    generate_maze(ROW, COL);
    draw_maze();
    return 0;
}