//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Board size and range of numbers
    int size = 5;
    int range = 25;

    //Generate random numbers for the board
    int board[size*size];
    srand(time(NULL));
    for(int i=0; i<size*size; i++){
        board[i] = rand() % range + 1;
    }

    //Display initial board
    printf("Welcome to Bingo Simulator!\n");
    printf("Here is your %dx%d board:\n", size, size);
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            printf("%3d ", board[i*size+j]);
        }
        printf("\n");
    }

    //Start the game
    int count = 0;
    int ball;
    int matches[size*size];
    for(int i=0; i<size*size; i++){
        matches[i] = 0;
    }
    while(count < size*size){
        printf("\nEnter the next ball number (1-%d): ", range);
        scanf("%d", &ball);
        if(ball < 1 || ball > range){
            printf("Invalid input, please try again.");
            continue;
        }
        int found = 0;
        for(int i=0; i<size*size; i++){
            if(board[i] == ball && matches[i] == 0){
                matches[i] = 1;
                found = 1;
                count++;
                break;
            }
        }
        if(found == 0){
            printf("Sorry, that number is not on the board. Try again.\n");
            continue;
        }
        printf("You have %d numbers left to match.\n", size*size-count);
        printf("Here is your updated board:\n");
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                if(matches[i*size+j] == 1){
                    printf("%3s ", "X");
                }
                else{
                    printf("%3d ", board[i*size+j]);
                }
            }
            printf("\n");
        }
        //Check for bingo
        int row_sum, col_sum, diag_sum1, diag_sum2;
        row_sum = col_sum = diag_sum1 = diag_sum2 = 0;
        for(int i=0; i<size; i++){
            row_sum = col_sum = 0;
            for(int j=0; j<size; j++){
                row_sum += matches[i*size+j];
                col_sum += matches[j*size+i];
                if(i == j){
                    diag_sum1 += matches[i*size+j];
                }
                if(i == size-j-1){
                    diag_sum2 += matches[i*size+j];
                }
            }
            if(row_sum == size){
                printf("Bingo! You completed a row!\n");
            }
            if(col_sum == size){
                printf("Bingo! You completed a column!\n");
            }
        }
        if(diag_sum1 == size || diag_sum2 == size){
            printf("Bingo! You completed a diagonal!\n");
        }
    }
    printf("Congratulations, you completed the board!\n");

    return 0;
}