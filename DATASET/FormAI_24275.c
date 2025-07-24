//FormAI DATASET v1.0 Category: Random ; Style: excited
/* Wow! Let's write a random number generator program in C! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    /* Let's tell the user what this exciting program is all about! */
    printf("Welcome to my random number generator program in C!\n");

    /* Let's declare some variables! */
    int min, max, num, i;
    
    /* Let's ask the user for the minimum and maximum numbers to generate! */
    printf("Please enter the minimum number: ");
    scanf("%d", &min);

    printf("Please enter the maximum number: ");
    scanf("%d", &max);

    /* Let's see if the user knows what they're doing! */
    if (min >= max) {
        printf("I'm sorry, that's not a valid input. The minimum number must be less than the maximum number. Try again!\n");
        return 1;
    }

    /* Let's use some magic to generate a random number! */
    srand(time(0));
    num = (rand() % (max - min + 1)) + min;

    /* Let's print out the random number! */
    printf("Your random number is: %d\n", num);

    /* Let's generate 10 random numbers! */
    printf("Here are 10 random numbers between %d and %d:\n", min, max);
    for (i = 0; i < 10; i++) {
        num = (rand() % (max - min + 1)) + min;
        printf("%d\n", num);
    }

    /* Let's say goodbye and end the program! */
    printf("Thanks for using my random number generator program! Goodbye!\n");
    return 0;
}