//FormAI DATASET v1.0 Category: Pattern printing ; Style: happy
#include <stdio.h>

int main() {
    printf("Hooray! Let's print a cool pattern in C!\n");

    int rows = 5;
    int columns = 10;

    printf("\nHere we go!\n\n");

    for(int i = 1; i <= rows; i++) {
        for(int j = 1; j <= columns; j++) {
            if(i==1 || i==rows || j==1 || j==columns) {
                printf("*");
            }
            else if(i%2==0 && j%2==0) {
                printf("&");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\nTa-da! This pattern is amazing!\n");

    return 0;
}