//FormAI DATASET v1.0 Category: Educational ; Style: automated
#include <stdio.h>

// function for computing factorial
int factorial(int n){
    if(n == 0) return 1;
    else return n * factorial(n-1);
}

// function for computing n choose k
int n_choose_k(int n, int k){
    return factorial(n) / (factorial(k) * factorial(n-k));
}

// function for generating pascal's triangle
void pascal(int rows){
    int i, j, space;
    for(i=0; i<rows; i++){
        for(space=0; space<rows-i; space++){
            printf(" ");
        }
        for(j=0; j<=i; j++){
            printf("%d ", n_choose_k(i, j));
        }
        printf("\n");
    }
}

int main(){
    int rows;
    printf("Enter the number of rows in Pascal's Triangle: ");
    scanf("%d", &rows);
    pascal(rows);

    return 0;
}