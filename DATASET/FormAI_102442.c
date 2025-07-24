//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: dynamic
#include <stdio.h>

int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int main() {
    // get user input for minimum and maximum allowable prime number
    int min_num, max_num;
    printf("Enter the minimum value: ");
    scanf("%d", &min_num);
    printf("Enter the maximum value: ");
    scanf("%d", &max_num);

    // generate prime numbers within the range and print them out
    printf("Prime numbers between %d and %d are: ", min_num, max_num);
    for (int i = min_num; i <= max_num; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}