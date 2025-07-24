//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUM 75

void printCard(int card[][COLS], int numCount[]) {
    printf("---------------------Bingo Card---------------------\n");
    printf("   B  I  N  G  O\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(j == 0) {
                printf("%2d", card[i][j]);
            } else {
                printf("%3d", card[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nNumber Count:\n");
    for(int i = 0; i < MAX_NUM; i++) {
        if(numCount[i]) {
            printf("%d: %d\n", i+1, numCount[i]);
        }
    }
}

void generateCard(int card[][COLS], int numCount[]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int num;
            do {
                num = rand() % MAX_NUM;
            } while(numCount[num] != 0);

            card[i][j] = num + 1;
            numCount[num] = 1;
        }
    }
}

int isBingo(int card[][COLS]) {
    // Check for row bingo
    for(int i = 0; i < ROWS; i++) {
        int count = 0;
        for(int j = 0; j < COLS; j++) {
            if(card[i][j] == -1) {
                count++;
            }
        }
        if(count == ROWS) {
            return 1;
        }
    }

    // Check for column bingo
    for(int i = 0; i < COLS; i++) {
        int count = 0;
        for(int j = 0; j < ROWS; j++) {
            if(card[j][i] == -1) {
                count++;
            }
        }
        if(count == COLS) {
            return 1;
        }
    }

    // Check for diagonal bingo
    int count1 = 0, count2 = 0;
    for(int i = 0; i < ROWS; i++) {
        if(card[i][i] == -1) {
            count1++;
        }
        if(card[i][COLS-i-1] == -1) {
            count2++;
        }
    }
    if(count1 == ROWS || count2 == ROWS) {
        return 1;
    }

    return 0;
}

int main() {
    srand(time(NULL));
    int card[ROWS][COLS];
    int numCount[MAX_NUM] = {0};
    int numDrawn[MAX_NUM] = {0};
    generateCard(card, numCount);
    printCard(card, numCount);

    int numDrawnCount = 0;
    while(1) {
        int num;
        do {
            num = rand() % MAX_NUM;
        } while(numDrawn[num]);

        numDrawn[num] = 1;
        numDrawnCount++;
        printf("Number Drawn: %d\n", num + 1);

        if(numCount[num]) {
            for(int i = 0; i < ROWS; i++) {
                for(int j = 0; j < COLS; j++) {
                    if(card[i][j] == num + 1) {
                        card[i][j] = -1;
                        break;
                    }
                }
            }
        }
        printf("\n");
        printCard(card, numCount);
        if(isBingo(card)) {
            printf("Bingo!!\n");
            break;
        }
    }

    printf("Total numbers drawn: %d\n", numDrawnCount);

    return 0;
}