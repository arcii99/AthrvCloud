//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define ROWS 5
#define COLS 5
#define NUM_THREADS 2

// Global variable to keep track of called numbers
bool calledNumbers[76] = {false};

// Global variable to keep track of the winning pattern
bool winningPattern[ROWS][COLS] = {
    {true, true, true, true, true}, // Full House
    {true, true, true, true, false}, // Horizontal line
    {false, true, true, true, true}, // Horizontal line
    {true, false, true, false, true}, // Diagonal line
    {true, false, false, false, true} // Diamond
};

// Struct to pass arguments to the thread function
struct ThreadArgs {
    int tid; // Thread id
    int ticket[ROWS][COLS]; // Bingo ticket
};

// Function to generate a random number between min and max, both inclusive
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a 5x5 bingo ticket
void generateTicket(int ticket[ROWS][COLS]) {
    int nums[COLS]; // Array to store the current column's numbers
    bool used[COLS][15] = {false}; // 2D array to keep track of used numbers in each column

    // Generate each column of the ticket
    for (int i = 0; i < COLS; i++) {
        // Generate 5 unique numbers for the column
        for (int j = 0; j < ROWS; j++) {
            do {
                nums[j] = getRandomNumber(i * 15 + 1, i * 15 + 15);
            } while (used[i][nums[j] - i * 15 - 1]);
            used[i][nums[j] - i * 15 - 1] = true;
            ticket[j][i] = nums[j];
        }
    }

    // Mark the middle cell as 'FREE'
    ticket[ROWS / 2][COLS / 2] = 0;
}

// Function to print the bingo ticket
void printTicket(int ticket[ROWS][COLS]) {
    printf("BINGO TICKET\n");
    printf("-------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%-3d", ticket[i][j]);
        }
        printf("\n");
    }
    printf("-------------\n");
}

// Function to check if a ticket has the winning pattern
bool checkWinningPattern(int ticket[ROWS][COLS]) {
    bool hasWon = false;

    // Check each winning pattern
    for (int i = 0; i < ROWS; i++) {
        bool winning = true;

        for (int j = 0; j < COLS; j++) {
            if (winningPattern[i][j] && !calledNumbers[ticket[i][j]]) {
                winning = false;
                break;
            }
        }

        if (winning) {
            hasWon = true;
            break;
        }
    }

    return hasWon;
}

// Function to call a random number
int callNumber() {
    int num;
    do {
        num = getRandomNumber(1, 75);
    } while (calledNumbers[num]);
    calledNumbers[num] = true;
    printf("Number called: %d\n", num);
    return num;
}

// Thread function to play the game
void *playBingo(void *args) {
    struct ThreadArgs *threadArgs = (struct ThreadArgs *)args;
    int *tid = &threadArgs->tid;
    int ticket[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            ticket[i][j] = threadArgs->ticket[i][j];
        }
    }

    // Play the game
    while(!checkWinningPattern(ticket)) {
        int num = callNumber();

        // Check the ticket for the called number
        bool found = false;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (ticket[i][j] == num) {
                    found = true;
                    ticket[i][j] = -1;
                    break;
                }
            }
            if (found) break;
        }

        // Print the updated ticket
        printf("\nTicket for thread %d\n", *tid);
        printTicket(ticket);
        printf("-------------\n");

        // Delay for 1 second
        usleep(1000000);
    }

    printf("BINGO! Thread %d has won!\n", *tid);
    return NULL;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate two bingo tickets
    int ticket1[ROWS][COLS], ticket2[ROWS][COLS];
    generateTicket(ticket1);
    generateTicket(ticket2);

    // Print the tickets
    printf("Bingo Ticket for Thread 1:\n");
    printTicket(ticket1);
    printf("\nBingo Ticket for Thread 2:\n");
    printTicket(ticket2);
    printf("Press Enter to start the game...");
    getchar();

    // Create two threads to play the game
    pthread_t threads[NUM_THREADS];
    struct ThreadArgs threadArgs[NUM_THREADS];
    threadArgs[0].tid = 1;
    threadArgs[1].tid = 2;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            threadArgs[0].ticket[i][j] = ticket1[i][j];
            threadArgs[1].ticket[i][j] = ticket2[i][j];
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, playBingo, (void *)&threadArgs[i]);
    }

    // Wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("GAME OVER!\n");

    return 0;
}