//FormAI DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>

int main() {
    int rows = 7, i, j, k, l, m;
    // Define number of rows
    
    for(i = 1; i <= rows; i++) {
        for(j = 1; j <= i; j++) {
            printf("*"); // Print stars
        }
        
        for(k = 1; k <= (rows-i)*2; k++) {
            printf(" "); // Print spaces
        }
        
        for (l = 1; l <= i; l++) {
            printf("*"); // Print stars
        }
        printf("\n");
    }
    
    for(i = rows-1; i >= 1; i--) {
        for(j = 1; j <= i; j++) {
            printf("*"); // Print stars
        }
        for(k = 1; k <= (rows-i)*2; k++) {
            printf(" "); // Print spaces
        }
        for (l = 1; l <= i; l++) {
            printf("*"); // Print stars
        }
        printf("\n");
    }
    
    for(m = 1; m <= rows; m++) {
        printf(" "); // Print spaces before the center row
    }
    printf("*"); // Print the center row
    
    for(m = 1; m <= rows; m++) {
        printf(" "); // Print spaces after the center row
    }
    printf("\n");
    
    for (i = rows-1; i >= 1; i--) {
        for(m = 1; m <= i; m++) {
            printf(" "); // Print spaces
        }
        for(j = i; j <= rows; j++) {
            printf("*"); // Print stars
        }
        for(k = 1; k <= (rows-i)*2; k++) {
            printf(" "); // Print spaces
        }
        for (l = i; l <= rows; l++) {
            printf("*"); // Print stars
        }
        printf("\n");
    }
    
    return 0;
}