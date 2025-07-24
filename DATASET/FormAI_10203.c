//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 20
#define MAX_Y 20
#define MAX_FRUITS 5

char board[MAX_X][MAX_Y];
int pacman_x, pacman_y;
int ghosts_x[4], ghosts_y[4];
int fruits_x[MAX_FRUITS], fruits_y[MAX_FRUITS];
int fruits_collected = 0;

void initialize_board() {
    int i, j;
    srand(time(NULL));

    for(i = 0; i < MAX_X; i++) {
        for(j = 0; j < MAX_Y; j++) {
            if(rand() % 2) {
                board[i][j] = '#';
            }
            else {
                board[i][j] = ' ';
            }
        }
    }

    board[MAX_X/2][MAX_Y/2] = 'P';
    pacman_x = MAX_X/2;
    pacman_y = MAX_Y/2;

    for(i = 0; i < 4; i++) {
        ghosts_x[i] = rand() % MAX_X;
        ghosts_y[i] = rand() % MAX_Y;
        board[ghosts_x[i]][ghosts_y[i]] = 'G';
    }

    for(i = 0; i < MAX_FRUITS; i++) {
        fruits_x[i] = rand() % MAX_X;
        fruits_y[i] = rand() % MAX_Y;
        board[fruits_x[i]][fruits_y[i]] = 'F';
    }
}

void print_board() {
    int i, j;

    for(i = 0; i < MAX_X; i++) {
        for(j = 0; j < MAX_Y; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void move_pacman(char dir) {
    switch(dir) {
        case 'w':
            if(pacman_x > 0 && board[pacman_x-1][pacman_y] != '#') {
                board[pacman_x][pacman_y] = ' ';
                pacman_x--;
                if(board[pacman_x][pacman_y] == 'F') {
                    board[pacman_x][pacman_y] = ' ';
                    fruits_collected++;
                }
                board[pacman_x][pacman_y] = 'P';
            }
            break;
        case 'a':
            if(pacman_y > 0 && board[pacman_x][pacman_y-1] != '#') {
                board[pacman_x][pacman_y] = ' ';
                pacman_y--;
                if(board[pacman_x][pacman_y] == 'F') {
                    board[pacman_x][pacman_y] = ' ';
                    fruits_collected++;
                }
                board[pacman_x][pacman_y] = 'P';
            }
            break;
        case 's':
            if(pacman_x < MAX_X-1 && board[pacman_x+1][pacman_y] != '#') {
                board[pacman_x][pacman_y] = ' ';
                pacman_x++;
                if(board[pacman_x][pacman_y] == 'F') {
                    board[pacman_x][pacman_y] = ' ';
                    fruits_collected++;
                }
                board[pacman_x][pacman_y] = 'P';
            }
            break;
        case 'd':
            if(pacman_y < MAX_Y-1 && board[pacman_x][pacman_y+1] != '#') {
                board[pacman_x][pacman_y] = ' ';
                pacman_y++;
                if(board[pacman_x][pacman_y] == 'F') {
                    board[pacman_x][pacman_y] = ' ';
                    fruits_collected++;
                }
                board[pacman_x][pacman_y] = 'P';
            }
            break;
    }
}

void move_ghosts() {
    int i;
    for(i = 0; i < 4; i++) {
        // randomly move up, down, left or right
        int dir = rand() % 4;
        switch(dir) {
            case 0:
                if(ghosts_x[i] > 0 && board[ghosts_x[i]-1][ghosts_y[i]] != '#') {
                    board[ghosts_x[i]][ghosts_y[i]] = ' ';
                    ghosts_x[i]--;
                    board[ghosts_x[i]][ghosts_y[i]] = 'G';
                }
                break;
            case 1:
                if(ghosts_y[i] > 0 && board[ghosts_x[i]][ghosts_y[i]-1] != '#') {
                    board[ghosts_x[i]][ghosts_y[i]] = ' ';
                    ghosts_y[i]--;
                    board[ghosts_x[i]][ghosts_y[i]] = 'G';
                }
                break;
            case 2:
                if(ghosts_x[i] < MAX_X-1 && board[ghosts_x[i]+1][ghosts_y[i]] != '#') {
                    board[ghosts_x[i]][ghosts_y[i]] = ' ';
                    ghosts_x[i]++;
                    board[ghosts_x[i]][ghosts_y[i]] = 'G';
                }
                break;
            case 3:
                if(ghosts_y[i] < MAX_Y-1 && board[ghosts_x[i]][ghosts_y[i]+1] != '#') {
                    board[ghosts_x[i]][ghosts_y[i]] = ' ';
                    ghosts_y[i]++;
                    board[ghosts_x[i]][ghosts_y[i]] = 'G';
                }
                break;
        }
    }
}

void play_game() {
    char dir;
    while(fruits_collected < MAX_FRUITS) {
        print_board();
        printf("Fruits collected: %d\n", fruits_collected);
        printf("Enter move (w = up, a = left, s = down, d = right): ");
        scanf("%c", &dir);
        getchar();
        move_pacman(dir);
        move_ghosts();
    }
    printf("Congratulations! You have collected all the fruits!\n");
}

int main() {
    printf("Welcome to the C Pac-Man Game Clone!\n");
    initialize_board();
    play_game();
    return 0;
}