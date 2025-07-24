//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: Claude Shannon
/* Welcome to the Bingo Simulator program! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define TOTAL_NUMBERS 25

/* Function to generate a random number within the given range */
int randomNumber(int min, int max){
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

/* Function to print the bingo card */
void printBingoCard(int arr[ROWS][COLS]){
    printf("\n\n\n");
    printf("********** BINGO CARD **********\n");
    printf("________________________________\n");
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(arr[i][j] == -1)
                printf("|   X   ");
            else
                printf("|  %2d   ", arr[i][j]);
        }
        printf("|\n");
        printf("________________________________\n");
    }
}

int main(){
    int bingo_card[ROWS][COLS];
    int numbers[TOTAL_NUMBERS];
    int current_number = 0;
    int row, col;
    char check;

    srand(time(0));     // Seed the random number generator

    /* Initialize the bingo card and numbers array */
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            bingo_card[i][j] = -1;
        }
    }
    for(int i=0; i<TOTAL_NUMBERS; i++){
        numbers[i] = i+1;
    }

    /* Shuffle the numbers */
    for(int i = TOTAL_NUMBERS-1; i >= 0; i--){
        int j = randomNumber(0, i);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    /* Fill in the bingo card */
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            bingo_card[i][j] = numbers[current_number++];
        }
    }

    /* Print the bingo card */
    printBingoCard(bingo_card);

    /* Loop until the user chooses to exit */
    do {
        /* Generate a new random number */
        int new_number = randomNumber(1, TOTAL_NUMBERS);

        /* Mark the number on the bingo card */
        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++){
                if(bingo_card[i][j] == new_number){
                    bingo_card[i][j] = -1;
                }
            }
        }

        /* Print the new bingo card */
        printBingoCard(bingo_card);

        /* Prompt the user to continue or exit */
        printf("\n\nTo continue playing, press any key. To exit press 'q'\n");
        scanf(" %c", &check);

    } while (check != 'q');

    printf("\n\nThank you for playing the Bingo Simulator!\n\n");

    return 0;
}