//FormAI DATASET v1.0 Category: Pattern printing ; Style: bold
#include <stdio.h>
#define HEIGHT 15
#define WIDTH 15

int main(){
    int row, col;

    // Top Half of C
    for(row = 1; row <= HEIGHT/2; row++){
        for(col = 1; col <= WIDTH; col++){
            if(col == 1){
                printf("**");
            } else if(row == 1 && col > 1 && col < WIDTH - 1){
                printf("**");
            } else if(row == row && col == WIDTH - 1){
                printf("**");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // Bottom Half of C
    for(row = HEIGHT/2; row <= HEIGHT; row++){
        for(col = 1; col <= WIDTH; col++){
            if(col == 1){
                printf("**");
            } else if(row == HEIGHT/2 && col > 1 && col < WIDTH - 1){
                printf("**");
            } else if(row == row && col == WIDTH - 1){
                printf("**");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}