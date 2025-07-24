//FormAI DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>

#define SIZE 10 // Size of the pattern

int main(){
    int pattern[SIZE][SIZE] = {0}; // Initializing the pattern with zeroes
    
    //Adding the first line of the pattern
    for(int i=0; i<SIZE; i++){
        pattern[0][i] = 1;
    }
    
    //Adding the diagonal part of the pattern
    for(int i=1; i<SIZE; i++){
        for(int j=0; j<i; j++){
            pattern[i][j] = pattern[i-1][j+1];
        }
    }
    
    //Adding the remaining part of the pattern
    for(int i=SIZE-2; i>=0; i--){
        for(int j=SIZE-i-2; j<SIZE; j++){
            pattern[i][j] = pattern[i+1][j-1];
        }
    }
    
    //Printing the pattern
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            if(pattern[i][j] == 1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}