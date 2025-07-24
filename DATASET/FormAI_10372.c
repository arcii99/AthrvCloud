//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers
int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    char quotes[5][100] = {
        "Your future is looking bright!",
        "You will encounter a great opportunity tomorrow.",
        "The stars are aligned in your favor.",
        "Keep an eye out for unexpected changes.",
        "Don't be afraid to take risks!"};

    srand(time(NULL));

    int fortune = generateRandomNumber(1, 10);

    if (fortune >= 1 && fortune <= 5)
    {
        printf("Your fortune is:\n%s\n", quotes[generateRandomNumber(0, 4)]);
    }
    else if (fortune >= 6 && fortune <= 8)
    {
        printf("Your fortune is:\nYou will %s.\n", 
        generateRandomNumber(0, 1) ? "encounter an unexpected person" : "find unexpected money");
    }
    else
    {
        printf("Your fortune is:\nYou will %s in the next year.\n",
        generateRandomNumber(0, 1) ? "travel to a new place" : "make a new friend");
    }

    return 0;
}