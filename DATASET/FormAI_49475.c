//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the bingo game
#define SIZE 5
#define MAX_NUM 25

// Define function prototypes
void fill_card(int card[SIZE][SIZE]);
void print_card(int card[SIZE][SIZE]);
int generate_call(int called_nums[MAX_NUM]);
int check_bingo(int card[SIZE][SIZE], int called_nums[MAX_NUM]);

int main(void) {
    // Seed random number generator
    srand(time(NULL));

    // Define array to track called numbers
    int called_nums[MAX_NUM] = {0};

    // Generate and fill bingo card
    int card[SIZE][SIZE] = {0};
    fill_card(card);

    // Print bingo card
    printf("Your Bingo Card:\n");
    print_card(card);

    // Play bingo game
    int num_calls = 0;
    int bingo = 0;
    while (!bingo) {
        // Generate random bingo number
        int call = generate_call(called_nums);
        printf("Bingo call: %d\n", call);
  
        // Check if number is on card and mark if present
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                if (card[row][col] == call) {
                    card[row][col] = 0;
                    printf("Number found on card!\n");
                }
            }
        }

        // Check for bingo
        bingo = check_bingo(card, called_nums);

        // Increment number of calls
        num_calls++;
    }

    // Print final results
    printf("\nBINGO!\n");
    printf("Number of calls: %d\n", num_calls);

    return 0;
}

// Function to fill bingo card with random numbers
void fill_card(int card[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            // Ensure number is not already on card
            int num = rand() % MAX_NUM + 1;
            int flag = 1;
            while (flag) {
                flag = 0;
                for (int i = 0; i < SIZE; i++) {
                    for (int j = 0; j < SIZE; j++) {
                        if (num == card[i][j]) {
                            num = rand() % MAX_NUM + 1;
                            flag = 1;
                        }
                    }
                }
            }

            card[row][col] = num;
        }
    }
}

// Function to print bingo card
void print_card(int card[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%2d ", card[row][col]);
        }
        printf("\n");
    }
}

// Function to generate random call that has not already been called
int generate_call(int called_nums[MAX_NUM]) {
    int call = rand() % MAX_NUM + 1;
    while (called_nums[call-1]) {
        call = rand() % MAX_NUM + 1;
    }
    called_nums[call-1] = 1;
    return call;
}

// Function to check if bingo has been achieved
int check_bingo(int card[SIZE][SIZE], int called_nums[MAX_NUM]) {
    int bingo = 0;
    for (int row = 0; row < SIZE; row++) {
        // Check for horizontal bingo
        if (!card[row][0] && !card[row][1] && !card[row][2] && !card[row][3] && !card[row][4]) {
            bingo = 1;
            break;
        }

        // Check for vertical bingo
        if (!card[0][row] && !card[1][row] && !card[2][row] && !card[3][row] && !card[4][row]) {
            bingo = 1;
            break;
        }
    }

    // Check for diagonal bingo
    if ((!card[0][0] && !card[1][1] && !card[2][2] && !card[3][3] && !card[4][4]) ||
        (!card[0][4] && !card[1][3] && !card[2][2] && !card[3][1] && !card[4][0])) {
        bingo = 1;
    }

    return bingo;
}