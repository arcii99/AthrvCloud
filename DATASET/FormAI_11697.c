//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ephemeral
#include<stdio.h>

int maze[6][6] = {
    {1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0},
    {1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0},
    {1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 1}
};

int sol[6][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
};

int find_path(int i, int j) {
    if (i == 5 && j == 5) {
        sol[i][j] = 1;
        return 1;
    }
    if (i<0 || i>=6 || j<0 || j>=6 || maze[i][j] == 0 || sol[i][j] == 1)
        return 0;
    sol[i][j] = 1;
    if (find_path(i+1, j) || find_path(i, j+1) || find_path(i-1, j) || find_path(i, j-1))
        return 1;
    sol[i][j] = 0;
    return 0;
}

int main() {
    int i, j;
    if (find_path(0, 0)) {
        printf("The path is: \n");
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 6; j++)
                printf("%d ", sol[i][j]);
            printf("\n");
        }
    }
    else
        printf("Path does not exist");
    return 0;
}