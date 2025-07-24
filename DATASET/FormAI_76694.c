//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void generate_board(int board[ROWS][COLS]){
    int nums_selected = 0;
    int max_nums = ROWS * COLS;

    while(nums_selected < max_nums){
        int num = (rand() % 75) + 1;
        int row = num / 15;
        if(num % 15 == 0){
            row--;
        }

        int col = -1;
        for(int i = 0; i < COLS; i++){
            if(board[row][i] == num){
                col = i;
                break;
            }
        }

        if(col == -1){
            int empty_found = 0;
            for(int i = 0; i < COLS; i++){
                if(board[row][i] == 0){
                    board[row][i] = num;
                    nums_selected++;
                    empty_found = 1;
                    break;
                }
            }

            if(!empty_found){
                continue;
            }
        }
    }
}

void print_board(int board[ROWS][COLS]){
    printf("-----------------------\n");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(board[i][j] == 0){
                printf("|   ");
            } else {
                printf("| %2d", board[i][j]);
            }
        }
        printf("|\n");
        printf("-----------------------\n");
    }
}

int check_bingo(int board[ROWS][COLS]){
    int found_bingo = 0;
    for(int i = 0; i < ROWS; i++){
        int bingo = 1;
        for(int j = 0; j < COLS; j++){
            if(board[i][j] > 0){
                bingo = 0;
                break;
            }
        }

        if(bingo){
            found_bingo = 1;
            break;
        }
    }

    if(!found_bingo){
        for(int i = 0; i < COLS; i++){
            int bingo = 1;
            for(int j = 0; j < ROWS; j++){
                if(board[j][i] > 0){
                    bingo = 0;
                    break;
                }
            }

            if(bingo){
                found_bingo = 1;
                break;
            }
        }
    }

    if(!found_bingo){
        int diagonal_1_bingo = 1;
        int diagonal_2_bingo = 1;
        for(int i = 0; i < ROWS; i++){
            if(board[i][i] > 0 || board[ROWS - i - 1][i] > 0){
                diagonal_1_bingo = 0;
            }

            if(board[i][COLS - i - 1] > 0 || board[ROWS - i - 1][COLS - i - 1] > 0){
                diagonal_2_bingo = 0;
            }
        }

        if(diagonal_1_bingo || diagonal_2_bingo){
            found_bingo = 1;
        }
    }

    return found_bingo;
}

int main(){
    srand(time(NULL));

    int board[ROWS][COLS] = {0};
    generate_board(board);

    printf("Welcome to the Mind-Bending Bingo Simulator!\n");
    printf("Your bingo card is:\n");
    print_board(board);

    int num_calls = 0;
    while(1){
        printf("Enter a number between 1 and 75 (or 0 to quit): ");
        int num;
        scanf("%d", &num);

        if(num == 0){
            printf("Thanks for playing!\n");
            return 0;
        }

        if(num < 1 || num > 75){
            printf("Invalid number.\n");
            continue;
        }

        int found = 0;
        for(int i = 0; i < ROWS; i++){
            for(int j = 0; j < COLS; j++){
                if(board[i][j] == num){
                    board[i][j] = 0;
                    found = 1;
                    break;
                }
            }

            if(found){
                break;
            }
        }

        if(found){
            printf("Number found!\n");
            print_board(board);
            num_calls++;

            if(check_bingo(board)){
                printf("Bingo! It took you %d calls to win!\n", num_calls);
                return 0;
            }
        } else {
            printf("Number not found.\n");
        }
    }

    return 0;
}