//FormAI DATASET v1.0 Category: Random ; Style: bold
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    int i, num;
    srand(time(0)); // Seed the random number generator with the current time
  
    printf("Generating 10 random numbers...\n");
    for(i = 0; i < 10; i++) {
        num = rand() % 100; // Generate a random number between 0-99
        printf("%d ", num);
    }
    printf("\n");
  
    return 0;
}