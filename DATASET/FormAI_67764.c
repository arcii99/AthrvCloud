//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <time.h>

int main() {
    long int seconds_to_travel;
    printf("Enter the number of seconds you would like to travel: ");
    scanf("%ld", &seconds_to_travel);
    time_t current_time = time(NULL);
    struct tm *time_info = localtime(&current_time);
    printf("Your current date and time is: %s", asctime(time_info));

    // Calculate the new date and time
    time_t new_time = current_time + seconds_to_travel;
    time_info = localtime(&new_time);

    // Print the new date and time
    printf("After time travel, the date and time is: %s", asctime(time_info));

    return 0;
}