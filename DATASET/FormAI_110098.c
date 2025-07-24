//FormAI DATASET v1.0 Category: System event logger ; Style: Cyberpunk
#include <stdio.h>
#include <time.h>

void logEvent(char *eventType, char *eventDesc) {
    FILE *fp;
    time_t currTime;

    // Get current time
    currTime = time(NULL);

    // Open log file with append mode (new events will appear at the end)
    fp = fopen("eventLog.txt", "a");

    // Print event type, event description, and current time to log file
    fprintf(fp, "[%s] %s - %s", eventType, eventDesc, ctime(&currTime));

    // Close log file
    fclose(fp);
}

int main() {
    // Example usage
    logEvent("System", "System started up successfully");
    logEvent("Cyber Attack", "DDOS attack detected from IP 192.168.10.11");
    logEvent("Security", "Unauthorized access attempt from IP 10.23.45.67");

    return 0;
}