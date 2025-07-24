//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: secure
#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);

    int starting_year = 2022;
    int target_year = 1982;

    while (current_time->tm_year + 1900 >= starting_year) {
        printf("Current year: %d\n", current_time->tm_year + 1900);
        printf("You are in the present time.\n");
        sleep(1);
        now++;
        current_time = localtime(&now);
    }

    printf("It's the year %d! You've traveled back in time.\n", target_year);
    printf("Tap any key to start the time machine.\n");
    getchar();

    now = mktime(current_time) - (starting_year - target_year) * 31536000;
    current_time = localtime(&now);

    while (current_time->tm_year + 1900 >= target_year) {
        printf("Current year: %d\n", current_time->tm_year + 1900);
        printf("Welcome to the past.\n");
        sleep(1);
        now--;
        current_time = localtime(&now);
    }

    printf("You've gone too far back. The time machine is starting to malfunction.\n");
    printf("The machine explodes, and you wake up in the present time.\n");

    return 0;
}