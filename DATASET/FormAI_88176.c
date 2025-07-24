//FormAI DATASET v1.0 Category: Pattern printing ; Style: ephemeral
#include <stdio.h>

int main() {
    // First half of C Shape
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 || j == 0) {
                printf("*");
            } else if (i == 9 && j >= 1) {
                printf("*");
            } else if (i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    // Second half of C Shape
    for (int i = 10; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 19 || j == 0) {
                printf("*");
            } else if (i == j+10) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}