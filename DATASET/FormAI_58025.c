//FormAI DATASET v1.0 Category: System event logger ; Style: Ada Lovelace
#include <stdio.h>
#include <time.h>

void logEvent(char* event){
    FILE *file;
    char *filename = "event_log.txt";
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    time_t now = time(NULL);
    char* timestamp = ctime(&now);
    fprintf(file, "%s: %s\n", timestamp, event);
    fclose(file);
}

int main(){
    logEvent("System started"); // Logging system startup event
    // Some codes here
    logEvent("User logged in"); // Logging user login event
    // Some codes here
    logEvent("Critical error occurred"); // Logging critical error event
    return 0;
}