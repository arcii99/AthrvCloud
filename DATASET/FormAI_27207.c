//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: visionary
#include <stdio.h>

int main() {
    int num, i, flag;

    printf("Enter a number:");
    scanf("%d", &num);

    if (num <= 1) {
        printf("Prime numbers start from 2. Please enter a number greater than 1\n");
        return 0;
    }

    printf("The prime numbers between 1 and %d are:\n", num);

    for (i = 2; i <= num; i++) {
        flag = 0;

        for (int j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}