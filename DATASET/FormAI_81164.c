//FormAI DATASET v1.0 Category: Random ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    // print a happy message to the user
    printf("Welcome to the random number generator!\n");
    printf("Press any key to generate a random number.\n");

    // seed the random number generator with the current time
    srand(time(NULL));

    // generate 10 random numbers and print them out
    for (int i = 0; i < 10; i++) {
        // use the rand() function to generate a random number between 1 and 100
        int rand_num = rand() % 100 + 1;

        // print out the number with a happy message
        printf("Your lucky number is: %d\n", rand_num);
    }

    // congratulate the user on their excellent luck
    printf("\n\nCongratulations, you're feeling lucky today!\n");
    printf("Don't spend all your winnings in one place!\n");

    return 0;
}