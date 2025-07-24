//FormAI DATASET v1.0 Category: Memory Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int* arr, int n);
void print_board(int board[], int size);
void swap(int* a, int* b);

int main(void) {
    // Initialize board
    int board[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int size = sizeof(board)/sizeof(board[0]);
    shuffle(board, size); // Shuffle board

    // Game loop
    int selection1, selection2, temp;
    int num_matches = 0;
    while (num_matches < 8) { // Game ends after 8 matches have been found
        printf("\n");
        print_board(board, size);
        printf("\nSelect your first card: ");
        scanf("%d", &selection1);
        printf("Select your second card: ");
        scanf("%d", &selection2);

        // Ensure valid selections
        while ((selection1 < 0 || selection1 >= size || selection2 < 0 || selection2 >= size) || (selection1 == selection2)) {
            printf("Invalid selection. Please try again.\n");
            printf("Select your first card: ");
            scanf("%d", &selection1);
            printf("Select your second card: ");
            scanf("%d", &selection2);
        }

        // Swap selected cards
        swap(&board[selection1], &board[selection2]);

        // Check for match
        if (board[selection1] == board[selection2]) {
            num_matches++;
            printf("\nMatch found!\n");
        } else {
            // If no match, swap back to previous arrangement
            swap(&board[selection1], &board[selection2]);
            printf("\nNo match found.\n");
        }
    }

    printf("\nCongratulations, you have matched all pairs!\n");

    return 0;
}

// Shuffle array
void shuffle(int* arr, int n) {
    srand(time(NULL));
    for (int i = n-1; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

// Print formatted board
void print_board(int board[], int size) {
    for (int i = 0; i < size; i++) {
        if (board[i] < 10) {
            printf("%d  ", board[i]);
        } else {
            printf("%d ", board[i]);
        }
        if ((i+1) % 4 == 0) {
            printf("\n");
        }
    }
}

// Swap values
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}