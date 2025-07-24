//FormAI DATASET v1.0 Category: Scientific ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int day_number;
    bool is_leap_year;

    printf("Welcome to the Leap Year Checker 3000!\n\n");
    
    printf("Please enter the year you want to check: ");
    scanf("%d", &day_number);

    if ((day_number % 4 == 0 && day_number % 100 != 0) || day_number % 400 == 0) {
        printf("\nHooray! %d is a leap year!\n", day_number);
        is_leap_year = true;
    } else {
        printf("\nOh no! %d is not a leap year.\n", day_number);
        is_leap_year = false;
    }

    if (is_leap_year) {
        printf("Here's a fun fact: Did you know that leap years have 366 days instead of the usual 365?\n");
        printf("This means that you get an extra day to eat pizza, watch Netflix, or save the world from intergalactic threats!\n");
    } else {
        printf("Sorry, you won't get an extra day this year. Better luck next time!\n");
        printf("But don't worry, you can still eat pizza, watch Netflix, or save the world from intergalactic threats on any day!\n");
    }

    printf("\nThank you for using the Leap Year Checker 3000. Have a wonderful day!\n");

    return 0;
}