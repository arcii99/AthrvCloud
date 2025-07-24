//FormAI DATASET v1.0 Category: Checkers Game ; Style: creative
#include<stdio.h>

char grid[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', ' '},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

void print_board() {
    for(int i=7;i>=0;i--) {
        printf("%d ", i+1);
        for(int j=0;j<8;j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

void move_piece() {
    int start_x, start_y, end_x, end_y;
    printf("Enter the starting position (Ex: a2): ");
    scanf("%c%d", &start_y, &start_x);
    printf("Enter the ending position (Ex: a3): ");
    scanf("%c%d", &end_y, &end_x);

    int grid_start_x = start_x-1, grid_start_y = start_y-'a';
    int grid_end_x = end_x-1, grid_end_y = end_y-'a';

    char piece = grid[grid_start_x][grid_start_y];
    grid[grid_end_x][grid_end_y] = piece;
    grid[grid_start_x][grid_start_y] = ' ';
}

int main() {
    printf("Welcome to C Checkers Game!\n");
    printf("Please make your moves in the format 'a2 a3'\n");
    while(1) {
        print_board();
        move_piece();
    }
    return 0;
}