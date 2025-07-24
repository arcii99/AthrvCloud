//FormAI DATASET v1.0 Category: Pattern printing ; Style: surrealist
#include <stdio.h>

int main() {
    // surreal variable declarations
    int a = 1, b = 3, c = 4, d = 6;
    
    // surreal for loop structure
    for(int i = 1; i <= 10; i++) {
        for(int j = 1; j <= 10; j++) {
            // surreal if-else condition
            if(i % 2 == 0) {
                if(j == a || j == b || j == c) {
                    printf("*");
                } else {
                    printf(" ");
                }
            } else {
                if(j == d) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        // surreal newline statement
        printf("\n");
        // surreal variable manipulation
        a++;
        b+=2;
        c++;
        d+=2;
    }
    return 0;
}