//FormAI DATASET v1.0 Category: Memory Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 16

void shuffle(int *nums, int size);
void printBoard(int *board, int size);
int getUserInput(int *board, int size);
void checkMatch(int *board, int size, int first, int second);

int main()
{
    int nums[MAX_SIZE/2], board[MAX_SIZE];
    srand(time(NULL));

    // Populate nums array with numbers 1 to 8
    for (int i = 0; i < MAX_SIZE/2; i++) {
        nums[i] = i+1;
    }

    // Shuffle nums array to get random order
    shuffle(nums, MAX_SIZE/2);

    // Copy shuffled nums array into board array twice
    for (int i = 0; i < MAX_SIZE; i+=2) {
        board[i] = board[i+1] = nums[i/2];
    }

    // Shuffle board array to get random order
    shuffle(board, MAX_SIZE);

    // Print board to screen
    printBoard(board, MAX_SIZE);

    // Keep track of number of turns taken
    int turns = 0;

    // Loop until all pairs have been found
    while(1) {
        // Get two positions from user and check for match
        checkMatch(board, MAX_SIZE, getUserInput(board, MAX_SIZE), getUserInput(board, MAX_SIZE));
        turns++;
        // Print updated board to screen
        printBoard(board, MAX_SIZE);
        // Check if all pairs have been found
        int pairsFound = 1;
        for (int i = 0; i < MAX_SIZE; i++) {
            if (board[i] != 0) {
                pairsFound = 0;
                break;
            }
        }
        if (pairsFound) {
            printf("Congratulations, you won in %d turns!\n", turns);
            break;
        }
    }

    return 0;
}

// Function to shuffle an array
void shuffle(int *nums, int size)
{
    for (int i = size-1; i > 0; i--) {
        int j = rand() % (i+1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

// Function to print board to screen
void printBoard(int *board, int size)
{
    for (int i = 0; i < size; i++) {
        if (board[i] == 0) {
            printf("[ ] ");
        } else {
            printf("[%d] ", board[i]);
        }
        if ((i+1) % 4 == 0) {
            printf("\n");
        }
    }
}

// Function to get user input for position on board
int getUserInput(int *board, int size)
{
    int pos;
    do {
        printf("Enter position on board (1-%d): ", size);
        scanf("%d", &pos);
        if (!((pos >= 1) && (pos <= size)) || (board[pos-1] == 0)) {
            printf("Invalid input, please try again.\n");
        } else {
            break;
        }
    } while(1);
    return pos-1;
}

// Function to check if there is a match at two positions on board
void checkMatch(int *board, int size, int first, int second)
{
    if (board[first] == board[second]) {
        printf("Match found!\n");
        board[first] = board[second] = 0;
    } else {
        printf("No match found.\n");
    }
}