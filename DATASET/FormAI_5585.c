//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include <stdio.h>
#include <time.h>

int main() {

    /* Get the current time */
    time_t currentTime = time(NULL);

    /* Enter the year to travel to */
    printf("Enter the year to travel to: ");
    int year;
    scanf("%d", &year);

    /* Calculate the time difference */
    struct tm *timeStruct = localtime(&currentTime);
    int currentYear = timeStruct->tm_year + 1900;
    int yearsToTravel = year - currentYear;

    /* Calculate the travel time */
    time_t travelTime = currentTime + (yearsToTravel * 31536000);

    /* Convert travelTime to human-readable format */
    struct tm *travelTimeStruct = localtime(&travelTime);
    char dateString[100];
    strftime(dateString, sizeof(dateString), "%A, %B %d %Y", travelTimeStruct);
    printf("\nYou have traveled to: %s\n", dateString);

    /* Wait for user input to exit */
    printf("\nPress any key to exit...");
    getchar();

    return 0;
}