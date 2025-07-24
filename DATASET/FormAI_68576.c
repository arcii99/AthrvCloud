//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed
    const char* fortunes[] = {"You will find happiness with a new love.", "Great things are coming your way.", "You will achieve great success in your career.", "Happiness will come to you when you least expect it.", "A long forgotten friend will call you this week."}; // array of fortunes
    int index = rand() % 5; // generate random index between 0-4
    printf("Welcome to the Automated Fortune Teller.\n");
    printf("Your fortune for today is: %s\n", fortunes[index]); // print random fortune
    return 0;
}