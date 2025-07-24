//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller Program!\n");

    // Initializing the random number generator
    srand(time(NULL));

    // Creating an array of fortunes
    char *fortunes[] = {"A great adventure awaits you.",
                        "A cheerful letter or message is on its way to you.",
                        "Your hard work will pay off.",
                        "A good friend is about to enter your life.",
                        "You will soon meet a person who will become very important to you.",
                        "Your future looks very bright.",
                        "A pleasant surprise is waiting for you.",
                        "You will soon receive a promotion.",
                        "Your goals will soon become a reality.",
                        "Your financial situation will improve soon."};

    // Calculating the size of the fortunes array
    int num_fortunes = sizeof(fortunes) / sizeof(char *);

    // Generating a random index to select a fortune
    int random_index = rand() % num_fortunes;

    // Printing the selected fortune
    printf("\nYour fortune for today is: %s\n", fortunes[random_index]);

    return 0;
}