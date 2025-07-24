//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define GRID_WIDTH 20
#define GRID_HEIGHT 15
#define PACMAN '@'
#define DOT '.'
#define GHOST 'G'

typedef struct {
    int x;
    int y;
} Position;

void display_board(char board[GRID_HEIGHT][GRID_WIDTH], Position pacman, Position ghost) {
    system("clear"); // clear console on Unix-like systems
    // system("cls"); // uncomment for Windows systems
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            if (pacman.x == j && pacman.y == i) {
                printf("%c", PACMAN);
            } else if (ghost.x == j && ghost.y == i) {
                printf("%c", GHOST);
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char board[GRID_HEIGHT][GRID_WIDTH] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '.', '.', '.', '#', '.', '#', '.', '#', '.', '.', '.', '#', '.', '.', '#'},
        {'#', '.', '#', '.', '#', '#', '#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '.', '#'},
        {'#', '#', '#', '#', '.', '#', '#', '#', '.', '#', '#', '.', '#', '.', '#', '.', '#', '.', '.', '#'},
        {'.', '.', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#', '.', '.', '#'},
        {'#', '#', '#', '#', '.', '#', '#', '.', '#', '#', '.', '#', '#', '.', '#', '.', '#', '.', '.', '#'},
        {'.', '.', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#', '.', '.', '#'},
        {'#', '#', '#', '#', '.', '#', '.', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '.', '#'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '#', '#', '#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '#', '#'},
        {'#', '.', '.', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };
    Position pacman = {1, 1};
    Position ghost = {10, 7};
    while (1) {
        display_board(board, pacman, ghost);
        char input;
        scanf("%c", &input);
        switch (input) {
            case 'w':
                if (board[pacman.y - 1][pacman.x] != '#') pacman.y--;
                break;
            case 'a':
                if (board[pacman.y][pacman.x - 1] != '#') pacman.x--;
                break;
            case 's':
                if (board[pacman.y + 1][pacman.x] != '#') pacman.y++;
                break;
            case 'd':
                if (board[pacman.y][pacman.x + 1] != '#') pacman.x++;
                break;
            case 'q':
                return 0; // quit game
            default:
                break;
        }
        // ghost movement logic
        int next_x = ghost.x;
        int next_y = ghost.y;
        if (pacman.x < ghost.x) next_x--;
        if (pacman.x > ghost.x) next_x++;
        if (pacman.y < ghost.y) next_y--;
        if (pacman.y > ghost.y) next_y++;
        if (board[next_y][next_x] != '#') {
            ghost.x = next_x;
            ghost.y = next_y;
        }
    }
    return 0;
}