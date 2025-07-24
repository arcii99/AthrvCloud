//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <time.h>

void travel(int year){
    time_t current_time;
    struct tm * time_info;
    time(&current_time);
    time_info = localtime(&current_time);
    int current_year = time_info->tm_year + 1900;
    if(year < current_year){
        printf("You have traveled back in time to the year %d\n", year);
    } else if(year > current_year){
        printf("You have traveled into the future to the year %d\n", year);
    } else{
        printf("You are in the present year %d\n", current_year);
    }
}

int main(){
    int year;
    printf("Enter a year to time travel to: ");
    scanf("%d", &year);
    travel(year);
    return 0;
}