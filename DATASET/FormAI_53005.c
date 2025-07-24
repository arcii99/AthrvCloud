//FormAI DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16

void shuffle(int arr[]);
void print(int arr[], int idx1, int idx2);
int check(int arr[], int idx1, int idx2);
void update(int arr[], int idx1, int idx2);

int main(void) {
    int arr[SIZE];
    time_t t;

    // Seed the random number generator
    srand((unsigned) time(&t));

    // Initialize the array with unique numbers
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = i + 1;
    }

    // Shuffle the array
    shuffle(arr);

    // Print the initial state of the game board
    print(arr, -1, -1);

    // Main game loop
    int idx1, idx2;
    while (1) {
        // Prompt the user for their move
        printf("Enter the index of two cards you would like to flip (e.g. 1 2): ");
        scanf("%d %d", &idx1, &idx2);
        idx1--, idx2--; // Convert to 0-based indexing

        // Check the user's move for validity
        if (idx1 < 0 || idx1 >= SIZE || idx2 < 0 || idx2 >= SIZE || idx1 == idx2) {
            printf("Invalid move. Please enter two distinct indices.\n");
            continue;
        }
        if (check(arr, idx1, idx2)) {
            printf("Congratulations! You found a match.\n");
            update(arr, idx1, idx2);
        } else {
            printf("Sorry, those cards don't match.\n");
        }

        // Print the updated state of the game board
        print(arr, idx1, idx2);

        // Check if the game has been won
        int count = 0;
        for (int i = 0; i < SIZE; ++i) {
            if (arr[i] == 0) {
                count++;
            }
        }
        if (count == SIZE) {
            printf("Congratulations! You won the game!\n");
            break;
        }
    }

    return 0;
}

// Shuffles the array using a Fisher-Yates shuffle algorithm
void shuffle(int arr[]) {
    for (int i = SIZE - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Prints the current state of the game board
void print(int arr[], int idx1, int idx2) {
    printf("\nCurrent state of game board:\n");
    for (int i = 0; i < SIZE; ++i) {
        if (i == idx1 || i == idx2) {
            printf("[%2d] ", arr[i]);
        } else if (arr[i] == 0) {
            printf("[  ] ");
        } else {
            printf("[XX] ");
        }
        if (i % 4 == 3) {
            printf("\n");
        }
    }
    printf("\n");
}

// Checks if the two cards at the given indices match
int check(int arr[], int idx1, int idx2) {
    return arr[idx1] == arr[idx2];
}

// Updates the game board by removing the matched cards
void update(int arr[], int idx1, int idx2) {
    arr[idx1] = 0;
    arr[idx2] = 0;
}