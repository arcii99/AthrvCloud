//FormAI DATASET v1.0 Category: Table Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

int main(){

    char table[ROWS][COLS] = {
        {'1', '2', '3'}, 
        {'4', '5', '6'}, 
        {'7', '8', '9'}
    };

    char p1 = 'X', p2 = 'O';
    int player = 1, row, col, win = 0;
    srand(time(NULL));

    printf("\n\tWelcome to the Tic Tac Toe Game!\n");

    // Game loop
    while(1){

        // Print the table
        printf("\n\t    %c  |  %c  |  %c  ", table[0][0], table[0][1], table[0][2]);
        printf("\n\t-------|-------|-------");
        printf("\n\t    %c  |  %c  |  %c  ", table[1][0], table[1][1], table[1][2]);
        printf("\n\t-------|-------|-------");
        printf("\n\t    %c  |  %c  |  %c  \n\n", table[2][0], table[2][1], table[2][2]);

        // Check if there is a winner
        if((table[0][0] == p1 && table[0][1] == p1 && table[0][2] == p1) || 
           (table[1][0] == p1 && table[1][1] == p1 && table[1][2] == p1) ||
           (table[2][0] == p1 && table[2][1] == p1 && table[2][2] == p1) ||
           (table[0][0] == p1 && table[1][0] == p1 && table[2][0] == p1) ||
           (table[0][1] == p1 && table[1][1] == p1 && table[2][1] == p1) ||
           (table[0][2] == p1 && table[1][2] == p1 && table[2][2] == p1) ||
           (table[0][0] == p1 && table[1][1] == p1 && table[2][2] == p1) ||
           (table[0][2] == p1 && table[1][1] == p1 && table[2][0] == p1)){

            printf("\n\tPlayer 1 wins the game!\n");
            win = 1;
            break;
        }
        else if((table[0][0] == p2 && table[0][1] == p2 && table[0][2] == p2) || 
                (table[1][0] == p2 && table[1][1] == p2 && table[1][2] == p2) ||
                (table[2][0] == p2 && table[2][1] == p2 && table[2][2] == p2) ||
                (table[0][0] == p2 && table[1][0] == p2 && table[2][0] == p2) ||
                (table[0][1] == p2 && table[1][1] == p2 && table[2][1] == p2) ||
                (table[0][2] == p2 && table[1][2] == p2 && table[2][2] == p2) ||
                (table[0][0] == p2 && table[1][1] == p2 && table[2][2] == p2) ||
                (table[0][2] == p2 && table[1][1] == p2 && table[2][0] == p2)){

            printf("\n\tPlayer 2 wins the game!\n");
            win = 1;
            break;
        }
        else if(table[0][0] != '1' && table[0][1] != '2' && table[0][2] != '3' && 
                table[1][0] != '4' && table[1][1] != '5' && table[1][2] != '6' &&
                table[2][0] != '7' && table[2][1] != '8' && table[2][2] != '9'){

            printf("\n\tThe game is a draw!\n");
            win = 1;
            break;
        }

        // Player's turn
        if(player == 1){

            printf("\n\tPlayer 1 (X) turn: ");

            do{
                printf("\n\tEnter the row number (1 - 3): ");
                scanf("%d", &row);
                printf("\tEnter the column number (1 - 3): ");
                scanf("%d", &col);
            }while(table[row-1][col-1] == p1 || table[row-1][col-1] == p2 || row < 1 || row > 3 || col < 1 || col > 3);

            table[row-1][col-1] = p1;
            player = 2;
        }
        else{
            
            printf("\n\tPlayer 2 (O) turn: ");

            do{
                row = rand() % 3;
                col = rand() % 3;
            }while(table[row][col] == p1 || table[row][col] == p2);

            table[row][col] = p2;
            player = 1;
        }
    }

    return 0;
}