//FormAI DATASET v1.0 Category: Date and time ; Style: thoughtful
#include <stdio.h>
#include <time.h>

void print_current_time() {
    time_t current_time = time(NULL);
    char* timestamp = ctime(&current_time); // get timestamp in human-readable format
    printf("Current time: %s", timestamp);
}

void print_future_time(int seconds) {
    time_t current_time = time(NULL);
    time_t future_time = current_time + seconds;
    char* timestamp = ctime(&future_time); // get timestamp in human-readable format
    printf("Future time (in %d seconds): %s", seconds, timestamp);
}

void print_time_diff_in_sec(time_t time1, time_t time2) {
    double time_diff = difftime(time2, time1); // calculate time difference in seconds
    printf("Time difference in seconds: %g\n", time_diff);
}

int main() {
    int future_seconds = 60;
    time_t current_time = time(NULL);
    print_current_time();
    print_future_time(future_seconds);
    sleep(future_seconds); // wait for some time
    time_t future_time = time(NULL);
    print_time_diff_in_sec(current_time, future_time);
    return 0;
}