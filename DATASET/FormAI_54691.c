//FormAI DATASET v1.0 Category: Memory Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, k, temp, count = 0;
    printf("Enter the size of game board (n x n): ");
    scanf("%d", &n);

    int board[n][n], flipped[n][n];

    srand(time(NULL));
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            board[i][j] = rand() % (n*n/2);
            flipped[i][j] = 0; //0 = unflipped, 1 = flipped
        }
    }

    //shuffle the game board
    for(i=0; i<n*n; i++){
        int r1 = rand() % n;
        int r2 = rand() % n;
        int c1 = rand() % n;
        int c2 = rand() % n;
        temp = board[r1][c1];
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = temp;
    }

    //play the game
    int row1, col1, row2, col2, match;
    do{
        printf("\n------------------------------\n");
        match = 0;
        count++;
        printf("Move #%d\n", count);

        //display flipped values
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                if(flipped[i][j] == 1){
                    printf("%2d ", board[i][j]);
                }
                else{
                    printf("*  ");
                }
                
            }
            printf("\n");
        }

        //get user input
        printf("Enter the row and column of first card (example: 1 2): ");
        scanf("%d %d", &row1, &col1);
        while(flipped[row1-1][col1-1] == 1){
            printf("That card has already been flipped. Please enter a different card: ");
            scanf("%d %d", &row1, &col1);
        }
        flipped[row1-1][col1-1] = 1;
        printf("Enter the row and column of second card (example: 1 2): ");
        scanf("%d %d", &row2, &col2);
        while(flipped[row2-1][col2-1] == 1 || (row1 == row2 && col1 == col2)){
            printf("That card has already been flipped or it is the same as the first card. Please enter a different card: ");
            scanf("%d %d", &row2, &col2);
        }
        flipped[row2-1][col2-1] = 1;

        //check for a match
        if(board[row1-1][col1-1] == board[row2-1][col2-1]){
            printf("\nMatch found!\n");
            match = 1;
        }
        else{
            printf("\nNo match found\n");
        }
        
        //pause for a moment
        for(k=0; k<200000000; k++){
            ;
        }

        //clear the screen
        system("clear");

    }while(match == 0);

    printf("\n------------------------------\n");
    printf("Congrats! You have completed the game in %d moves.\n", count);

    return 0;
}