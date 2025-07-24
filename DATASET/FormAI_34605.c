//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: intelligent
#include<stdio.h>

int main() {
    int num, i, flag;
    printf("Enter a number to check for prime: ");
    scanf("%d", &num);
    if (num == 1 || num == 0) {
        printf("%d is not a prime number", num);
    } else {
        flag = 0;
        for (i = 2; i <= num / 2; ++i) {
            if (num % i == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("%d is a prime number", num);
        else
            printf("%d is not a prime number", num);
    }
    return 0;
}