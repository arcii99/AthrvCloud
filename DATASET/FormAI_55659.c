//FormAI DATASET v1.0 Category: Memory Game ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 16
#define MAX_GUESSES 8

void display_board(int values[], int visible[], int guess_idx);
int check_guess(int values[], int visible[], int guess_idx, int guess1, int guess2);
void clear_input_buffer();
void wait_for_input();

int main() {
    int values[SIZE], visible[SIZE];
    int guess1, guess2, guess_idx = 0;
    int guesses_left = MAX_GUESSES;
    int matched_pairs = 0;
    
    srand(time(NULL));
    
    // Initialize game board
    for (int i = 0; i < SIZE; i++) {
        values[i] = i / 2;
        visible[i] = 0;
    }
    
    // Shuffle board
    for (int i = 0; i < SIZE; i++) {
        int temp = values[i];
        int j = rand() % SIZE;
        values[i] = values[j];
        values[j] = temp;
    }
    
    // Game loop
    while (matched_pairs < 8 && guesses_left > 0) {
        display_board(values, visible, guess_idx);
        printf("Guesses left: %d\n", guesses_left);
        printf("Enter two numbers between 0 and 15 (inclusive) separated by a space: ");
        scanf("%d %d", &guess1, &guess2);
        
        if (guess1 < 0 || guess1 > 15 || guess2 < 0 || guess2 > 15) {
            clear_input_buffer();
            printf("Invalid input. Please try again.\n");
            wait_for_input();
            continue;
        }
            
        int result = check_guess(values, visible, guess_idx, guess1, guess2);
        
        if (result == 1) {
            printf("Match!\n");
            matched_pairs++;
        } else if (result == -1) {
            printf("Sorry, those numbers do not match.\n");
            guesses_left--;
        }
        
        guess_idx++;
        wait_for_input();
    }
    
    if (matched_pairs == 8) {
        printf("Congratulations, you won!\n");
    } else {
        printf("Sorry, you ran out of guesses. Better luck next time.\n");
    }
    
    return 0;
}

void display_board(int values[], int visible[], int guess_idx) {
    printf("\n");
    printf("+----+----+----+----+\n");
    for (int i = 0; i < SIZE; i++) {
        if (i % 4 == 0) {
            printf("+\n");
            printf("| ");
        }
        
        if (visible[i] == 1 || i == guess_idx * 2 || i == guess_idx * 2 + 1) {
            printf("%-2d ", values[i]);
        } else {
            printf("## ");
        }
    }
    printf("+\n");
    printf("+----+----+----+----+\n");
}

int check_guess(int values[], int visible[], int guess_idx, int guess1, int guess2) {
    visible[guess1] = 1;
    visible[guess2] = 1;
    
    if (values[guess1] == values[guess2]) {
        return 1;
    } else {
        return -1;
    }
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void wait_for_input() {
    printf("Press Enter to continue...");
    clear_input_buffer();
    getchar();
}