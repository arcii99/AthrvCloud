//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void fillCard(int card[ROWS][COLS]) {
    int i, j;
    srand(time(NULL));
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(i == 2 && j == 2) {
                card[i][j] = 0;
            }
            else {
                int num;
                do {
                    num = rand() % 15 + 1 + j * 15;
                } while(numExists(num, card, i, j));
                card[i][j] = num;
            }
        }
    }
}

void displayCard(int card[ROWS][COLS]) {
    int i, j;
    printf("---------------------\n");
    printf("| B  | I  | N  | G  | O  |\n");
    for(i = 0; i < ROWS; i++) {
        printf("---------------------\n|");
        for(j = 0; j < COLS; j++) {
            if(card[i][j] < 10) {
                printf(" ");
            }
            if(card[i][j] == 0) {
                printf(" F |");
            }
            else {
                printf(" %d |", card[i][j]);
            }
        }
        printf("\n");
    }
    printf("---------------------\n");
}

int numExists(int num, int card[ROWS][COLS], int current_row, int current_col) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(card[i][j] == num && (i != current_row || j != current_col)) {
                return 1;
            }
        }
    }
    return 0;
}

int marked(int num, int card[ROWS][COLS], int mark[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(card[i][j] == num) {
                mark[i][j] = 1;
                return 1;
            }
        }
    }
    return 0;
}

int checkRow(int row, int card[ROWS][COLS], int mark[ROWS][COLS]) {
    int i;
    for(i = 0; i < COLS; i++) {
        if(!mark[row][i]) {
            return 0;
        }   
    }
    return 1;
}

int checkCol(int col, int card[ROWS][COLS], int mark[ROWS][COLS]) {
    int i;
    for(i = 0; i < ROWS; i++) {
        if(!mark[i][col]) {
            return 0;
        }
    }
    return 1;
}

int checkDiagonal1(int card[ROWS][COLS], int mark[ROWS][COLS]) {
    int i;
    for(i = 0; i < ROWS; i++) {
        if(!mark[i][i]) {
            return 0;
        }
    }
    return 1;
}

int checkDiagonal2(int card[ROWS][COLS], int mark[ROWS][COLS]) {
    int i;
    for(i = 0; i < ROWS; i++) {
        if(!mark[i][COLS - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int checkWin(int card[ROWS][COLS], int mark[ROWS][COLS]) {
    int i;
    for(i = 0; i < ROWS; i++) {
        if(checkRow(i, card, mark) || checkCol(i, card, mark)) {
            return 1;
        }
    }
    if(checkDiagonal1(card, mark) || checkDiagonal2(card, mark)) {
        return 1;
    }
    return 0;
}

int main() {
    int i, j, num;
    int card[ROWS][COLS];
    int mark[ROWS][COLS] = {0};
    fillCard(card);
    displayCard(card);
    while(1) {
        printf("Enter a number from 1 to 75, or 0 to exit: ");
        scanf("%d", &num);
        if(num == 0) {
            break;
        }
        if(num < 1 || num > 75) {
            printf("Invalid input.\n");
            continue;
        }
        if(marked(num, card, mark)) {
            printf("Marked %d.\n", num);
        }
        else {
            printf("%d is not on your card.\n", num);
        }
        if(checkWin(card, mark)) {
            printf("BINGO! You won!\n");
            break;
        }
    }
    return 0;
}