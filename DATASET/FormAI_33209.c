//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 18
#define COL 26

char maze[ROW][COL] = {
    {"--------------------------"},
    {"|..........|.....|........"},
    {"|----|------|---| |---|..|"},
    {"|s......|........|.|.....|"},
    {"|--|----|--------|.|.|.--|"},
    {"|..|.............|.c|....|"},
    {"|--|---|-----------|.|--|"},
    {"|......|...........|.|..|"},
    {"|------|---| |-----|.|..|"},
    {"|..........|.......|.|..|"},
    {"|----|.....|----|..|.|..|"},
    {"|......|........|..|.e..|"},
    {"|------|------| |--------"},
    {"|..........|..|.........|"},
    {"|----|-----|..|--|----|.|"},
    {"|..........|..|..|....|.|"},
    {"|---|--------|----|..|.|"},
    {"|...................|...|"},
};

int visited[ROW][COL] = {0};

void display_maze() {
    for (int i = 0; i < ROW; i++) {
        printf("%s\n", maze[i]);
    }
}

int valid_cell(int r, int c) {
    if (r >= 0 && c >= 0 && r < ROW && c < COL) {
        if (maze[r][c] != '|' && visited[r][c] == 0) {
            return 1;
        }
    }
    return 0;
}

int find_path(int r, int c) {
    int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    if (maze[r][c] == 'e') {
        printf("\nCONGRATULATIONS! You have found the exit!\n");
        return 1;
    }
    visited[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int next_row = r + directions[i][0];
        int next_col = c + directions[i][1];
        if (valid_cell(next_row, next_col)) {
            if (find_path(next_row, next_col)) {
                return 1;
            }
        }
    }
    return 0;
}

void generate_random_coordinates(int *r, int *c, char marker) {
    *r = rand() % ROW;
    *c = rand() % COL;
    while (maze[*r][*c] != '.') {
        *r = rand() % ROW;
        *c = rand() % COL;
    }
    maze[*r][*c] = marker;
}

int main() {
    srand(time(NULL));
    int start_row, start_col;
    generate_random_coordinates(&start_row, &start_col, 's');
    
    int end_row, end_col;
    generate_random_coordinates(&end_row, &end_col, 'e');
    
    display_maze();
    printf("\nFind the path from 's' to 'e'.\n");
    
    if (!find_path(start_row, start_col)) {
        printf("There is no path from 's' to 'e'.\n");
    }
    
    display_maze();

    return 0;
}