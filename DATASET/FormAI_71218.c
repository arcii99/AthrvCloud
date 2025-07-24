//FormAI DATASET v1.0 Category: Table Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int table[5][5] = {0};
    int num, row, col;

    printf("Welcome to the Game\n");

    while(1) {
        num = rand() % 25 + 1;
        printf("The Number is: %d\n", num);

        //check if the number is already present in the table
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(table[i][j] == num) {
                    printf("The Number is already present in the table\n");
                    goto end;
                }
            }
        }

        //put the number in the table
        if(num <= 5) { //in the first row
            row = 0;
            col = num-1;
        } else if(num <= 10) { //in the second row
            row = 1;
            col = num-6;
        } else if(num <= 15) { //in the third row
            row = 2;
            col = num-11;
        } else if(num <= 20) { //in the fourth row
            row = 3;
            col = num-16;
        } else { //in the fifth row
            row = 4;
            col = num-21;
        }

        table[row][col] = num; //place the number in the table

        //print the table
        printf("Current Table:\n\n");
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(table[i][j] == 0) {
                    printf("__ ");
                } else {
                    printf("%2d ", table[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");

        //check if the game is finished
        int count=0;
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(table[i][j] != 0) {
                    count++;
                }
            }
        }
        if(count == 25) {
            printf("Congratulations! You have won the Game\n");
            break;
        }

        end:
        printf("\n");

    }

    return 0;
}