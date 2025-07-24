//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: excited
#include <stdio.h>

void printMaze(char maze[][31], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char maze[21][31] = {
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
        "X............XX............X",
        "X.XXXXX.XXXXX.XX.XXXXX.XXXXX.X",
        "XoXXXXX.XXXXX.XX.XXXXX.XXXXXoX",
        "X.XXXXX.XXXXX.XX.XXXXX.XXXXX.X",
        "X...........................X",
        "X.XXXXX.XX.XXXXXXXX.XX.XXXXX.X",
        "X......XX...XX.XX...XX......X",
        "XXXXXX.XXXXX XX.X.XXXXX.XXXXXX",
        "XXXXXX.XXXXX XX.X.XXXXX.XXXXXX",
        "XXXXXX.XX          XX.XXXXXXXX",
        "XXXXXX.XX XXXXXX XX.XXXXXXXX",
        "      .    XXXXXX    .      ",
        "XXXXXX.XX X      X XX.XXXXXX",
        "XXXXXX.XX XXXXXX X XX.XXXXXX",
        "XXXXXX.XX          XX.XXXXXX",
        "XXXXXX.XXXXXXXXXXXX.XXXXXXXX",
        "X............XX............X",
        "X.XXXXX.XXXXX.XX.XXXXX.XXXXX.X",
        "Xo..XX.......   .......XX..oX",
        "XXX.XX.XX.XXXXXXXX.XX.XX.XXX",
        "X......XX...XX.XX...XX......X",
        "X.XXXXXXXXXX.XX.XXXXXXXXXX.X",
        "X...........................X",
        "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
    };

    int row = 21, col = 31;
    printMaze(maze, row, col);

    return 0;
}