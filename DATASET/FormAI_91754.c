//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <time.h>

int main() {
    time_t unix_time, travel_time;
    struct tm *time_info, *travel_info;
    char time_string[50], travel_string[50];

    // get current time
    unix_time = time(NULL);
    time_info = localtime(&unix_time);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

    // travel to the future
    travel_time = unix_time + 86400*365; // one year later
    travel_info = localtime(&travel_time);
    strftime(travel_string, sizeof(travel_string), "%Y-%m-%d %H:%M:%S", travel_info);

    printf("Current time: %s\n", time_string);
    printf("Traveling to the future...\n");
    printf("One year later: %s\n", travel_string);

    // travel to the past
    travel_time = unix_time - 86400*365; // one year ago
    travel_info = localtime(&travel_time);
    strftime(travel_string, sizeof(travel_string), "%Y-%m-%d %H:%M:%S", travel_info);

    printf("Traveling to the past...\n");
    printf("One year ago: %s\n", travel_string);

    return 0;
}