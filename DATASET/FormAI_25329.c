//FormAI DATASET v1.0 Category: Pattern printing ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int size;
    printf("Enter size of pattern: ");
    scanf("%d", &size);

    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {

            if (i%2 == 0) {
                if (j%2 == 0) {
                    printf("+");
                } else {
                    printf("*");
                }
            } else {
                if (j%2 == 0) {
                    printf("*");
                } else {
                    printf("+");
                }
            }

        }
        printf("\n");
    }

    return 0;
}