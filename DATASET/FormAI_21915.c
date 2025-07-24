//FormAI DATASET v1.0 Category: Table Game ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int levels, i, j, k=1;
    printf("Welcome to the Puzzling Table Game!\n\n");
    printf("How many levels would you like to play? (Choose between 3 and 10): ");
    scanf("%d", &levels);
    printf("\n");

    //Creating the array
    int arr[levels][levels];

    // Generating random numbers and filling the array
    srand(time(NULL));
    for(i=0; i<levels; i++) {
        for(j=0; j<levels; j++) {
            arr[i][j] = rand()%1001;
        }
    }

    //Printing the array in a table form
    printf("This is your Puzzling Table Game Board:\n");
    printf("----------------------------------------\n");
    for(i=0; i<levels; i++) {
        for(j=0; j<levels; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------------\n");

    //Player instructions
    printf("\nNow it's your turn to guess which number is missing in the table!\n");
    printf("You will be given %d chances to guess.\n", levels);
    printf("If you guess correctly, you will move on to the next level.\n");
    printf("If you do not guess correctly, you will have to start again from the first level.\n");
    printf("Good luck!\n\n");

    //Main loop for the game
    while(1) {
        //Selecting the missing number and taking the player's guess
        int row = rand()%levels;
        int col = rand()%levels;
        int missingNum = arr[row][col];
        printf("Guess the missing number in row %d and column %d: ", row+1, col+1);
        int guess;
        scanf("%d", &guess);

        //Checking the player's guess and giving the appropriate output
        if(guess==missingNum) {
            printf("Congratulations! You have correctly guessed the missing number.\n");
            printf("Moving on to the next level...\n\n");
            k++;
            if(k>levels) {
                printf("You have completed all levels successfully! Congratulations!\n");
                break;
            }
        }
        else {
            printf("Sorry, that is incorrect. You will have to start again from level 1.\n");
            printf("Better luck next time!\n");
            break;
        }
    }
    return 0;
}