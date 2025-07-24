//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: shocked
#include <stdio.h>

int main() {
    int num, i, flag;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num == 1) {
        printf("1 is not a prime number\n");
        return 0;
    }
    printf("The prime numbers between 1 and %d are:\n", num);
    for (i = 2; i <= num; i++) {
        flag = 1;
        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            printf("%d\n", i);
        }
    }
    return 0;
}