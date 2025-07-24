//FormAI DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>

int main() {
    int rows, columns, i, j;
    printf("How many rows do you want in your pattern? ");
    scanf("%d", &rows);
    printf("How many columns do you want in your pattern? ");
    scanf("%d", &columns);

    int pattern[rows][columns];

    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            if(i==0 || i==rows-1){ //drawing the top and bottom rows of the pattern
                pattern[i][j] = 1;
            }
            else if(j==0 || j==columns-1){ //drawing the left and right columns of the pattern
                pattern[i][j] = 1;
            }
            else if(i==j || i+j==rows-1){ //drawing the diagonal lines of the pattern
                pattern[i][j] = 0;
            }
            else if(i<=2 || j<=2){ //drawing the first few rows and columns of the pattern
                pattern[i][j] = 2;
            }
            else if(i>=rows-3 || j>=columns-3){ //drawing the last few rows and columns of the pattern
                pattern[i][j] = 3;
            }
            else{ //filling the rest of the pattern with random numbers
                pattern[i][j] = rand()%10 + 1;
            }
        }
    }

    printf("\nHere is your pattern:\n");

    for(i=0;i<rows;i++){
        for(j=0;j<columns;j++){
            printf("%d ", pattern[i][j]);
        }
        printf("\n");
    }

    return 0;
}