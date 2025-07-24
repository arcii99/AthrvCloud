//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 21
#define COLS 21

char screen[ROWS][COLS] = {' '}; // Screen matrix
int p_row, p_col; // Pac-man coordinates
int score = 0; // Player score
bool game_over = false; // Flag to check if the game is over
bool has_eaten = false; // Flag to check if Pac-man has eaten a pill

void print_screen();
void move_pacman(int delta_row, int delta_col);
void check_collision(int row, int col);
void update_score();
void check_gameover();

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Set the initial position of Pac-man
    p_row = ROWS / 2;
    p_col = COLS / 2;

    // Place pills on the screen
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            if(screen[row][col] == ' ') {
                if(rand() % 10 == 0) {
                    screen[row][col] = '.';
                }
            }
        }
    }

    // Game loop
    while(!game_over) {
        // Clear screen
        system("clear");

        // Print screen
        print_screen();

        // Ask player for direction
        printf("Enter direction (w,a,s,d): ");
        char input;
        scanf(" %c", &input);

        // Move Pac-man
        if(input == 'w') {
            move_pacman(-1, 0);
        } else if(input == 's') {
            move_pacman(1, 0);
        } else if(input == 'a') {
            move_pacman(0, -1);
        } else if(input == 'd') {
            move_pacman(0, 1);
        }

        // Check if Pac-man has collided with anything
        check_collision(p_row, p_col);

        // Update score
        update_score();

        // Check for game over
        check_gameover();
    }

    // Game over
    printf("Game over! Final score: %d\n", score);

    return 0;
}

void print_screen() {
    // Print top border
    printf("+");
    for(int col = 0; col < COLS; col++) {
        printf("-");
    }
    printf("+\n");

    // Print screen
    for(int row = 0; row < ROWS; row++) {
        printf("|");
        for(int col = 0; col < COLS; col++) {
            printf("%c", screen[row][col]);
        }
        printf("|\n");
    }

    // Print bottom border
    printf("+");
    for(int col = 0; col < COLS; col++) {
        printf("-");
    }
    printf("+\n");
}

void move_pacman(int delta_row, int delta_col) {
    // Calculate new position
    int new_row = p_row + delta_row;
    int new_col = p_col + delta_col;

    // Check if new position is within bounds
    if(new_row < 0 || new_row >= ROWS || new_col < 0 || new_col >= COLS) {
        return;
    }

    // Check if new position is a wall
    if(screen[new_row][new_col] == '#') {
        return;
    }

    // Move Pac-man
    screen[p_row][p_col] = ' ';
    p_row = new_row;
    p_col = new_col;
    screen[p_row][p_col] = 'P';
}

void check_collision(int row, int col) {
    // Check if Pac-man has collided with a pill
    if(screen[row][col] == '.') {
        screen[row][col] = ' ';
        has_eaten = true;
    }
}

void update_score() {
    // Update score if Pac-man has eaten a pill
    if(has_eaten) {
        score++;
        has_eaten = false;
    }
}

void check_gameover() {
    // Check if all pills have been eaten
    bool has_pills = false;
    for(int row = 0; row < ROWS; row++) {
        for(int col = 0; col < COLS; col++) {
            if(screen[row][col] == '.') {
                has_pills = true;
                break;
            }
        }
        if(has_pills) {
            break;
        }
    }
    if(!has_pills) {
        game_over = true;
        return;
    }

    // Check if Pac-man has collided with a ghost
    // (not implemented in this example)
}