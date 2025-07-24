//FormAI DATASET v1.0 Category: Pattern printing ; Style: creative
#include <stdio.h>

int main(){

    int height, width, i, j, k, l;
    
    printf("Enter the height: ");
    scanf("%d", &height);
    
    while(height<1 || height>26){ // Checking if height is within range
        printf("Please enter a height between 1 and 26: ");
        scanf("%d", &height);
    }
    
    width = height*2-1; // Calculating width based on height
    
    l = height-1; // Setting initial values for k and l
    
    for(i=0; i<height; i++){ // Loop for printing top half of the pattern
        for(j=0; j<width; j++){
            if(j==l+i || j==l-i){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    l--; // Decreasing l for second half of pattern
    
    for(i=0; i<height-1; i++){ // Loop for printing bottom half of pattern
        for(j=0; j<width; j++){
            if(j==l-i || j==l+i){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}