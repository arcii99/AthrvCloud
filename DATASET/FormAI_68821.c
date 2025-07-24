//FormAI DATASET v1.0 Category: Date and time ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to print date and time
void printDateTime(const struct tm* datetime) {
    char datetime_str[80];
    strftime(datetime_str, 80, "%Y-%m-%d %H:%M:%S", datetime);
    printf("Current date and time: %s\n", datetime_str);
}

// Callback function for asynchronous date/time retrieval
void callback(void* arg) {
    struct tm* datetime = (struct tm*)arg;
    printDateTime(datetime);
    free(datetime); // Free memory allocated for datetime struct
}

// Function to get current date and time asynchronously
void getCurrentDateTimeAsync(void (*callback)(void*), bool isLocalTime) {
    // Allocate memory for datetime struct
    struct tm* datetime = (struct tm*)malloc(sizeof(struct tm));
    
    // Get current time as epoch time
    time_t current_time = time(NULL);
    
    if (isLocalTime) {
        localtime_r(&current_time, datetime); // Get local time
    } else {
        gmtime_r(&current_time, datetime); // Get UTC time
    }
    
    // Call the callback function and pass the datetime struct as argument
    callback(datetime);
}

int main() {
    printf("Retrieving current date and time asynchronously...\n");
    
    // Retrieve current local date and time asynchronously
    getCurrentDateTimeAsync(callback, true);
    
    // Retrieve current UTC date and time asynchronously after 5 seconds
    sleep(5);
    getCurrentDateTimeAsync(callback, false);
    
    return 0;
}