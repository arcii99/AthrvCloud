//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: relaxed
#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;   // To store current time
    struct tm * time_info; // Pointer to time_info structure
    char time_str[50];     // To store formatted time string

    // Get current time
    time(&current_time);

    // Convert current time to time_info structure
    time_info = localtime(&current_time);

    // Format time string and print it
    strftime(time_str, sizeof(time_str), "It's currently %I:%M %p on %A, %B %d, %Y", time_info);
    printf("%s\n", time_str);

    // Ask user for a year to travel to
    int year;
    printf("What year would you like to travel to?\n");
    scanf("%d", &year);

    // Set time_info structure with user's desired year
    time_info->tm_year = year - 1900;

    // Convert time_info structure to time
    current_time = mktime(time_info);

    // Format and print the new time
    strftime(time_str, sizeof(time_str), "You have traveled to %Y. It's currently %I:%M %p on %A, %B %d", localtime(&current_time));
    printf("%s\n", time_str);

    return 0;
}