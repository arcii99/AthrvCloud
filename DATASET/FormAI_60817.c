//FormAI DATASET v1.0 Category: System event logger ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// struct to hold event data
typedef struct event {
    char message[100];
    char timestamp[30];
} Event;

// function to write event to log file
void writeEvent(Event e) {
    FILE *f = fopen("events.log", "a");
    fprintf(f, "[%s] %s\n", e.timestamp, e.message);
    fclose(f);
}

// function to create and log an event
void logEvent(char* message) {
    Event e;
    strcpy(e.message, message);
    time_t raw_time;
    struct tm *time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(e.timestamp, 30, "%Y-%m-%d %H:%M:%S", time_info);
    writeEvent(e);
}

// main function for testing
int main() {
    logEvent("Program started");
    int a = 5;
    int b = 7;
    int sum = a + b;
    logEvent("Variables initialized");
    printf("The sum of %d and %d is %d\n", a, b, sum);
    logEvent("Sum calculated and printed");
    return 0;
}