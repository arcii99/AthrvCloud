//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: expert-level
#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm * current_time = localtime(&t);

    printf("Welcome to the Time Travel Simulator!\n");

    int option;
    printf("Choose a year to travel to:\n");
    scanf("%d", &option);

    printf("\nTravelling to %d...\n\n", option);

    current_time->tm_year = option - 1900;

    t = mktime(current_time);
    current_time = localtime(&t);

    printf("You have arrived in the year %d!\n", current_time->tm_year + 1900);
    printf("The current date and time is: %s", asctime(current_time));
    
    return 0;
}