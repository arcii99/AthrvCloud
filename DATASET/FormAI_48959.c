//FormAI DATASET v1.0 Category: Date and time ; Style: creative
#include<stdio.h>
#include<time.h>

/* Function to calculate time difference in seconds */
int time_diff(struct timespec *start, struct timespec *stop, struct timespec *diff)
{
    if ((stop->tv_nsec - start->tv_nsec) < 0) {
        diff->tv_sec = stop->tv_sec - start->tv_sec - 1;
        diff->tv_nsec = stop->tv_nsec - start->tv_nsec + 1000000000;
    } else {
        diff->tv_sec = stop->tv_sec - start->tv_sec;
        diff->tv_nsec = stop->tv_nsec - start->tv_nsec;
    }
    return (diff->tv_sec * 1000000000) + diff->tv_nsec;
}

/* Main function to demonstrate date and time functionality */
int main()
{
    /* Example 1 - Print current date and time */
    time_t current_time = time(NULL);
    printf("Current date and time: %s", asctime(localtime(&current_time)));

    /* Example 2 - Calculating time difference */
    struct timespec start, stop, diff;
    clock_gettime(CLOCK_REALTIME, &start);
    // Code to be timed
    for (int i=0; i<100000000; i++) {}
    clock_gettime(CLOCK_REALTIME, &stop);
    printf("Time taken = %d nanoseconds\n", time_diff(&start, &stop, &diff));

    /* Example 3 - Formatting time using strftime */
    char buffer[80];
    struct tm time_info;
    time(&current_time);
    localtime_r(&current_time, &time_info);
    strftime(buffer, 80, "Formatted date and time: %A, %B %d %Y %H:%M:%S", &time_info);
    printf("%s\n", buffer);

    return 0;
}