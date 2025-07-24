//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: real-life
#include <stdio.h>

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int count = 0;
    int num = 2; //start with 2 since it is the first prime number
    printf("Here are the first 50 prime numbers: \n");

    while (count < 50) {
        if (is_prime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }

    printf("\n");
    return 0;
}