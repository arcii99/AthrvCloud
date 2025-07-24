//FormAI DATASET v1.0 Category: Pattern printing ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Hello, let's print a C Pattern!\n");
    for(int i=0; i<6; i++) {
        for(int j=0; j<6; j++) {
            if(i == 0 || i == 5) { // printing * for first and last row
                printf("* ");
            }
            else if(j == 0 || j == 5) { // printing * for first and last column
                printf("* ");
            }
            else if(j == i) { // printing * for diagonal elements
                printf("* ");
            }
            else { // printing space for other elements
                printf("  ");
            }
        }
        printf("\n"); // moving to next line
    }
    printf("C Pattern printing complete!");
    return 0;
}