//FormAI DATASET v1.0 Category: Fractal Generation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int MAX_ROW = 40;
    int MAX_COL = 100;
    int array[MAX_ROW][MAX_COL];
    int row, col, i, j;

    srand(time(NULL));
    for(i=0; i<MAX_ROW; i++){
        for(j=0; j<MAX_COL; j++){
            array[i][j] = rand()%2;
        }
    }

    for(i=0; i<MAX_ROW; i++){
        for(j=0; j<MAX_COL; j++){
            if(array[i][j]==1){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}