//FormAI DATASET v1.0 Category: System event logger ; Style: single-threaded
#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_LOG_ENTRIES 100

struct LogEntry{
    char message[100];
    time_t timeStamp;
};

struct Log{
    struct LogEntry entries[MAX_LOG_ENTRIES];
    int count;
};

void logEvent(struct Log *log, const char *message){
    if(log->count < MAX_LOG_ENTRIES){
        struct LogEntry newEntry;
        strcpy(newEntry.message, message);
        newEntry.timeStamp = time(NULL);
        log->entries[log->count++] = newEntry;
    }
}

void printLog(struct Log *log){
    printf("Log entries:\n");
    for(int i=0; i<log->count; i++){
        printf("%s - %s", asctime(localtime(&(log->entries[i].timeStamp))), log->entries[i].message);
    }
}

int main(){
    struct Log myLog = {0};
    logEvent(&myLog, "System started");
    logEvent(&myLog, "User login failed");
    logEvent(&myLog, "Critical error: memory full");
    logEvent(&myLog, "System shutdown initiated");
    printLog(&myLog);
    return 0;
}