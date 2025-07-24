//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define MAX_SCORE 30

// Function declarations
void move_pacman(int direction);
void move_ghosts();
void draw_board();
void check_score();
void game_over();
void reset_game();

// Variables
char board[HEIGHT][WIDTH];
int pacman_x, pacman_y;
int score;
int ghost1_x, ghost1_y, ghost2_x, ghost2_y;
bool game_running;

int main() {
    // Initialize variables
    srand(time(NULL));
    pacman_x = rand() % WIDTH;
    pacman_y = rand() % HEIGHT;
    score = 0;
    ghost1_x = rand() % WIDTH;
    ghost1_y = rand() % HEIGHT;
    ghost2_x = rand() % WIDTH;
    ghost2_y = rand() % HEIGHT;
    game_running = true;

    // Game loop
    while (game_running) {
        // Clear screen and draw board
        system("clear");
        draw_board();

        // Get user input and move Pac-Man
        int direction;
        scanf("%d", &direction);
        move_pacman(direction);

        // Move ghosts
        move_ghosts();

        // Check score and game over conditions
        check_score();
        if (score == MAX_SCORE) {
            game_over();
        }
    }

    // Reset game if player chooses to play again
    reset_game();

    return 0;
}

// Function definitions
void move_pacman(int direction) {
    // Move Pac-Man based on direction input from user
    switch (direction) {
        case 1: // up
            if (pacman_y > 0) {
                pacman_y--;
            }
            break;
        case 2: // down
            if (pacman_y < HEIGHT - 1) {
                pacman_y++;
            }
            break;
        case 3: // left
            if (pacman_x > 0) {
                pacman_x--;
            }
            break;
        case 4: // right
            if (pacman_x < WIDTH - 1) {
                pacman_x++;
            }
            break;
        default:
            break;
    }
}

void move_ghosts() {
    // Move ghosts randomly
    ghost1_x += rand() % 3 - 1;
    ghost1_y += rand() % 3 - 1;
    ghost2_x += rand() % 3 - 1;
    ghost2_y += rand() % 3 - 1;

    // Check if ghosts collide with Pac-Man
    if (ghost1_x == pacman_x && ghost1_y == pacman_y ||
            ghost2_x == pacman_x && ghost2_y == pacman_y) {
        game_over();
    }
}

void draw_board() {
    // Draw board with Pac-Man, ghosts, and score
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == pacman_y && j == pacman_x) {
                printf("C");
            } else if (i == ghost1_y && j == ghost1_x ||
                    i == ghost2_y && j == ghost2_x) {
                printf("G");
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void check_score() {
    // Check if Pac-Man eats a dot and update score
    if (board[pacman_y][pacman_x] == '.') {
        board[pacman_y][pacman_x] = ' ';
        score++;
    }
}

void game_over() {
    // End game and ask user if they want to play again
    printf("Game over!\n");
    game_running = false;

    printf("Play again? (y/n)\n");
    char choice;
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        reset_game();
    }
}

void reset_game() {
    // Reset board, Pac-Man, ghosts, and score
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 5 == 0) {
                board[i][j] = '.';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    pacman_x = rand() % WIDTH;
    pacman_y = rand() % HEIGHT;
    score = 0;
    ghost1_x = rand() % WIDTH;
    ghost1_y = rand() % HEIGHT;
    ghost2_x = rand() % WIDTH;
    ghost2_y = rand() % HEIGHT;
    game_running = true;
}