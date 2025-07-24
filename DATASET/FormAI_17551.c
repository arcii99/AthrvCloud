//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: retro
#include <stdio.h>

int main() {
    int num, i, count;

    printf("Enter the number of prime numbers you want to generate: ");
    scanf("%d", &num);

    printf("\nThe first %d prime numbers are: ", num);

    for (i = 2; num > 0; i++) {
        count = 0;
        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                count++;
                break;
            }
        }
        if (count == 0) {
            printf("%d ", i);
            num--;
        }
    }

    printf("\n");

    return 0;
}