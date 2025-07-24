//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 500
#define COL 500

int main(){
    int i,j,k, start, end;
    double A[ROW][COL], B[ROW][COL], C[ROW][COL];
    srand(time(NULL));

    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            A[i][j] = (double)(rand() % 10000)/10000.0;
            B[i][j] = (double)(rand() % 10000)/10000.0;
            C[i][j] = 0.0;
        }
    }

    start = clock();
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            for(k = 0; k < ROW; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    end = clock();
    printf("Time taken for multiplication: %.9lf seconds", (double)(end - start)/CLOCKS_PER_SEC);
    return 0;
}