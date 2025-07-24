//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare the dimensions of the game grid
#define WIDTH 50
#define HEIGHT 20

// Declare the score variables for both players
int romeo_score = 0;
int juliet_score = 0;

// Declare the position of the spaceship for both players
int romeo_position = WIDTH / 2;
int juliet_position = WIDTH / 2;

// Declare the position of the invaders
int invaders_position[HEIGHT];

// A function to clear the console
void clrscr() {
    system("cls||clear");
}

// A function to display the game grid
void display_grid() {
    int i, j;
    clrscr();
    printf("Romeo: %d - Juliet: %d\n\n", romeo_score, juliet_score);
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            // Display the spaceship for Romeo
            if (i == HEIGHT - 1 && j == romeo_position) {
                printf("R");
            }
            // Display the spaceship for Juliet
            else if (i == 0 && j == juliet_position) {
                printf("J");
            }
            // Display the invaders
            else if (i == invaders_position[j]) {
                printf("O");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// A function to move the spaceship for Romeo
void move_romeo(int move) {
    romeo_position += move;
    if (romeo_position < 0) {
        romeo_position = 0;
    }
    if (romeo_position > WIDTH - 1) {
        romeo_position = WIDTH - 1;
    }
}

// A function to move the spaceship for Juliet
void move_juliet(int move) {
    juliet_position += move;
    if (juliet_position < 0) {
        juliet_position = 0;
    }
    if (juliet_position > WIDTH - 1) {
        juliet_position = WIDTH - 1;
    }
}

// A function to move the invaders
void move_invaders() {
    int i, move;
    // Randomly select the direction of the movement
    if (rand() % 2 == 0) {
        move = -1;
    }
    else {
        move = 1;
    }
    for (i = 0; i < WIDTH; i++) {
        invaders_position[i] += move;
        // Check if the invaders have reached the spaceship of Romeo
        if (i == romeo_position && invaders_position[i] == HEIGHT - 1) {
            romeo_score++;
            init_invaders();
        }
        // Check if the invaders have reached the spaceship of Juliet
        if (i == juliet_position && invaders_position[i] == 0) {
            juliet_score++;
            init_invaders();
        }
    }
}

// A function to initialize the invaders
void init_invaders() {
    int i;
    srand(time(NULL));
    for (i = 0; i < WIDTH; i++) {
        invaders_position[i] = rand() % HEIGHT;
    }
}

int main() {
    int move, i, j;
    char input;
    init_invaders();
    while (1) {
        display_grid();
        // Check if Romeo or Juliet has won
        if (romeo_score == 10) {
            printf("Romeo wins!\n");
            break;
        }
        if (juliet_score == 10) {
            printf("Juliet wins!\n");
            break;
        }
        // Get the user input for Romeo
        printf("Romeo's turn: ");
        scanf("%c", &input);
        if (input == 'a') {
            move = -1;
        }
        else if (input == 'd') {
            move = 1;
        }
        else {
            continue;
        }
        move_romeo(move);
        // Get the user input for Juliet
        printf("Juliet's turn: ");
        scanf(" %c", &input);
        if (input == 'a') {
            move = -1;
        }
        else if (input == 'd') {
            move = 1;
        }
        else {
            continue;
        }
        move_juliet(move);
        move_invaders();
    }
    return 0;
}