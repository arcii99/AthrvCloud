//FormAI DATASET v1.0 Category: Pattern printing ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printStar(){
    printf("\033[0;33m*\033[0m");
}

void printDash(){
    printf("\033[1;36m#\033[0m");
}

void printSpace(){
    printf("\033[1;37m.\033[0m");
}

int main() {
    srand(time(NULL));
    int width = 12;
    int height = 12;
    int pattern[width][height];
    int i, j;

    // Initialize the pattern
    for(i=0;i<width;i++){
        for(j=0;j<height;j++){
            pattern[i][j] = rand() % 3;
        }
    }

    // Print the pattern
    for(i=0;i<width;i++){
        for(j=0;j<height;j++){
            if(pattern[i][j] == 0){
                printStar();
            }
            else if(pattern[i][j] == 1){
                printDash();
            }
            else{
                printSpace();
            }
        }
        printf("\n");
    }

    return 0;
}