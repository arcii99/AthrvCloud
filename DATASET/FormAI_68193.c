//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>

int main() {
    printf("Let's print a unique C pattern!\n\n");
    
    int rows = 10;
    int cols = 10;
    
    // Top
    for (int i = 0; i < cols; i++) {
        printf("C ");
    }
    printf("\n");
    
    // Middle
    for (int i = 1; i < rows - 1; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == 0 || j == (cols - 1)) {
                printf("C ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    // Bottom
    for (int i = 0; i < cols; i++) {
        printf("C ");
    }
    printf("\n\nWow, that pattern looks awesome!\n\n");
    return 0;
}