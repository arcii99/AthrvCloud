//FormAI DATASET v1.0 Category: System event logger ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct log_entry{
    int id;
    char type;
    char message[256];
    time_t timestamp;
} LogEntry;

void log_event(char type, char* message){
    LogEntry* entry = malloc(sizeof(LogEntry));
    entry->id = rand();
    entry->type = type;
    strcpy(entry->message, message);
    entry->timestamp = time(NULL);

    // send entry to a remote logging server
    // in a distributed system, we can have multiple logging servers 
    // to ensure fault tolerance and avoid single point of failure
    send_log(entry);
}

void send_log(LogEntry* entry){
    // simulate sending the log entry to a remote server
    printf("Sending log entry with id %d to remote server...\n", entry->id);
    // sleep to simulate network latency
    sleep(1);
    printf("Log entry sent successfully.\n");
}

int main(){
    log_event('I', "System started.");
    log_event('W', "Disk space low.");
    log_event('E', "Critical system error.");
    
    return 0;
}