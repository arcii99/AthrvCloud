//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t t = time(NULL); // get current time
    struct tm* curr_time = localtime(&t); // convert current time to struct tm format

    int year, month, day;

    // ask user for the year, month, and day they want to travel to
    printf("What year would you like to travel to? ");
    scanf("%d", &year);
    printf("What month would you like to travel to? ");
    scanf("%d", &month);
    printf("What day would you like to travel to? ");
    scanf("%d", &day);

    // create a struct tm for the travel date
    struct tm travel_time = {0};
    travel_time.tm_year = year - 1900;
    travel_time.tm_mon = month - 1;
    travel_time.tm_mday = day;

    // calculate the difference between the two times in seconds
    time_t time_diff = mktime(&travel_time) - mktime(curr_time);

    if (time_diff <= 0) {
        printf("You cannot travel back in time. Please choose a future date.\n");
        return 0;
    }

    printf("Preparing to travel through time...\n");
    printf("3...\n");
    sleep(1); // wait for 1 second
    printf("2...\n");
    sleep(1);
    printf("1...\n");
    sleep(1);

    time_t travel_t = t + time_diff; // calculate travel time
    struct tm* travel_time_info = localtime(&travel_t); // convert travel time to struct tm format

    // print out the travel details to the user
    printf("You have successfully traveled to %d/%d/%d!\n", travel_time_info->tm_mday, travel_time_info->tm_mon + 1, travel_time_info->tm_year + 1900);

    return 0;
}