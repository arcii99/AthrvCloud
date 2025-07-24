//FormAI DATASET v1.0 Category: System event logger ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char *event) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%d-%02d-%02d %02d:%02d:%02d %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, event);
    FILE *file = fopen("log.txt", "a+");
    if (file == NULL) {
        printf("Error: could not open log file.\n");
        return;
    }
    fprintf(file, "%d-%02d-%02d %02d:%02d:%02d %s\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, event);
    fclose(file);
}

int main() {
    logEvent("Application started");
    // your code here
    logEvent("Application stopped");
    return 0;
}