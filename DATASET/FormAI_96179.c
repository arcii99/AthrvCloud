//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int n);

int main() {
    int i, j, count, num, bingo[5][5], player[5][5], winner;
    
    srand(time(0));
    
    // Generate Bingo Card
    printf("Your Bingo Card:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (i == 2 && j == 2) { // Center square is always free
                bingo[i][j] = 0;
                printf("   ");
            } else {
                num = rand() % 75 + 1; // 1-75
                for (count = 0; count < j; count++) { // Check for repeats in row
                    if (bingo[i][count] == num) {
                        num = rand() % 75 + 1;
                        count = -1;
                    }
                }
                bingo[i][j] = num;
                printf("%2d ", num);
            }
        }
        printf("\n");
    }
    printf("\n");
    
    // Shuffle Bingo Numbers
    int bingo_nums[75];
    for (i = 0; i < 75; i++) {
        bingo_nums[i] = i + 1;
    }
    shuffle(bingo_nums, 75);
    
    // Play Game
    printf("Game Starting!\n");
    winner = 0;
    for (i = 0; i < 75; i++) {
        printf("Next Number: %d\n", bingo_nums[i]);
        
        // Check for number on player's card and mark if found
        for (j = 0; j < 5; j++) {
            for (count = 0; count < 5; count++) {
                if (bingo[j][count] == bingo_nums[i]) {
                    player[j][count] = 1;
                }
            }
        }
        
        // Check for winner
        for (j = 0; j < 5; j++) {
            if ((player[j][0] == 1 && player[j][1] == 1 && player[j][2] == 1 && player[j][3] == 1 && player[j][4] == 1) || 
                (player[0][j] == 1 && player[1][j] == 1 && player[2][j] == 1 && player[3][j] == 1 && player[4][j] == 1) ||
                (player[0][0] == 1 && player[1][1] == 1 && player[2][2] == 1 && player[3][3] == 1 && player[4][4] == 1) ||
                (player[0][4] == 1 && player[1][3] == 1 && player[2][2] == 1 && player[3][1] == 1 && player[4][0] == 1)) {
                winner = 1;
                break;
            }
        }
        
        if (winner) {
            printf("BINGO!!! Congratulations, you're the winner!!!");
            break;
        } else {
            printf("Continue playing...\n");
        }
    }
    
    if (!winner) {
        printf("Sorry, no winner this time. Better luck next time!\n");
    }
    
    return 0;
}

// Fisher-Yates Shuffle Algorithm
void shuffle(int *array, int n) {
    int i, j, temp;
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}