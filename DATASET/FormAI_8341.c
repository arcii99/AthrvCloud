//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: scientific
#include <stdio.h>

int is_prime(int num) {
    int i;
    for(i=2; i<=num/2; i++) {
        if(num%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int num, i;
    printf("Enter a number to find prime numbers upto: ");
    scanf("%d", &num);
    printf("Prime numbers upto %d are: ", num);
    for(i=2; i<=num; i++) {
        if(is_prime(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}