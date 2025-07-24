//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define time travel function
void time_travel(int year, int month, int day) {
    // Set the current and target time
    time_t current_time = time(NULL);
    struct tm current_tm = *localtime(&current_time);
    struct tm target_tm = {.tm_year = year - 1900, .tm_mon = month - 1, .tm_mday = day};
    time_t target_time = mktime(&target_tm);

    // Calculate the time difference
    double time_diff = difftime(target_time, current_time);

    // Output the result
    printf("Time travel result:\n");
    printf("You travelled %0.0f seconds into the future!\n", time_diff);
    printf("Current time: %s", asctime(&current_tm));
    printf("Target time: %s", asctime(&target_tm));
}

int main() {
    // Set the target date
    int target_year = 3000;
    int target_month = 1;
    int target_day = 1;

    // Invoke the time travel function
    time_travel(target_year, target_month, target_day);

    return 0;
}