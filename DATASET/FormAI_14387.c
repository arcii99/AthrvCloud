//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare an array of fortunes
    const char *fortunes[] = {
        "You will win the lottery!",
        "The love of your life is just around the corner.",
        "Your hard work will pay off.",
        "You will find success in your career.",
        "A great opportunity is coming your way.",
        "You will make a new friend soon.",
        "You will travel to a new and exciting place.",
        "Your health will improve.",
        "You will find peace and happiness in your life."
    };

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random index from 0 to the length of the fortunes array
    int index = rand() % (sizeof(fortunes) / sizeof(fortunes[0]));

    // Display the fortune
    printf("Your fortune for today is: %s\n", fortunes[index]);

    return 0;
}