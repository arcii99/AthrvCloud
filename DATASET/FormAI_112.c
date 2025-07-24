//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include <stdio.h>
#include <time.h>

int main() {
    time_t now = time(NULL);
    struct tm *current = localtime(&now);

    printf("Welcome to Time Travel Simulator!\n\n");
    printf("Enter a date and time in the future (MM/DD/YYYY HH:MM:SS): ");
    struct tm future;
    scanf("%d/%d/%d %d:%d:%d", &future.tm_mon, &future.tm_mday, 
            &future.tm_year, &future.tm_hour, &future.tm_min, &future.tm_sec);

    // Set tm_mon to be 0-indexed
    future.tm_mon -= 1;
    // Set tm_year to be relative to 1900
    future.tm_year -= 1900;
    // Convert future time to time_t
    time_t future_time = mktime(&future);

    printf("\nTime is now: %s", asctime(current));
    printf("Time machine is charging...\n");
    printf("Travelling to %s", asctime(&future));

    // Delay for dramatic effect
    for (int i = 0; i < 10; i++) {
        printf(".");
        fflush(stdout);
        sleep(1);
    }
    printf("\n\nWe have arrived at %s", asctime(&future));
    printf("Would you like to stay or return to the present?\n");
    printf("Enter 's' to stay or any other key to return: ");
    char choice;
    scanf(" %c", &choice);
    if (choice == 's') {
        printf("\nWelcome to the future!\n");
        printf("Current date and time: %s", asctime(&future));
    } else {
        printf("\nReturning to present...\n");
        time_t present_time = time(NULL);
        struct tm *present = localtime(&present_time);
        printf("\nWe have returned to: %s", asctime(present));
    }
    return 0;
}