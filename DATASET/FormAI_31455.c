//FormAI DATASET v1.0 Category: Matrix operations ; Style: recursive
#include <stdio.h>
#define ROWS 3
#define COLS 3
void addition(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS], int row, int col){
    if(row >= ROWS){
        return;
    }
    if(col >= COLS){
        addition(a,b,result,row+1,0);
        return;
    }
    result[row][col] = a[row][col] + b[row][col];
    addition(a,b,result,row,col+1);
}

void subtraction(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS], int row, int col){
    if(row >= ROWS){
        return;
    }
    if(col >= COLS){
        subtraction(a,b,result,row+1,0);
        return;
    }
    result[row][col] = a[row][col] - b[row][col];
    subtraction(a,b,result,row,col+1);
}
void multiplication(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS], int row, int col){
    if(row >= ROWS){
        return;
    }
    if(col >= COLS){
        multiplication(a,b,result,row+1,0);
        return;
    }
    result[row][col] = 0;
    int i;
    for(i=0;i<COLS;i++){
        result[row][col] += a[row][i]*b[i][col];
    }
    multiplication(a,b,result,row,col+1);
}

int main(){
    int i,j;
    int a[ROWS][COLS] = {{1,2,3},{4,5,6},{7,8,9}};
    int b[ROWS][COLS] = {{10,11,12},{13,14,15},{16,17,18}};
    int add_result[ROWS][COLS];
    int sub_result[ROWS][COLS];
    int mul_result[ROWS][COLS];

    addition(a,b,add_result,0,0);
    subtraction(a,b,sub_result,0,0);
    multiplication(a,b,mul_result,0,0);

    printf("Matrix A:\n");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }

    printf("\nA + B:\n");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            printf("%d ",add_result[i][j]);
        }
        printf("\n");
    }

    printf("\nA - B:\n");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            printf("%d ",sub_result[i][j]);
        }
        printf("\n");
    }

    printf("\nA * B:\n");
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            printf("%d ",mul_result[i][j]);
        }
        printf("\n");
    }

    return 0;
}