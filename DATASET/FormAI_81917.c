//FormAI DATASET v1.0 Category: Pattern printing ; Style: relaxed
#include <stdio.h>

int main() {
    int height, width, i, j, k;
    
    printf("Enter the height of C: ");
    scanf("%d", &height);
    
    width = height / 2 + 1;
    
    // Printing top part of C
    for(i = 1; i <= height; i++) {
        if(i == 1) {
            for(j = 1; j <= width; j++) {
                printf("*");
            }
            printf("\n");
        } else {
            printf("*");
            for(j = 1; j <= width; j++) {
                printf(" ");
            }
            printf("\n");
        }
    }
    
    // Printing middle part of C
    for(i = 1; i <= width - 1; i++) {
        for(j = 1; j <= i; j++) {
            printf(" ");
        }
        printf("*\n");
    }
    
    // Printing bottom part of C
    for(i = 1; i <= width; i++) {
        printf("*");
    }
    
    printf("\n");
    
    return 0;
}