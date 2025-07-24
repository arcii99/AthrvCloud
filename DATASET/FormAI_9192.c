//FormAI DATASET v1.0 Category: Pattern printing ; Style: minimalist
#include <stdio.h>

int main() {
    int height, width, i, j;
    printf("Enter height of pattern (must be an odd number): ");
    scanf("%d", &height);
    width = height;
 
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            if(i == (height / 2) || j == (width / 2)) { // Center of the pattern
                printf("*");
            } 
            else if(i == (j + 1) || (i + 1) == j) { // Diagonal
                printf("*");
            } 
            else if(i == 0 && j <= (width / 2) || j == 0 && i >= (height / 2)) { // Top half and left side
                printf("*");
            }
            else if(i == (height - 1) && j >= (width / 2) || j == (width - 1) && i <= (height / 2)) { // Bottom half and right side
                printf("*");
            } 
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}