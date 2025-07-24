//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: surrealist
#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter a year to travel to: ");
    int year; scanf("%d", &year);
    printf("Enter a month to travel to: ");
    int month; scanf("%d", &month);
    printf("Enter a day to travel to: ");
    int day; scanf("%d", &day);

    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;

    time_t target_time = mktime(&tm);

    printf("Time machine activated...\n");
    printf("Traveling to %02d/%02d/%d...\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900);
    printf("Arrived at destination!\n");

    if(t > target_time) {
        printf("Oh no! You have traveled back in time...\n");
        printf("Current time: %s", asctime(&tm));
    } else if(t < target_time) {
        printf("Congratulations! You have successfully traveled to the future.\n");
        printf("Current time: %s", asctime(&tm));
    } else {
        printf("You seem to be stuck in a time loop...\n");
        printf("Current time: %s", asctime(&tm));
    }

    printf("Thank you for using the Time Travel Simulator. Goodbye!");

    return 0;
}