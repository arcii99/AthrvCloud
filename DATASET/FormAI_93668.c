//FormAI DATASET v1.0 Category: Date and time ; Style: energetic
#include <stdio.h>
#include <time.h>

int main(void) {
    time_t now;

    time(&now);

    printf("Welcome to the Energized Date and Time program!\n");
    printf("Today's date and time is: %s", ctime(&now));
    printf("How about we do some fun date and time calculations?\n");
    printf("Let me know how many seconds you'd like to add to the current time: ");

    int seconds;
    scanf("%d", &seconds);

    printf("Great! Adding %d seconds to the current time...\n", seconds);

    // Add the desired number of seconds to the current time
    now += seconds;

    printf("\nThe new date and time after adding %d seconds is: %s", seconds, ctime(&now));

    printf("\nLet's try something else.\n");
    printf("Enter 1 if you want to get the current year, or 2 to get the current month: ");

    int input;
    scanf("%d", &input);

    switch(input) {
        case 1:
            printf("\nThe current year is: %d\n", localtime(&now)->tm_year + 1900);
            break;
        case 2:
            printf("\nThe current month is: %d\n", localtime(&now)->tm_mon + 1);
            break;
        default:
            printf("\nInvalid input. Try again.\n");
            break;
    }

    printf("\nThanks for using the Energized Date and Time program!\n");

    return 0;
}