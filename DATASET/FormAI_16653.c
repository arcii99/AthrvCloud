//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <time.h>

int main() {
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);

    int year, month, day;
    printf("Enter a date in the format YYYY/MM/DD: ");
    scanf("%d/%d/%d", &year, &month, &day);

    struct tm enteredTime = { 
        .tm_year = year - 1900,
        .tm_mon = month - 1,
        .tm_mday = day
    };

    time_t enteredTimeEpoch = mktime(&enteredTime);
    double secondsDifference = difftime(enteredTimeEpoch, currentTime);

    if (secondsDifference < 0) {
        printf("You have entered a date from the past. Running time travel...\n");
    } else {
        printf("You have entered a date from the future. Running time travel...\n");
    }

    // Simulate time travel by waiting for the time difference
    printf("Time travel initiated. Please wait...\n");
    while (difftime(time(NULL), currentTime) < secondsDifference) {
        // Waiting...
    }
    printf("Time travel complete! You have arrived at your destination.\n");

    struct tm *newLocalTime = localtime(&enteredTimeEpoch);
    printf("New date and time: %s", asctime(newLocalTime));

    return 0;
}