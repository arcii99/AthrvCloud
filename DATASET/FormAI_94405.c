//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, num;
    int bingo[5][5];
    int counter[12] = {0};
    int diagonal_ltr = 0, diagonal_rtl = 0, horizontal = 0, vertical = 0; 
    
    // Initialize bingo card with random numbers between 1 and 75
    srand(time(NULL));
    for(i=0; i<5; i++) {
        for(j=0; j<5; j++) {
            num = rand() % 75 + 1;
            // Check if number is already in the array
            for(int k=0; k<j; k++) {
                if(bingo[i][k] == num) {
                    num = rand() % 75 + 1;
                    k = -1;
                }
            }
            bingo[i][j] = num;
            printf("%2d ", bingo[i][j]);
        }
        printf("\n");
    }
    
    // Game Loop
    while(1) {
        int flag = 0;
        int sel_num = rand() % 75 + 1;
        
        // Check if selected number has already been called
        for(i=0; i<12; i++) {
            if(counter[i] == sel_num) {
                flag = 1;
                break;
            }
        }
        
        // If number has not been called, update grid and check for winner
        if(!flag) {
            for(i=0; i<5; i++) {
                for(j=0; j<5; j++) {
                    if(bingo[i][j] == sel_num) {
                        bingo[i][j] = 0;
                        printf("Number %d selected!\n", sel_num);
                    }
                }
            }
            
            // Check for diagonal win
            if(bingo[0][0] == 0 && bingo[1][1] == 0 && bingo[2][2] == 0 && bingo[3][3] == 0 && bingo[4][4] == 0) {
                printf("Diagonal win!\n");
                break;
            }
            if(bingo[0][4] == 0 && bingo[1][3] == 0 && bingo[2][2] == 0 && bingo[3][1] == 0 && bingo[4][0] == 0) {
                printf("Diagonal win!\n");
                break;
            }
            
            // Check for horizontal win
            for(i=0; i<5; i++) {
                for(j=0; j<5; j++) {
                    if(bingo[i][j] == 0) {
                        horizontal++;
                    }
                }
                if(horizontal == 5) {
                    printf("Horizontal win!\n");
                    break;
                }
                horizontal = 0;
            }
            
            // Check for vertical win
            for(i=0; i<5; i++) {
                for(j=0; j<5; j++) {
                    if(bingo[j][i] == 0) {
                        vertical++;
                    }
                }
                if(vertical == 5) {
                    printf("Vertical win!\n");
                    break;
                }
                vertical = 0;
            }
            
            counter[i] = sel_num;
        }
    }
    
    return 0;
}