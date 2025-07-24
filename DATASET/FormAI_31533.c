//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: authentic
#include <stdio.h>

// Function of finding prime numbers upto the given limit
void primeGenerator(int limit) {
    int count = 0; // Initialisation of a variable used to count the number of prime numbers found
    int flag; // A flag variable that checks if the number has a factor other than 1 and itself

    printf("Prime Numbers between 2 and %d are:\n", limit);

    // Loop to check if each number is a prime number or not
    for (int num = 2; num <= limit; num++) {
        flag = 0;
        // Inner loop to check if the number has factors
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                flag = 1;
                break;
            }
        }
        // If the number has no factor, it is a prime number
        if (flag == 0) {
            printf("%d ", num);
            count++;
        }
    }
    printf("\nTotal number of prime numbers between 2 and %d are: %d\n", limit, count);
}

int main() {
    int limit;
    printf("Enter the limit up to which prime numbers are to be generated: ");
    scanf("%d", &limit);

    // Checking if the limit is valid or not
    if (limit < 2) {
        printf("Invalid limit, please enter a number greater than or equal to 2.\n");
        return 0;
    }

    // Function call to generate the prime numbers
    primeGenerator(limit);

    return 0;
}