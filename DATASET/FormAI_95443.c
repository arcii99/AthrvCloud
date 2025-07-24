//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Game board dimensions */
#define WIDTH 10
#define HEIGHT 10

/* Randomize seed value */
#define SEED time(NULL)

/* Possible values for cells on the game board */
#define EMPTY 0
#define SHIP 1
#define HIT 2
#define MISS 3

/* Function declarations */
void initialize_board(int board[WIDTH][HEIGHT]);
void print_board(int board[WIDTH][HEIGHT]);
int place_ships(int board[WIDTH][HEIGHT], int num_of_ships);
int get_coordinate(char letter);
void play_game(int board[WIDTH][HEIGHT], int num_of_ships);

int main() {
    /* Initialize random seed */
    srand(SEED);

    /* Initialize the game board */
    int board[WIDTH][HEIGHT];
    initialize_board(board);

    /* Place ships on the game board */
    int num_of_ships = place_ships(board, 3);

    /* Print out the game instructions */
    printf("Welcome to Battleship!\n");
    printf("The object of the game is to sink all of the enemy ships.\n");
    printf("Enter coordinates as a letter and a number (e.g. A1).\n");

    /* Start the game */
    play_game(board, num_of_ships);

    return 0;
}

/* Function to initialize the game board with all empty cells */
void initialize_board(int board[WIDTH][HEIGHT]) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            board[i][j] = EMPTY;
        }
    }
}

/* Function to print out the game board */
void print_board(int board[WIDTH][HEIGHT]) {
    printf("  1 2 3 4 5 6 7 8 9 10\n");
    printf(" +-+-+-+-+-+-+-+-+-+\n");
    for (int i = 0; i < WIDTH; i++) {
        /* Convert row number to letter */
        char letter = 'A' + i;
        printf("%c|", letter);
        for (int j = 0; j < HEIGHT; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case MISS:
                    printf("o");
                    break;
                case HIT:
                    printf("x");
                    break;
                case SHIP:
                    printf(" ");
                    break;
            }
            printf("|");
        }
        printf("\n");
        printf(" +-+-+-+-+-+-+-+-+-+\n");
    }
}

/* Function to place ships on the game board */
int place_ships(int board[WIDTH][HEIGHT], int num_of_ships) {
    int count = 0;
    while (count < num_of_ships) {
        /* Generate random starting position and direction */
        int row = rand() % HEIGHT;
        int col = rand() % WIDTH;
        int dir = rand() % 2;

        /* Attempt to place ship */
        if (dir == 0) { /* vertical */
            int end_row = row + 3;
            if (end_row <= HEIGHT) {
                int overlap = 0;
                for (int i = row; i < end_row; i++) {
                    if (board[i][col] == SHIP) {
                        overlap = 1;
                        break;
                    }
                }
                if (overlap == 0) {
                    for (int i = row; i < end_row; i++) {
                        board[i][col] = SHIP;
                    }
                    count++;
                }
            }
        } else { /* horizontal */
            int end_col = col + 3;
            if (end_col <= WIDTH) {
                int overlap = 0;
                for (int i = col; i < end_col; i++) {
                    if (board[row][i] == SHIP) {
                        overlap = 1;
                        break;
                    }
                }
                if (overlap == 0) {
                    for (int i = col; i < end_col; i++) {
                        board[row][i] = SHIP;
                    }
                    count++;
                }
            }
        }
    }
    return num_of_ships;
}

/* Function to convert a letter coordinate to a row number */
int get_coordinate(char letter) {
    return letter - 'A';
}

/* Function to play the game */
void play_game(int board[WIDTH][HEIGHT], int num_of_ships) {
    int num_of_guesses = 0;
    while (1) {
        /* Print out the game board */
        printf("\n");
        print_board(board);

        /* Ask player for a coordinate guess */
        printf("Enter a coordinate: ");
        char input[10];
        scanf("%s", input);
        int row = get_coordinate(input[0]);
        int col = atoi(&input[1]) - 1;
        if (row < 0 || row >= HEIGHT || col < 0 || col >= WIDTH) {
            printf("Invalid coordinate.\n");
            continue;
        }

        /* Check the guessed cell on the game board */
        switch (board[row][col]) {
            case EMPTY:
                printf("Miss!\n");
                board[row][col] = MISS;
                break;
            case SHIP:
                printf("Hit!\n");
                board[row][col] = HIT;
                int hit_count = 0;
                for (int i = 0; i < HEIGHT; i++) {
                    for (int j = 0; j < WIDTH; j++) {
                        if (board[i][j] == HIT) {
                            hit_count++;
                        }
                    }
                }
                if (hit_count == num_of_ships * 4) {
                    printf("You win!\n");
                    return;
                }
                break;
            case HIT:
            case MISS:
                printf("Already guessed that square.\n");
                break;
        }

        num_of_guesses++;
    }
}