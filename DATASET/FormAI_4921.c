//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: romantic
#include <stdio.h>

int main() {
    int num, i, flag;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num == 1) {
        printf("1 is not a prime number.");
    }
    else {
        for (i = 2; i <= num/2; ++i) {
            flag = 0;

            if (num%i == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
            printf("%d is a prime number.", num);
        else
            printf("%d is not a prime number.", num);
    }

    return 0;
}