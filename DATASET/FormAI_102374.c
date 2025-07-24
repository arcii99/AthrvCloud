//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("***Welcome to the Automated Fortune Teller***\n");

    // seed the random number generator
    srand(time(NULL));

    // create an array of fortunes
    char *fortunes[] = {
        "The journey is the reward.",
        "A smooth sea never made a skilled sailor.",
        "You will soon receive an unexpected gift.",
        "Your future looks bright!",
        "Good things come to those who wait.",
        "The best way to predict the future is to create it.",
        "Your hard work will pay off.",
        "The greatest risk is not taking one.",
        "You will find success in the things you love.",
        "Be the change you wish to see in the world."
    };

    // generate a random index for the array of fortunes
    int random_index = rand() % 10;

    // print the fortune
    printf("\nYour fortune for today:\n\n%s\n", fortunes[random_index]);

    printf("\nThank you for using the Automated Fortune Teller!\n");

    return 0;
}