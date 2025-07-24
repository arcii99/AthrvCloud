//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
    {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', '*', ' ', '*', ' ', '*', '*', ' ', '*'},
    {'*', ' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*'},
    {'*', '*', '*', '*', '*', '*', '*', ' ', ' ', '*'},
    {'*', ' ', ' ', ' ', '*', ' ', ' ', ' ', '*', '*'},
    {'*', ' ', '*', '*', '*', '*', '*', ' ', '*', '*'},
    {'*', ' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*'},
    {'*', ' ', '*', '*', '*', '*', '*', '*', ' ', '*'},
    {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
};

typedef struct Coordinate {
    int x;
    int y;
} Coord;

Coord find_start() {
    srand(time(NULL));
    Coord start;
    start.x = rand() % ROWS;
    start.y = rand() % COLS;

    while (maze[start.x][start.y] != ' ') {
        start.x = rand() % ROWS;
        start.y = rand() % COLS;
    }

    return start;
}

int maze_traversal(Coord* path, Coord curr_pos, int count) {
    if (curr_pos.x < 0 || curr_pos.y < 0 || curr_pos.x >= ROWS || curr_pos.y >= COLS) {
        return 0;
    }

    if (maze[curr_pos.x][curr_pos.y] == '*') {
        return 0;
    }

    if (maze[curr_pos.x][curr_pos.y] == 'E') {
        return count;
    }

    maze[curr_pos.x][curr_pos.y] = '*';

    Coord new_pos[4] = {
        {curr_pos.x-1, curr_pos.y},
        {curr_pos.x+1, curr_pos.y},
        {curr_pos.x, curr_pos.y-1},
        {curr_pos.x, curr_pos.y+1}
    };

    int i;
    for (i=0; i<4; i++) {
        path[count] = curr_pos;
        int result = maze_traversal(path, new_pos[i], count+1);

        if (result != 0) {
            return result;
        }
    }

    return 0;
}

void print_maze() {
    int i, j;
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Coord start = find_start();
    Coord endpoint = {8, 8};
    maze[endpoint.x][endpoint.y] = 'E';

    Coord path[ROWS*COLS];

    print_maze();
    printf("\n");

    int result = maze_traversal(path, start, 0);

    int i;
    for (i=0; i<result; i++) {
        printf("(%d, %d)\n", path[i].x, path[i].y);
    }

    return 0;
}