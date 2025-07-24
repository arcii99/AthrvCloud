//FormAI DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
#include <stdio.h>
#include <time.h>

void logEvent(char* event)
{
    time_t now;
    struct tm* timeinfo;
    now = time(NULL);
    timeinfo = localtime(&now);
    
    FILE* file = fopen("system_log.txt", "a");
    
    if (file != NULL) {
        fprintf(file, "[%04d-%02d-%02d %02d:%02d:%02d] %s\n",
                timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday,
                timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
                event);
        fclose(file);
    }
}

int main()
{
    // Example usage
    logEvent("System started");
    logEvent("Disk space low");
    logEvent("Critical error occurred");
    
    return 0;
}