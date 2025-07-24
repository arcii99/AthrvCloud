//FormAI DATASET v1.0 Category: Date and time ; Style: surprised
#include<stdio.h>
#include<time.h>

int main(){
    printf("Wow! I can't believe I'm coding a C program to print the date and time!\n");
    printf("But hey, let's get to it!\n\n");

    time_t current_time;
    struct tm *local_time;

    current_time = time(NULL);
    local_time = localtime(&current_time);
    
    printf("The current date and time is: %s", asctime(local_time));
    printf("And it only took %ld seconds to calculate it!\n", current_time);

    printf("\nNow let's get fancy and print the date and time in a more readable format:\n");
    
    int day = local_time->tm_mday;
    int month = local_time->tm_mon + 1;
    int year = local_time->tm_year + 1900;
    int hour = local_time->tm_hour;
    int minute = local_time->tm_min;
    int second = local_time->tm_sec;

    printf("It is currently %d:%02d:%02d on %d/%02d/%d.\n", hour, minute, second, month, day, year);
    printf("Isn't that amazing?\n");

    printf("\nOh wait, we can go even further and print the date and time in the ISO 8601 format:\n");

    char iso_string[21];
    strftime(iso_string, 20, "%Y-%m-%dT%TZ", local_time);

    printf("The ISO 8601 date and time is: %s\n", iso_string);
    printf("My mind is blown... I can't believe I just wrote that code!\n");

    return 0;
}