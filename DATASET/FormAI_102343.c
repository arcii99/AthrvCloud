//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLUMNS 5

int arr[ROWS][COLUMNS];

void displayCard() {
    int i, j;
    printf("\n----------------------\n");
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLUMNS; j++) {
            if (arr[i][j] != -1)
                printf(" %02d |", arr[i][j]);
            else
                printf(" ** |");
        }
        printf("\n----------------------\n");
    }
    return;
}

int checkHorizontal(int row) {
    int i;
    for (i = 0; i < COLUMNS; i++) {
        if (arr[row][i] != -1)
            return 0;
    }
    return 1;
}

int checkVertical(int column) {
    int i;
    for (i = 0; i < ROWS; i++) {
        if (arr[i][column] != -1)
            return 0;
    }
    return 1;
}

int checkDiagonal1() {
    int i;
    for (i = 0; i < ROWS; i++) {
        if (arr[i][i] != -1)
            return 0;
    }
    return 1;
}

int checkDiagonal2() {
    int i, j;
    for (i = 0, j = COLUMNS - 1; i < ROWS && j >= 0; i++, j--) {
        if (arr[i][j] != -1)
            return 0;
    }
    return 1;
}

int checkBingo() {
    int i, j, count = 0;
    for (i = 0; i < ROWS; i++) {
        if (checkHorizontal(i))
            count++;
    }
    for (i = 0; i < COLUMNS; i++) {
        if (checkVertical(i))
            count++;
    }
    if (checkDiagonal1())
        count++;
    if (checkDiagonal2())
        count++;
    return count;
}

void generateCard() {
    int i, j, k, flag, num;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            arr[i][j] = -1;
        }
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            flag = 1;
            while (flag) {
                num = rand() % 15 + 1 + (j * 15);
                flag = 0;
                for (k = 0; k < j; k++) {
                    if (arr[i][k] == num) {
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    arr[i][j] = num;
                }
            }
        }
    }
    arr[2][2] = -1;
    return;
}

void generateRandomNumber(int *num) {
    int flag, temp;
    while (1) {
        flag = 0;
        temp = rand() % 75 + 1;
        if (num[temp] == 1) {
            continue;
        }
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (arr[i][j] == temp) {
                    arr[i][j] = -1;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        num[temp] = 1;
        break;
    }
    return;
}

void simulateBingo() {
    int num[76] = { 0 };
    int count = 0;
    while (count < 5) {
        displayCard();
        int randomNumber;
        generateRandomNumber(num);
        printf("\nRandom number generated : %d\n", randomNumber);
        count = checkBingo();
        printf("\n\nNumber of lines completed : %d\n", count);
        if (count >= 5) {
            printf("\n\nBingo!!!");
            break;
        }
        printf("\nPress Enter for next number...");
        getchar();
        system("clear");
    }
    return;
}

int main() {
    srand(time(NULL));
    generateCard();
    simulateBingo();
    return 0;
}