//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define ROWS 5
#define COLS 5
#define MAX_NUMBER 25

// Declare global variables
int board[ROWS][COLS] = {0};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
bool gameOver = false;
int count = 0;

// Function declarations
void printBoard();
int getRandomNumber();
bool isBoardFull();
bool isNumberOnBoard(int number);
bool isBingo();
void *caller(void *param);
void *callee(void *param);

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Print initial board
    printf("Welcome to the C Bingo Simulator!\n");
    sleep(1);
    printf("Generating board...\n");
    printBoard();

    // Create threads for caller and callee
    pthread_t callerThread, calleeThread;
    pthread_create(&callerThread, NULL, caller, NULL);
    pthread_create(&calleeThread, NULL, callee, NULL);

    // Wait for threads to finish
    pthread_join(callerThread, NULL);
    pthread_join(calleeThread, NULL);

    // Clean up mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

// Function to print the board
void printBoard() {
    printf("+----+----+----+----+----+\n");
    for (int i = 0; i < ROWS; i++) {
        printf("| ");
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] != 0) {
                printf("%2d", board[i][j]);
            } else {
                printf("  ");
            }
            printf(" | ");
        }
        printf("\n+----+----+----+----+----+\n");
    }
}

// Function to generate a random number
int getRandomNumber() {
    return (rand() % MAX_NUMBER) + 1;
}

// Function to check if the board is full
bool isBoardFull() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if a number is on the board
bool isNumberOnBoard(int number) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == number) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if there is bingo
bool isBingo() {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        bool bingo = true;
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 0) {
                bingo = false;
                break;
            }
        }
        if (bingo) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++) {
        bool bingo = true;
        for (int j = 0; j < ROWS; j++) {
            if (board[j][i] == 0) {
                bingo = false;
                break;
            }
        }
        if (bingo) {
            return true;
        }
    }

    // Check diagonal
    bool bingo = true;
    for (int i = 0; i < ROWS; i++) {
        if (board[i][i] == 0) {
            bingo = false;
            break;
        }
    }
    if (bingo) {
        return true;
    }

    // Check reverse diagonal
    bingo = true;
    for (int i = 0; i < ROWS; i++) {
        if (board[i][ROWS - i - 1] == 0) {
            bingo = false;
            break;
        }
    }
    if (bingo) {
        return true;
    }

    return false;
}

// Function for caller thread
void *caller(void *param) {
    printf("The caller has started the game!\n");
    while (!gameOver) {
        int number = getRandomNumber();
        pthread_mutex_lock(&mutex);
        if (!isNumberOnBoard(number)) {
            printf("The caller called: %d\n", number);
            // Place number on board
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    if (board[i][j] == 0) {
                        board[i][j] = number;
                        break;
                    }
                }
            }
            printBoard();
            // Check for bingo
            if (isBingo()) {
                printf("BINGO! The caller has won!\n");
                gameOver = true;
            }
        }
        pthread_mutex_unlock(&mutex);
        if (!gameOver && isBoardFull()) {
            printf("It's a tie!\n");
            gameOver = true;
        }
        sleep(1);
    }
    pthread_exit(0);
}

// Function for callee thread
void *callee(void *param) {
    printf("The first player has joined the game!\n");
    printf("The second player has joined the game!\n");
    while (!gameOver) {
        int number;
        printf("Enter your number (1 to 25): ");
        scanf("%d", &number);
        if (number >= 1 && number <= 25) {
            pthread_mutex_lock(&mutex);
            if (!isNumberOnBoard(number)) {
                // Place number on board
                for (int i = 0; i < ROWS; i++) {
                    for (int j = 0; j < COLS; j++) {
                        if (board[i][j] == number) {
                            board[i][j] = 0;
                            count++;
                        }
                    }
                }
                if (count == 5) {
                    printf("You've cleared a row! Congratulations!\n");
                    count = 0;
                }
                printBoard();
                // Check for bingo
                if (isBingo()) {
                    printf("BINGO! You've won!\n");
                    gameOver = true;
                }
                pthread_mutex_unlock(&mutex);
            } else {
                printf("That number is already on the board. Please enter a new one.\n");
                pthread_mutex_unlock(&mutex);
            }
        } else {
            printf("Invalid number. Please enter a number between 1 and 25.\n");
        }
    }
    pthread_exit(0);
}