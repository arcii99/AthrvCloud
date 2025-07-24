//FormAI DATASET v1.0 Category: System event logger ; Style: Ken Thompson
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<syslog.h>

//Function to generate random timestamps
char* getTimestamp(){
    time_t t = time(NULL);
    struct tm* currentTime = localtime(&t);
    char* timestamp = asctime(currentTime);
    timestamp[strlen(timestamp)-1] = '\0';
    return timestamp;
}

int main(){

    //Open syslog
    openlog("SystemEventLogger", LOG_PID|LOG_CONS, LOG_USER);

    //Array of possible events
    const char* events[] = {"Disk Space Usage exceeding threshold", "Memory Usage reaching critical level", "Application Crash", "Unauthorized access attempt", "Invalid Input received", "Configuration File Error", "Network Connectivity issue", "File not found error", "System Restart", "Remote connection attempt"};

    //Loop to generate random system events
    for(int i=0; i<50; i++){
        int randomIndex = rand()%10;
        char* event = (char*)malloc(sizeof(char)*(strlen(events[randomIndex])+1));
        strcpy(event, events[randomIndex]);
        char* timestamp = getTimestamp();
        syslog(LOG_INFO, "[%s] %s", timestamp, event);
        free(event);
        sleep(1);
    }

    //Close syslog
    closelog();

    return 0;
}