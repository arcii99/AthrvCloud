//FormAI DATASET v1.0 Category: Funny ; Style: excited
// Get ready for some excitement! Here's a hilarious program written in C
// that's guaranteed to tickle your funny bone. Let's dive right in!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up some randomly generated numbers to be used throughout the program
    srand(time(0));
    int num1 = rand() % 20 + 1;
    int num2 = rand() % 20 + 1;
    int num3 = rand() % 20 + 1;

    // Declare some memorable strings that we'll be using later
    char intro[] = "Welcome to the funniest program you'll ever see!";
    char joke1[] = "Why did the programmer quit his job?";
    char punchline1[] = "Because he didn't get arrays!";
    char joke2[] = "Why couldn't the bicycle stand up by itself?";
    char punchline2[] = "Because it was two-tired!";

    // Print out the intro message, complete with some extra exclamation points for excitement!
    printf("%s!!!\n\n", intro);

    // Set up a loop to randomly decide on one of two jokes to tell
    for (int i = 0; i < 3; i++)
    {
        int joke_num = rand() % 2;

        if (joke_num == 0)
        {
            printf("%s\n", joke1);
            printf("%s\n\n", punchline1);
        }
        else
        {
            printf("%s\n", joke2);
            printf("%s\n\n", punchline2);
        }
    }

    // Use the randomly generated numbers to print out a wacky message
    printf("Congratulations, you've just won %d dollars %d cents and %d bananas!\n", num1, num2, num3);
    printf("Just kidding, you have won nothing! But wasn't that fun?!?!");

    return 0;
}