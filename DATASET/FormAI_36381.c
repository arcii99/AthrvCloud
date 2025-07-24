//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(int seconds){
    int mill = 1000 * seconds;
    clock_t start_time = clock();
    while (clock() < start_time + mill);
}

int main(){
    int current_year;
    time_t time_now;
    struct tm *time_info;
    char year[5];
    printf("Welcome to the Time Travel Simulator!\n");
    delay(2);
    printf("Please enter the current year (in yyyy format):\n");
    scanf("%4s", year);
    current_year = atoi(year);
    if(current_year < 2021){
        printf("Sorry, we cannot time travel to the past.\n");
    }
    else if(current_year > 3021){
        printf("Sorry, we cannot time travel to the future beyond 3021.\n");
    }
    else{
        time(&time_now);
        time_info = localtime(&time_now);
        printf("Current time: %s", asctime(time_info));
        delay(2);
        printf("Preparing time travel sequence...\n");
        delay(3);
        printf("Initiating time travel sequence...\n");
        delay(4);
        printf("You have successfully time travelled to the year %d!\n", current_year);
        time_info -> tm_year = current_year - 1900;
        time_info -> tm_mon = 0;
        time_info -> tm_mday = 1;
        time_info -> tm_hour = 0;
        time_info -> tm_min = 0;
        time_info -> tm_sec = 0;
        time_now = mktime(time_info);
        time_info = localtime(&time_now);
        printf("Current time in %d: %s", current_year, asctime(time_info));
    }
    return 0;
}