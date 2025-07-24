//FormAI DATASET v1.0 Category: System event logger ; Style: automated
#include <stdio.h>
#include <time.h>

void logEvent(char* eventType, char* description){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char timestamp[100];
    strftime(timestamp, sizeof(timestamp), "%c", tm);

    FILE *fp;
    fp = fopen("events.log", "a");

    fprintf(fp, "[%s] %s: %s\n", timestamp, eventType, description);
    fclose(fp);
}

int main(){
    logEvent("INFO", "Program started");

    // Do some logic

    logEvent("ERROR", "Invalid input detected");
    logEvent("INFO", "Program ended");
    return 0;
}