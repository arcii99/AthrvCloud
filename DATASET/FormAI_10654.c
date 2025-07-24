//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void time_travel(int year, int month, int day){
    printf("\nYou are now going back in time to %d/%d/%d", day, month, year);
    time_t current_time = time(NULL);
    struct tm *current_tm = localtime(&current_time);

    current_tm->tm_year = year - 1900;
    current_tm->tm_mon = month - 1;
    current_tm->tm_mday = day;
    current_time = mktime(current_tm);
    printf("\n\nTime travel successful!\n\n");
    printf("Today's date is: %s", asctime(current_tm));
}

int main(){
    int year, month, day;

    printf("Welcome to the Time Travel Simulator! \n");
    printf("Enter a date to travel to (YYYY/MM/DD): ");
    scanf("%d/%d/%d", &year, &month, &day);

    time_travel(year, month, day);

    return 0;
}