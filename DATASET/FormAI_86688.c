//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MIN_NUM 1
#define MAX_NUM 75

int generateRandomNum(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

int checkDuplicate(int num, int *arr, int size){
    for(int i=0; i<size; i++){
        if(arr[i] == num){
            return 1;
        }
    }
    return 0;
}

void generateBingoCard(int card[ROWS][COLS]){
    int numbers[ROWS*COLS];
    int index;
    int num;

    for(int i=0; i<(ROWS*COLS); i++){
        numbers[i] = -1;
    }

    srand(time(NULL));

    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            index = i*COLS + j;
            do{
                num = generateRandomNum(MIN_NUM, MAX_NUM);
            }while(checkDuplicate(num, numbers, index));

            numbers[index] = num;

            if(j == 2 && i == 2){
                card[i][j] = 0;
            }
            else{
                card[i][j] = num;
            }
        }
    }
}

int checkBingo(int card[ROWS][COLS]){
    int row, col;
    int diag1 = 0, diag2 = 0;

    for(row=0; row<ROWS; row++){
        int rowCount = 0;
        for(col=0; col<COLS; col++){
            if(card[row][col] == 0){
                rowCount++;
            }
        }
        if(rowCount == 5){
            return 1;
        }
    }

    for(col=0; col<COLS; col++){
        int colCount = 0;
        for(row=0; row<ROWS; row++){
            if(card[row][col] == 0){
                colCount++;
            }
        }
        if(colCount == 5){
            return 1;
        }
    }

    for(int i=0; i<ROWS; i++){
        if(card[i][i] == 0){
            diag1++;
        }
        if(card[i][ROWS-1-i] == 0){
            diag2++;
        }
    }

    if(diag1 == 5 || diag2 == 5){
        return 1;
    }

    return 0;
}

void printCard(int card[ROWS][COLS]){
    printf("\n\n");

    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(card[i][j] == 0){
                printf(" X ");
            }
            else{
                printf(" %2d", card[i][j]);
            }
        }
        printf("\n");
    }

    printf("\n\n");
}

int main(){
    int card[ROWS][COLS];

    generateBingoCard(card);
    printCard(card);

    printf("Press enter to start the game!");

    getchar();

    int num;
    int count = 0;

    while(!checkBingo(card)){
        count++;
        printf("\n\nEnter the next number (1-75): ");
        scanf("%d", &num);
        getchar();

        if(num < 1 || num > 75){
            printf("\n\nInvalid number!\n");
            continue;
        }

        for(int i=0; i<ROWS; i++){
            for(int j=0; j<COLS; j++){
                if(card[i][j] == num){
                    card[i][j] = 0;
                    printCard(card);
                }
            }
        }
    }

    printf("\n\nBINGO! It took you %d tries!\n\n", count);

    return 0;
}