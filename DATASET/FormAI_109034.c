//FormAI DATASET v1.0 Category: System event logger ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct event {
    char time[30];
    char description[500];
} events[100];

int total_events = 0;

void log_event(char* desc) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    sprintf(events[total_events].time, "%d-%02d-%02d %02d:%02d:%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    strcpy(events[total_events].description, desc);
    total_events++;
}

void print_events() {
    printf("Events logged so far:\n");
    for (int i = 0; i < total_events; i++) {
        printf("%s: %s\n", events[i].time, events[i].description);
    }
}

int main() {
    log_event("System booting up");
    log_event("Network connection established");
    log_event("Application started running");
    print_events();
    return 0;
}