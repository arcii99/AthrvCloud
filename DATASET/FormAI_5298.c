//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define ROWS 20
#define COLS 30
#define GHOSTS 4

// define game entities
char board[ROWS][COLS];
int score;
int lives;
int pacman_x, pacman_y;
int ghost_x[GHOSTS], ghost_y[GHOSTS];

// initialize game board
void init_board()
{
    // clear the board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }

    // place walls
    for (int i = 0; i < ROWS; i++) {
        board[i][0] = '#';
        board[i][COLS-1] = '#';
    }
    for (int j = 0; j < COLS; j++) {
        board[0][j] = '#';
        board[ROWS-1][j] = '#';
    }
    for (int i = 5; i < ROWS-5; i++) {
        board[i][COLS/2] = '#';
    }

    // place pacman
    pacman_x = ROWS/2;
    pacman_y = 1;
    board[pacman_x][pacman_y] = 'P';

    // place ghosts
    for (int i = 0; i < GHOSTS; i++) {
        ghost_x[i] = ROWS/2;
        ghost_y[i] = COLS-2-i;
        board[ghost_x[i]][ghost_y[i]] = 'G';
    }

    // set initial score and lives
    score = 0;
    lives = 3;
}

// draw game board
void draw_board()
{
    system("clear");
    printf("Score: %d\nLives: %d\n\n", score, lives);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// move pacman
void move_pacman()
{
    int new_x = pacman_x, new_y = pacman_y;
    char input = getchar();

    switch(input) {
        case 'w':
            new_x--;
            break;
        case 'a':
            new_y--;
            break;
        case 's':
            new_x++;
            break;
        case 'd':
            new_y++;
            break;
        default:
            break;
    }

    if (board[new_x][new_y] == '.') {
        board[pacman_x][pacman_y] = '.';
        pacman_x = new_x;
        pacman_y = new_y;
        board[pacman_x][pacman_y] = 'P';
    } else if (board[new_x][new_y] == 'G') {
        lives--;
        if (lives == 0) {
            printf("Game over\n");
            exit(0);
        } else {
            init_board();
        }
    }
}

// move ghosts
void move_ghosts()
{
    for (int i = 0; i < GHOSTS; i++) {
        int new_x, new_y;
        do {
            int direction = rand() % 4;
            switch(direction) {
                case 0:
                    new_x = ghost_x[i]-1;
                    new_y = ghost_y[i];
                    break;
                case 1:
                    new_x = ghost_x[i];
                    new_y = ghost_y[i]-1;
                    break;
                case 2:
                    new_x = ghost_x[i]+1;
                    new_y = ghost_y[i];
                    break;
                case 3:
                    new_x = ghost_x[i];
                    new_y = ghost_y[i]+1;
                    break;
                default:
                    break;
            }
        } while (board[new_x][new_y] != '.');
        board[ghost_x[i]][ghost_y[i]] = '.';
        ghost_x[i] = new_x;
        ghost_y[i] = new_y;
        board[ghost_x[i]][ghost_y[i]] = 'G';
    }
}

int main()
{
    // seed random number generator
    srand(time(0));

    // initialize game board and entities
    init_board();

    // game loop
    while (1) {
        // draw game board
        draw_board();

        // move pacman
        move_pacman();

        // move ghosts
        move_ghosts();
    }

    return 0;
}