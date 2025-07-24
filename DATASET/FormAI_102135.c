//FormAI DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>
#define N 8

void printBoard(char arr[][N]);
void initializeBoard(char arr[][N]);

int main() {
    char board[N][N];
    initializeBoard(board);
    printBoard(board);
    return 0;
}

void initializeBoard(char arr[][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((i+j)%2==0) {
                if (i < 3) {
                    arr[i][j] = 'O';
                }
                else if (i > 4) {
                    arr[i][j] = 'X';
                }
                else {
                    arr[i][j] = ' ';
                }
            }
            else {
                arr[i][j] = ' ';
            }
        }
    }
}

void printBoard(char arr[][N]) {
    int i, j;
    printf("   1  2  3  4  5  6  7  8\n");
    for (i = 0; i < N; i++) {
        printf("%d ",i+1);
        for (j = 0; j < N; j++) {
            printf("[%c]",arr[i][j]);
        }
        printf("\n");
    }
}