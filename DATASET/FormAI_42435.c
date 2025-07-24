//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int rows = 5, cols = 5;
    int max_num = 25, min_num = 1;
    int drawn_nums[25];
    int bingo_card[5][5] = {{0}};

    // Seed random num generator
    srand(time(NULL));

    // Fill bingo_card with random nums
    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            if(r==2 && c==2){
                 bingo_card[r][c] = -1;  // Free space
            }
            else{
                 bingo_card[r][c] = rand() % (max_num - min_num + 1) + min_num;
            }
        }
    }

    printf("Welcome to BINGO SIMULATOR!\n\n");

    // Display initial bingo card
    printf("   B   I   N   G   O\n");
    for(int r=0; r<rows; r++){
        printf("=====================\n");
        for(int c=0; c<cols; c++){
            if(bingo_card[r][c] == -1){
                printf("|Free");
            }
            else{
                printf("| %2d ", bingo_card[r][c]);
            }
        }
        printf("|\n");
    }
    printf("=====================\n\n");

    // Keep drawing nums until someone wins
    int turn = 1;
    while(1){
        printf("TURN %d\n", turn);
        int num = rand() % (max_num - min_num + 1) + min_num;

        // Check if num has already been drawn
        int already_drawn = 0;
        for(int i=0; i<max_num; i++){
            if(drawn_nums[i] == num){
                already_drawn = 1;
                printf("    %d has already been drawn\n", num);
                break;
            }
        }

        // If num hasn't been drawn, mark it off and check for winner
        if(!already_drawn){
            drawn_nums[num-1] = num;
            printf("    %d\n\n", num);

            // Mark num on bingo card
            int marked = 0;
            for(int r=0; r<rows; r++){
                for(int c=0; c<cols; c++){
                    if(bingo_card[r][c] == num){
                        bingo_card[r][c] = -1;
                        marked = 1;
                        break;
                    }
                }
                if(marked){
                    break;
                }
            }

            // Check for win
            int win = 0;
            int row_sum, col_sum, diag_sum1 = 0, diag_sum2 = 0;
            for(int r=0; r<rows; r++){
                row_sum = 0;
                for(int c=0; c<cols; c++){
                    row_sum += bingo_card[r][c];
                }
                if(row_sum == -5){
                    win = 1; // bingo
                    break;
                }
            }

            if(!win){
                for(int c=0; c<cols; c++){
                    col_sum = 0;
                    for(int r=0; r<rows; r++){
                        col_sum += bingo_card[r][c];
                    }
                    if(col_sum == -5){
                        win = 1; // bingo
                        break;
                    }
                }
            }

            if(!win){
                for(int i=0; i<rows; i++){
                    diag_sum1 += bingo_card[i][i];
                    diag_sum2 += bingo_card[i][rows-i-1];
                }
                if(diag_sum1 == -5 || diag_sum2 == -5){
                    win = 1; // bingo
                }
            }

            // If someone wins, end the game
            if(win){
                printf("\nBINGO! Someone won on turn %d!\n", turn);
                break;
            }
        }

        turn++;
    }

    return 0;
}