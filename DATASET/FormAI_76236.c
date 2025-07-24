//FormAI DATASET v1.0 Category: Pattern printing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // configuration
    int size = 5; // the size of the pattern (number of rows)
    char symbol = '*'; // the symbol used to draw the pattern
    
    // pattern drawing
    for(int i = 1; i <= size; i++){
        
        // draw spaces
        for(int j = i; j < size; j++){
            printf(" ");
        }
        
        // draw symbols
        for(int k = 1; k <= i; k++){
            printf("%c ", symbol);
        }
        
        printf("\n");
    }
    
    // bonus: pattern flipping
    printf("\nFlipped pattern:\n");
    for(int i = size; i >= 1; i--){
        
        // draw spaces
        for(int j = i; j < size; j++){
            printf(" ");
        }
        
        // draw symbols
        for(int k = 1; k <= i; k++){
            printf("%c ", symbol);
        }
        
        printf("\n");
    }
    
    return 0;
}