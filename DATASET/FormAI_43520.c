//FormAI DATASET v1.0 Category: Random ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed the random number generator
    srand(time(NULL));
    
    // Generate 10 random numbers between 1 and 100
    printf("Here are 10 random numbers between 1 and 100:\n");
    for (int i = 0; i < 10; i++) {
        int random_num = rand() % 100 + 1;
        printf("%d\n", random_num);
    }
    
    // Generate a random character
    printf("\nHere's a random character: ");
    char random_char = 'A' + rand() % 26;
    printf("%c\n", random_char);
    
    // Generate a random lowercase string of length 10
    printf("\nHere's a random lowercase string of length 10: ");
    for (int i = 0; i < 10; i++) {
        char random_lower = 'a' + rand() % 26;
        printf("%c", random_lower);
    }
    printf("\n");
    
    return 0;
}