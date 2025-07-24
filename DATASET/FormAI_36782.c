//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[5][5];
int numArr[75];
int calledNums[75];
int currNum = 0;
int isWinner = 0;

void init_board(){
    int i, j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            board[i][j] = 0;
        }
    }
}

void print_board(){
    int i, j;
    printf("\nBINGO BOARD\n");
    printf("------------\n");
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(board[i][j] == 0){
                printf("|_ _ _ _ _ |");
            } else {
                printf("|_%02d_", board[i][j]);
                if(board[i][j] < 10){
                    printf("_ _|");
                } else {
                    printf(" _|");
                }
            }
        }
        printf("\n");
    }
}

void generate_num_array(){
    int i;
    for(i = 0; i < 75; i++){
        numArr[i] = i + 1;
    }
}

void shuffle_num_array(){
    int i, j, temp;
    srand(time(0));
    for(i = 0; i < 75; i++){
        j = rand() % 75;
        temp = numArr[i];
        numArr[i] = numArr[j];
        numArr[j] = temp;
    }
}

int check_for_winner(){
    int i, j, count;
    // Check rows
    for(i = 0; i < 5; i++){
        count = 0;
        for(j = 0; j < 5; j++){
            if(board[i][j] != 0){
                count++;
            }
        }
        if(count == 5){
            isWinner = 1;
            return isWinner;
        }
    }
    // Check cols
    for(i = 0; i < 5; i++){
        count = 0;
        for(j = 0; j < 5; j++){
            if(board[j][i] != 0){
                count++;
            }
        }
        if(count == 5){
            isWinner = 1;
            return isWinner;
        }
    }
    // Check diagonals
    if(board[0][0] != 0 && board[1][1] != 0 && board[2][2] != 0 && board[3][3] != 0 && board[4][4] != 0){
        isWinner = 1;
        return isWinner;
    }
    if(board[0][4] != 0 && board[1][3] != 0 && board[2][2] != 0 && board[3][1] != 0 && board[4][0] != 0){
        isWinner = 1;
        return isWinner;
    }
    return isWinner;
}

void call_num(){
    if(currNum < 75){
        printf("\nNumber called: %d\n", numArr[currNum]);
        calledNums[currNum] = numArr[currNum];
        int i, j;
        for(i = 0; i < 5; i++){
            for(j = 0; j < 5; j++){
                if(board[i][j] == numArr[currNum]){
                    board[i][j] = 0;
                    break;
                }
            }
        }
        currNum++;
    }
}

void play_bingo(){
    generate_num_array();  
    shuffle_num_array();
    init_board();
    int i, j;

    while(!isWinner && currNum < 75){
        call_num();
        print_board();
        check_for_winner();
    }

    if(isWinner){
        printf("\n\nBINGO!!! Congratulations, you won!\n");
    } else {
        printf("\n\nSorry, better luck next time.\n");
    }
    printf("List of called numbers:\n");
    for(i = 0; i < currNum; i++){
        printf("%d ", calledNums[i]);
        if((i+1) % 10 == 0){
            printf("\n");
        }
    }
}

int main(){
    printf("Welcome to Bingo Simulator\n\n");
    play_bingo();
    return 0;
}