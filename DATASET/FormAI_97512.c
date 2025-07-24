//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Initialize random seed

    // Define fortune array
    char *fortune[] = {
        "You will soon meet new people who will make you happy!",
        "You will have a successful career and make good money!",
        "You will go on an amazing vacation and have the time of your life!",
        "You will fall in love with someone who loves you back just as much!",
        "You will achieve all of your dreams and live a long, happy life!"
    };

    // Get a random fortune
    int index = rand() % 5;
    char *selected_fortune = fortune[index];

    // Print out fortune
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Here is your unique fortune:\n\n");
    printf("%s\n", selected_fortune);

    return 0;
}