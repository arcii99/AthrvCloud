//FormAI DATASET v1.0 Category: Pattern printing ; Style: calm
#include <stdio.h>

int main(){
    int i, j, k;
    int n = 5; // Change this value to change the number of rows in the pattern
    int center = n / 2; // The center row of the pattern
    
    printf("Here's a C pattern printing example:\n\n");
    
    // Loop for the upper half of the pattern
    for(i = 0; i < center; i++){
        // Loop for printing spaces before the C
        for(j = 0; j < i; j++){
            printf(" ");
        }
        // Loop for printing the C
        for(k = 0; k < n - (2 * i); k++){
            if(k == 0 || k == n - (2 * i) - 1){
                printf("*");
            } else {
                printf(" ");
            }
        }
        // Move to the next line for the next row
        printf("\n");
    }
    
    // Loop for the center row of the pattern
    for(i = 0; i < n; i++){
        if(i == 0 || i == n-1){
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("\n");
    
    // Loop for the bottom half of the pattern
    for(i = center-1; i >= 0; i--){
        // Loop for printing spaces before the C
        for(j = i; j > 0; j--){
            printf(" ");
        }
        // Loop for printing the C
        for(k = n - (2 * i); k > 0; k--){
            if(k == 1 || k == n - (2 * i)){
                printf("*");
            } else {
                printf(" ");
            }
        }
        // Move to the next line for the next row
        printf("\n");
    }
    
    return 0;
}