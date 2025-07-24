//FormAI DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// async function to generate a random number after a delay
void generateRandomNumberAfterDelay(int delay, int *number) {
    // generating a random number after some delay and storing it in the address pointed to by number
    srand(time(0) + delay);
    int random_number = rand() % 100;
    printf("Async Task: Generating random number after %d seconds\n", delay);
    printf("Async Task: Random Number Generated: %d\n", random_number);
    *number = random_number;
}

int main() {
    // declaring variables
    int number = 0;
    int product = 0;

    // generate a random number asynchronously after 3 seconds
    printf("Async Program: Starting Async Task...\n");
    generateRandomNumberAfterDelay(3, &number);

    // calculating the square of the number asynchronously after a delay
    printf("Async Program: Starting another Async Task...\n");
    for(int i=5;i>=0;i--) {
        printf("Async Program: Squaring the number after %d seconds...\n", i);
        sleep(1);
    }
    product = number * number;
    printf("Async Program: Square of the number %d: %d\n", number, product);

    return 0;
}