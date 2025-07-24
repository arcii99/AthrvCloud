//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Claude Shannon
/* 
Claude Shannon-style Bingo Simulator Example Program
Minimum 50 lines
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 5    // Number of rows on Bingo card
#define COLS 5    // Number of columns on Bingo card
#define MAX_NUM 75 // Maximum number drawn during game

void generate_card(int card[ROWS][COLS]);
void print_card(int card[ROWS][COLS]);
int draw_number(int numbers_drawn[MAX_NUM]);
int check_bingo(int card[ROWS][COLS], int numbers_drawn[MAX_NUM]);

int main() {
    int numbers_drawn[MAX_NUM];  // Array to hold drawn numbers
    int player_card[ROWS][COLS]; // Bingo card for player
    int computer_card[ROWS][COLS]; // Bingo card for computer
    int num_drawn = 0;  // Number of numbers drawn
    int player_bingo = 0;  // Player's Bingo status
    int computer_bingo = 0;  // Computer's Bingo status
    
    srand(time(NULL)); // Initialize random number generator
    
    printf("Welcome to the Bingo Simulator!\n");
    printf("Generating player card...\n");
    generate_card(player_card);
    printf("Player card:\n");
    print_card(player_card);
    
    printf("Generating computer card...\n");
    generate_card(computer_card);
    
    while (num_drawn < MAX_NUM && !player_bingo && !computer_bingo) {
        int num = draw_number(numbers_drawn);
        printf("Number drawn: %d\n", num);
        numbers_drawn[num_drawn] = num;
        num_drawn++;
        
        printf("Player card:\n");
        print_card(player_card);
        player_bingo = check_bingo(player_card, numbers_drawn);
        if (player_bingo) {
            printf("Bingo! You win!\n");
            break;
        }
        
        printf("Computer card:\n");
        print_card(computer_card);
        computer_bingo = check_bingo(computer_card, numbers_drawn);
        if (computer_bingo) {
            printf("Computer got bingo! You lose!\n");
            break;
        }
    }
    
    if (!player_bingo && !computer_bingo) {
        printf("Sorry, no one got bingo. It's a tie!\n");
    }
    
    return 0;
}

// Generate a random Bingo card
void generate_card(int card[ROWS][COLS]) {
    int i, j;
    int used_nums[MAX_NUM] = {0};
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int num;
            do {
                num = rand() % MAX_NUM + 1;
            } while (used_nums[num-1]);
            used_nums[num-1] = 1;
            card[i][j] = num;
        }
    }
    
    card[ROWS/2][COLS/2] = 0;  // Set center to free space
}

// Print out a Bingo card
void print_card(int card[ROWS][COLS]) {
    int i, j;
    
    printf("-----------------------\n");
    for (i = 0; i < ROWS; i++) {
        printf("| ");
        for (j = 0; j < COLS; j++) {
            printf("%02d ", card[i][j]);
            printf("| ");
        }
        printf("\n");
        printf("-----------------------\n");
    }
}

// Draw a random number that hasn't been drawn before
int draw_number(int numbers_drawn[MAX_NUM]) {
    int num;
    do {
        num = rand() % MAX_NUM + 1;
    } while (numbers_drawn[num-1]);
    return num;
}

// Check if a Bingo card has achieved Bingo
// Return 1 for Bingo, 0 for no Bingo
int check_bingo(int card[ROWS][COLS], int numbers_drawn[MAX_NUM]) {
    int i, j;
    int bingo = 0;
    
    // Check rows
    for (i = 0; i < ROWS; i++) {
        int row_bingo = 1;
        for (j = 0; j < COLS; j++) {
            if (card[i][j] != 0 && !numbers_drawn[card[i][j]-1]) {
                row_bingo = 0;
                break;
            }
        }
        if (row_bingo) {
            bingo = 1;
            break;
        }
    }
    
    // Check columns
    if (!bingo) {
        for (j = 0; j < COLS; j++) {
            int col_bingo = 1;
            for (i = 0; i < ROWS; i++) {
                if (card[i][j] != 0 && !numbers_drawn[card[i][j]-1]) {
                    col_bingo = 0;
                    break;
                }
            }
            if (col_bingo) {
                bingo = 1;
                break;
            }
        }
    }
    
    // Check diagonals
    if (!bingo) {
        int diag1_bingo = 1;
        int diag2_bingo = 1;
        for (i = 0; i < ROWS; i++) {
            if (card[i][i] != 0 && !numbers_drawn[card[i][i]-1]) {
                diag1_bingo = 0;
            }
            if (card[i][COLS-i-1] != 0 && !numbers_drawn[card[i][COLS-i-1]-1]) {
                diag2_bingo = 0;
            }
        }
        if (diag1_bingo || diag2_bingo) {
            bingo = 1;
        }
    }
    
    return bingo;
}