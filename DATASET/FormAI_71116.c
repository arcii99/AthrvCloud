//FormAI DATASET v1.0 Category: Pac-Man Game Clone ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 20
#define NUM_DOTS 200

// Global variables
char board[BOARD_SIZE][BOARD_SIZE];
int x_pos = 10;
int y_pos = 10;
int score = 0;
int num_dots_remaining = NUM_DOTS;
int level = 1;

// Function to generate random number
int random_number(int min, int max) {
    return rand() % (max-min+1) + min;
}

// Function to setup board
void setup_board() {
    int i, j;

    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            if(i == 0 || i == BOARD_SIZE-1 || j == 0 || j == BOARD_SIZE-1)
                board[i][j] = '#';
            else
                board[i][j] = ' ';
        }
    }

    // Place dots throughout board
    for(i = 0; i < NUM_DOTS; i++) {
        int x = random_number(1, BOARD_SIZE-2);
        int y = random_number(1, BOARD_SIZE-2);

        if(board[x][y] == ' ')
            board[x][y] = '.';
        else
            i--;
    }

    // Place Pac-Man on board
    board[x_pos][y_pos] = 'C';
}

// Function to print out board
void print_board() {
    int i, j;

    printf("Score: %d  Dots Remaining: %d  Level: %d\n", score, num_dots_remaining, level);

    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// Function to move Pac-Man up
void move_up() {
    if(board[x_pos-1][y_pos] != '#') {
        if(board[x_pos-1][y_pos] == '.') {
            score += 10;
            num_dots_remaining--;
        }
        board[x_pos][y_pos] = ' ';
        x_pos--;
        board[x_pos][y_pos] = 'C';
    }
}

// Function to move Pac-Man down
void move_down() {
    if(board[x_pos+1][y_pos] != '#') {
        if(board[x_pos+1][y_pos] == '.') {
            score += 10;
            num_dots_remaining--;
        }
        board[x_pos][y_pos] = ' ';
        x_pos++;
        board[x_pos][y_pos] = 'C';
    }
}

// Function to move Pac-Man left
void move_left() {
    if(board[x_pos][y_pos-1] != '#') {
        if(board[x_pos][y_pos-1] == '.') {
            score += 10;
            num_dots_remaining--;
        }
        board[x_pos][y_pos] = ' ';
        y_pos--;
        board[x_pos][y_pos] = 'C';
    }
}

// Function to move Pac-Man right
void move_right() {
    if(board[x_pos][y_pos+1] != '#') {
        if(board[x_pos][y_pos+1] == '.') {
            score += 10;
            num_dots_remaining--;
        }
        board[x_pos][y_pos] = ' ';
        y_pos++;
        board[x_pos][y_pos] = 'C';
    }
}

// Function to get user input and move Pac-Man
void move_pacman() {
    char input;

    printf("Enter direction (u/d/l/r): ");
    scanf("%c", &input);

    switch(tolower(input)) {
        case 'u':
            move_up();
            break;
        case 'd':
            move_down();
            break;
        case 'l':
            move_left();
            break;
        case 'r':
            move_right();
            break;
        default:
            printf("Invalid input\n");
            break;
    }
}

// Main function to run game
int main() {
    srand(time(NULL));

    setup_board();

    while(num_dots_remaining > 0) {
        print_board();
        move_pacman();
    }

    level++;
    num_dots_remaining = NUM_DOTS;
    printf("Level Complete!\n");

    setup_board();

    while(num_dots_remaining > 0) {
        print_board();
        move_pacman();
    }

    level++;
    num_dots_remaining = NUM_DOTS;
    printf("Level Complete!\n");

    return 0;
}