//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10 //Size of Matrix
#define THRESHOLD 0.5 //Threshold probability for percolation to occur

int is_occupied[SIZE][SIZE]; //Array to track occupied cells

void print_matrix(int matrix[SIZE][SIZE]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int has_path(int matrix[SIZE][SIZE], int x1, int y1, int x2, int y2){
    if(x1<0 || x1>=SIZE || y1<0 || y1>=SIZE || x2<0 || x2>=SIZE || y2<0 || y2>=SIZE){
        return 0;
    }
    if(matrix[x1][y1] == 0 || matrix[x2][y2] == 0){
        return 0;
    }
    if(matrix[x1][y1] == 2 || matrix[x2][y2] == 2){
        return 1;
    }
    matrix[x1][y1] = 0;
    matrix[x2][y2] = 0;
    int up = has_path(matrix, x1-1, y1, x2-1, y2);
    int down = has_path(matrix, x1+1, y1, x2+1, y2);
    int left = has_path(matrix, x1, y1-1, x2, y2-1);
    int right = has_path(matrix, x1, y1+1, x2, y2+1);
    return up || down || left || right;
}

int main(){
    srand(time(0));
    int matrix[SIZE][SIZE];
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            float random_num = (float)rand()/(float)RAND_MAX;
            random_num < THRESHOLD ? (matrix[i][j] = 1) : (matrix[i][j] = 0);
            is_occupied[i][j] = 0;
        }
    }
    
    int percolated = 0;
    for(int i=0; i<SIZE; i++){
        if(has_path(matrix, 0, i, SIZE-1, i)){
            percolated = 1;
            break;
        }
    }

    if(percolated){
        printf("Matrix percolated with threshold probability %f\n", THRESHOLD);
    }
    else{
        printf("Matrix did not percolate with threshold probability %f\n", THRESHOLD);
    }
    
    printf("Matrix:\n");
    print_matrix(matrix);
    return 0;
}