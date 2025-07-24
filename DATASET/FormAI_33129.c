//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // Seed random number generator with current time

    // Array of possible fortune messages
    char* fortunes[] = {"You will achieve great success in your career.",
                        "Love is on the horizon. Look out for it!",
                        "Your financial situation is going to improve.",
                        "You will discover a new hobby that you love.",
                        "Travel is in your future. Pack your bags!",
                        "An unexpected opportunity is going to come your way.",
                        "You will meet someone who will impact your life in a positive way.",
                        "A difficult decision lies ahead, but you will make the right choice.",
                        "Take risks and you will be rewarded.",
                        "You will learn a valuable lesson from a mistake you make."};

    // Generate a random number between 0 and 9, inclusive
    int randomIndex = rand() % 10;

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");

    // Read user's name input
    char name[20];
    scanf("%s", name);

    printf("Hello, %s! Please ask me a question.\n", name);

    // Read user's question input
    char question[100];
    scanf(" %[^\n]s", question);

    // Display randomly generated fortune
    printf("\nHmm, let me consult my crystal ball...\n");
    printf("Your fortune is:\n%s", fortunes[randomIndex]);

    return 0;
}