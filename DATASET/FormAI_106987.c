//FormAI DATASET v1.0 Category: Funny ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the World of Randomness!\n\n");
    printf("Today, we are going to generate some random numbers using machine language! Woohooo!\n\n");
    printf("Are you ready? Let's do this!\n\n");
    
    srand(time(0)); // seed the randomizer with the time
    
    int max_num = 100; // the maximum number to generate
    int num_of_nums = 10; // the number of random numbers to generate
    
    printf("Generating %d random numbers between 0 and %d...\n\n", num_of_nums, max_num);
    
    int i;
    for (i = 1; i <= num_of_nums; i++) {
        printf("Random Number %d: %d\n", i, rand() % max_num);
    }
    
    printf("\nWow, that was so much fun! Let's do it again sometime!\n");
    
    return 0;
}