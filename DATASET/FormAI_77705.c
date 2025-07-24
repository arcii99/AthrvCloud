//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t current_time; // initialize time_t structure
    struct tm* current_tm; // initialize struct tm to break down time_t to human-readable format
    
    // get current timestamp
    current_time = time(NULL);

    // break down current timestamp to human-readable format
    current_tm = localtime(&current_time);
    printf("Today's date and time: %s", asctime(current_tm));
    
    // set future date
    struct tm future_tm = {0}; // initialize struct tm
    future_tm.tm_year = current_tm->tm_year + 10; // add 10 years
    future_tm.tm_mon = current_tm->tm_mon + 6; // add 6 months
    future_tm.tm_mday = current_tm->tm_mday; // same day
    future_tm.tm_hour = current_tm->tm_hour; // same hour
    future_tm.tm_min = current_tm->tm_min; // same minute
    future_tm.tm_sec = current_tm->tm_sec; // same second
    
    // convert future date to timestamp
    time_t future_time = mktime(&future_tm);
    
    // break down future timestamp to human-readable format
    struct tm* future_tm_ptr = localtime(&future_time);
    printf("10 years and 6 months from now: %s", asctime(future_tm_ptr));

    // set past date
    struct tm past_tm = {0}; // initialize struct tm
    past_tm.tm_year = current_tm->tm_year - 5; // subtract 5 years
    past_tm.tm_mon = current_tm->tm_mon - 3; // subtract 3 months
    past_tm.tm_mday = current_tm->tm_mday; // same day
    past_tm.tm_hour = current_tm->tm_hour; // same hour
    past_tm.tm_min = current_tm->tm_min; // same minute
    past_tm.tm_sec = current_tm->tm_sec; // same second
    
    // convert past date to timestamp
    time_t past_time = mktime(&past_tm);
    
    // break down past timestamp to human-readable format
    struct tm* past_tm_ptr = localtime(&past_time);
    printf("5 years and 3 months ago: %s", asctime(past_tm_ptr));

    return 0;
}