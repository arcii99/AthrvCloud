//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int card[5][5], num[75], row, col, rand_num, count=0, result;
    srand(time(0)); 
    // Randomly filling the array with numbers between 1-75
    for(int i=0; i<75; i++)
        num[i] = i + 1;
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            card[i][j] = 0;
    // Assigning random numbers to the card
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++) {
            do {
                rand_num = rand() % 15;
                if(j == 2 && i == 2) //The center cell is always empty.
                    break;
            } while(num[rand_num + 15*j] == -1);
            card[i][j] = num[rand_num + 15*j];
            num[rand_num + 15*j] = -1;
        }
    printf("Welcome to Bingo Simulator!\n\n");
    //Printing the generated Bingo Card
    printf("Here's your Bingo Card:\n");
    for(int i=0; i<5; i++) {
        printf("\t");
        for(int j=0; j<5; j++) {
            if(card[i][j] == -1)
                printf("   ");
            else
                printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
    // Start of the game
    while(count < 25) {
        printf("\nEnter 0 to generate a new number: ");
        scanf("%d", &result);
        if(result != 0) {
            printf("\nInvalid input, Please enter 0 to generate a number or elements of the card.\n");
            continue;
        }
        srand(time(0));
        do {
            rand_num = rand() % 75 + 1;
            for(row=0; row<5; row++)
                for(col=0; col<5; col++)
                    if(card[row][col] == rand_num) {
                        card[row][col] = -1;
                        count++;
                    }
        } while(rand_num == 0 || num[rand_num - 1] == -1);
        num[rand_num - 1] = -1;
        //Printing the generated number and the updated card
        printf("\nGenerated Number: %d\n", rand_num);
        printf("Updated Bingo Card:\n");
        for(int i=0; i<5; i++) {
            printf("\t");
            for(int j=0; j<5; j++) {
                if(card[i][j] == -1)
                    printf("   ");
                else
                    printf("%2d ", card[i][j]);
            }
            printf("\n");
        }
        //If user matches all rows or column
        for(int i=0; i<5; i++) {
            if(card[i][0] == -1 && card[i][1] == -1 && card[i][2] == -1 && card[i][3] == -1 && card[i][4] == -1) {
                printf("\nBingo! You matched row %d\n", i+1);
                return 0;
            }
            if(card[0][i] == -1 && card[1][i] == -1 && card[2][i] == -1 && card[3][i] == -1 && card[4][i] == -1) {
                printf("\nBingo! You matched column %d\n", i+1);
                return 0;
            }
        }
        //If user matches diagonal elements
        if(card[0][0] == -1 && card[1][1] == -1 && card[2][2] == -1 && card[3][3] == -1 && card[4][4] == -1) {
            printf("\nBingo! You matched the primary diagonal!\n");
            return 0;
        }
        if(card[0][4] == -1 && card[1][3] == -1 && card[2][2] == -1 && card[3][1] == -1 && card[4][0] == -1) {
            printf("\nBingo! You matched the secondary diagonal!\n");
            return 0;
        }
    }
    printf("Game Over! You could not match any row, column or diagonal!\n");
    return 0;
}