//FormAI DATASET v1.0 Category: System event logger ; Style: Linus Torvalds
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>


enum log_level {
    LOG_LEVEL_DEBUG = 1,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR,
    LOG_LEVEL_FATAL
};

const char *LEVEL_STRINGS[] = {
    "UNKNOWN",
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
    "FATAL"
};

const int MAX_NUM_ARGS = 10;


static void log_event(enum log_level level, const char *format, ...) {

    time_t now = time(NULL);
    char time_str[64];

    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));

    va_list arg_list;
    va_start(arg_list, format);

    char log_str[4096];

    int num_chars_written = vsnprintf(log_str, sizeof(log_str), format, arg_list);

    if(num_chars_written < 0) {
        fprintf(stderr, "Failed to format log message.\n");
        return;
    }

    va_end(arg_list);

    char event_str[5000];

    snprintf(event_str, sizeof(event_str), "[%s] <%s> %s\n", time_str, LEVEL_STRINGS[level], log_str);

    printf("%s", event_str);
}


int main(int argc, char *argv[]) {

    log_event(LOG_LEVEL_DEBUG, "Starting up the logger.");

    log_event(LOG_LEVEL_INFO, "The system is running.");

    log_event(LOG_LEVEL_ERROR, "An error occurred with error code %d", 404);

    log_event(LOG_LEVEL_FATAL, "A critical error occurred and the system is shutting down.");

    return 0;
}