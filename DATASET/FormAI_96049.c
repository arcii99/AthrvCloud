//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: medieval
#include <stdio.h>

int main() {
    int i, j, size;
    printf("Enter size of the square: ");
    scanf("%d", &size);

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            printf("X");
        }
        printf("\n");
    }

    return 0;
}