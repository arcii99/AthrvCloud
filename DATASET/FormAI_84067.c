//FormAI DATASET v1.0 Category: System event logger ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void log_event(char* event_type, char* message) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    FILE* file = fopen("event_log.txt", "a");
    fprintf(file, "%d-%02d-%02d %02d:%02d:%02d [%s]: %s\n",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec, event_type, message);
    fclose(file);
}

void system_startup() {
    log_event("INFO", "System started up successfully");
    // ...
}

void system_shutdown() {
    log_event("INFO", "System shutting down");
    // ...
}

void do_something() {
    // some code...
    log_event("DEBUG", "Did something interesting");
    // more code...
}

int main() {
    system_startup();
    // ...
    do_something();
    // ...
    system_shutdown();
    return 0;
}