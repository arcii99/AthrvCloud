//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //set random seed
    int arr[5][5]; //declare array
    int nums[25]; //declare nums array
    int i,j,k; //declare counters
    int bingo = 0; //flag for winning
    int number; //for storing random number
    char response; //for asking to play again
    
    printf("Welcome to Bingo Simulator!\n");
    printf("-----------------------------\n");

    do {
        //initialize array
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                arr[i][j] = 0;
            }
        }
        
        //populate nums array
        for (i = 0; i < 25; i++) {
            nums[i] = i+1;
        }

        //shuffle nums array
        for (i = 0; i < 25; i++) {
            j = rand() % 25;
            k = nums[i];
            nums[i] = nums[j];
            nums[j] = k;
        }

        //generate bingo board
        printf("B  I  N  G  O\n");
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (i == 2 && j == 2) {
                    arr[i][j] = -1;
                    printf("   ");
                    continue;
                }
                arr[i][j] = nums[(i*5)+j];
                printf("%d  ", arr[i][j]);
            }
            printf("\n");
        }

        //play bingo
        while (!bingo) {
            printf("\nEnter a number between 1 and 25: ");
            scanf("%d", &number);

            //check if number is on board
            for (i = 0; i < 5; i++) {
                for (j = 0; j < 5; j++) {
                    if (arr[i][j] == number) {
                        arr[i][j] = -1;
                        break;
                    }
                }
            }

            //check for bingo
            if ((arr[0][0] == -1 && arr[1][1] == -1 && arr[2][2] == -1 && arr[3][3] == -1 && arr[4][4] == -1) ||
            (arr[0][4] == -1 && arr[1][3] == -1 && arr[2][2] == -1 && arr[3][1] == -1 && arr[4][0] == -1)) {
                bingo = 1;
                printf("\nBINGO! You won!\n");
            } else {
                bingo = 1;
                for (i = 0; i < 5; i++) {
                    for (j = 0; j < 5; j++) {
                        if (arr[i][j] != -1) {
                            bingo = 0;
                            break;
                        }
                    }
                }
                if (bingo) {
                    printf("\nBINGO! You won!\n");
                }
            }
        }

        //ask to play again
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &response);
        printf("\n");
        
    } while (response == 'y' || response == 'Y');
    
    printf("\nThanks for playing Bingo Simulator!\n");
    
    return 0;
}