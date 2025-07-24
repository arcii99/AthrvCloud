//FormAI DATASET v1.0 Category: System event logger ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct event {
    char type[20];
    char message[100];
    time_t timestamp;
};

void log_event(struct event);

int main() {
    struct event e;
    time_t t;

    srand(time(&t));
    int option = rand() % 3;

    if(option == 0) {
        strcpy(e.type, "SYSTEM_ERROR");
        strcpy(e.message, "Error in file system");
        time(&t);
        e.timestamp = t;
        log_event(e);
    }
    else if(option == 1) {
        strcpy(e.type, "USER_ACTION");
        strcpy(e.message, "User clicked on the log out button");
        time(&t);
        e.timestamp = t;
        log_event(e);
    }
    else {
        strcpy(e.type, "SECURITY_ALERT");
        strcpy(e.message, "Unauthorized access attempt");
        time(&t);
        e.timestamp = t;
        log_event(e);
    }

    return 0;
}

void log_event(struct event e) {
    FILE *fp;
    fp = fopen("event_log.txt", "a");

    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(fp, "%s | %s | %s", e.type, e.message, ctime(&e.timestamp));
    fclose(fp);
}