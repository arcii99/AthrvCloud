//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: enthusiastic
#include <stdio.h>

int main() {
    int num, check, flag;
    printf("Enter a number to check if it's prime: ");
    scanf("%d", &num);

    if(num == 1) {
        flag = 0;
    } else {
        for(int i = 2; i <= num/2; ++i) {
            if(num % i == 0) {
                flag = 0;
                break;
            }
        }
    }

    if(flag == 1) {
        printf("%d is a prime number.", num);
    } else {
        printf("%d is not a prime number.", num);
    }

    return 0;
}