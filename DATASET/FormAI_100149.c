//FormAI DATASET v1.0 Category: System event logger ; Style: automated
#include <stdio.h>
#include <time.h>

void log_event(char* event) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    printf("[%04d-%02d-%02d %02d:%02d:%02d] %s\n", 
           tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
           tm->tm_hour, tm->tm_min, tm->tm_sec, event);
}

int main() {
    log_event("System started");
    // Your code here
    log_event("System stopped");
    return 0;
}