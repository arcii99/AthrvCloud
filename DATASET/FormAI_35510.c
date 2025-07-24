//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: irregular
// Irregular Time Travel Simulator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    time_t t; // variable to hold time
    srand((unsigned) time(&t)); // seed the random number generator

    printf("Welcome to the Irregular Time Travel Simulator!\n\n");

    int year = rand() % 10000; // generate a random year between 0 and 9999
    int month = rand() % 12 + 1; // generate a random month between 1 and 12
    int day = rand() % 31 + 1; // generate a random day between 1 and 31

    printf("You will be time traveling to %d/%d/%d.\n\n", month, day, year);

    // simulate the time travel experience
    printf("3...2...1...GO!\n\n");
    for (int i = 5; i >= 1; i--)
    {
        printf("%d...\n", i);
        sleep(1);
    }
    printf("You have arrived!\n\n");

    // display information about the time period
    printf("Here are some interesting facts about the time period:\n\n");
    switch (year / 1000)
    {
        case 0:
            printf("This is the Prehistoric era.\n");
            break;
        case 1:
            printf("This is the Ancient era.\n");
            break;
        case 2:
            printf("This is the Medieval era.\n");
            break;
        case 3:
            printf("This is the Renaissance era.\n");
            break;
        case 4:
            printf("This is the Enlightenment era.\n");
            break;
        case 5:
            printf("This is the Industrial Revolution era.\n");
            break;
        case 6:
            printf("This is the Modern era.\n");
            break;
        case 7:
            printf("This is the Post-Modern era.\n");
            break;
        case 8:
            printf("This is the Information era.\n");
            break;
        case 9:
            printf("This is the Future era.\n");
            break;
        default:
            printf("Unknown era.\n");
            break;
    }
    if (month == 12 && day == 25)
    {
        printf("It's Christmas Day!\n");
    }
    if (year >= 2000 && year <= 2021)
    {
        printf("You have arrived in the 21st century.\n");
    }
    if (year < 1000)
    {
        printf("The year is represented with Roman numerals.\n");
    }
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        printf("This year is a leap year.\n");
    }

    printf("\nThank you for using the Irregular Time Travel Simulator!\n");

    return 0;
}