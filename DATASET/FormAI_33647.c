//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include <stdio.h>

int main() {
    int height;

    printf("Enter the height of C (minimum 4): ");
    scanf("%d", &height);

    if(height < 4) {
        printf("Minimum height requirement not met.\n");
    } else {
        printf("\n");
        for(int i = 1; i <= height; i++) {
            for(int j = 1; j <= height / 2; j++) {
                if(i == 1 || i == height || j == 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}