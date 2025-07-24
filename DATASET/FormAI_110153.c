//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: Cyberpunk
#include <stdio.h>

// defining function to check if a number is prime or not
int is_prime(int num) {
    int i;
    if (num <= 1){
        return 0;
    }
    for (i = 2; i < num; i++){
        if (num % i == 0){
            return 0;
        }
    }
    return 1;
}

int main() {

    printf("------------------------------\n");
    printf("Cyberpunk Prime Number Generator\n");
    printf("------------------------------\n\n");

    // user input
    int n;
    printf("How many prime numbers do you want to generate?: ");
    scanf("%d", &n);

    printf("------------------------------\n");
    printf("Generating...\n");
    printf("------------------------------\n\n");

    int count = 0, num = 2;
    printf("The first %d prime numbers are:\n", n);
    while (count < n) {
        if (is_prime(num)) {
            count++;
            printf("%d ", num);
        }
        num++;
    }

    printf("\n------------------------------\n");
    printf("Generation complete!\n");
    printf("------------------------------\n");

    return 0;
}