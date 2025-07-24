//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printCard(int card[][5]) {
    printf("B    I    N    G    O\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i == 2 && j == 2) {
                printf("    ");
            } else {
                printf("%-4d ", card[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int numbers[75], pickedNums[75] = {0};
    int card[5][5] = {0};
    int bingo = 0, num, count = 0;

    // Populate array with numbers 1-75
    for(int i = 0; i < 75; i++) {
        numbers[i] = i + 1;
    }

    // Shuffle the numbers array
    srand(time(NULL));
    for(int i = 0; i < 75; i++) {
        int j = rand() % 75;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Fill in the bingo card
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(i == 2 && j == 2) {
                continue;
            } else {
                card[i][j] = numbers[count];
                count++;
            }
        }
    }

    // Print out the starting card
    printCard(card);

    // Loop until there is a bingo
    while(!bingo) {
        printf("Enter the next number (1-75): ");
        scanf("%d", &num);

        // Check if the number has already been picked
        if(pickedNums[num-1] == 1) {
            printf("That number has already been picked, please enter a different number.\n");
            continue;
        } else {
            pickedNums[num-1] = 1;
        }

        // Check if the number is on the bingo card
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(card[i][j] == num) {
                    card[i][j] = 0;
                }
            }
        }

        // Print out the updated card
        printCard(card);

        // Check for a bingo
        bingo = 1;
        for(int i = 0; i < 5; i++) {
            // Check rows
            if(card[i][0] * card[i][1] * card[i][2] * card[i][3] * card[i][4] == 0) {
                printf("Bingo! Row %d\n", i+1);
                bingo = 0;
            }
            // Check columns
            if(card[0][i] * card[1][i] * card[2][i] * card[3][i] * card[4][i] == 0) {
                printf("Bingo! Column %d\n", i+1);
                bingo = 0;
            }
        }
        // Check diagonals
        if(card[0][0] * card[1][1] * card[3][3] * card[4][4] == 0) {
            printf("Bingo! Diagonal from top left to bottom right\n");
            bingo = 0;
        }
        if(card[0][4] * card[1][3] * card[3][1] * card[4][0] == 0) {
            printf("Bingo! Diagonal from top right to bottom left\n");
            bingo = 0;
        }
    }

    return 0;
}