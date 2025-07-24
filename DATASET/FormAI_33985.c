//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 1000 // maximum number of logs that can be stored
#define MAX_IP_SIZE 40 // maximum size of IP address

// structure to store log data
struct Log {
    char ip[MAX_IP_SIZE];
    char time[20];
    char message[100];
};

// function to parse log data and store it in a Log struct
struct Log parseLog(char* logData) {
    struct Log log;
    char* token;

    // parse IP address
    token = strtok(logData, " ");
    if(token != NULL) {
        strcpy(log.ip, token);
    }

    // parse time
    token = strtok(NULL, " ");
    if(token != NULL) {
        strcpy(log.time, token);
    }

    // parse message
    token = strtok(NULL, "\n");
    if(token != NULL) {
        strcpy(log.message, token);
    }

    return log;
}

int main() {
    struct Log logs[MAX_LOG_SIZE]; // array to store logs
    int logIndex = 0; // variable to keep track of number of logs

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("log.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open log file.\n");
        return 0;
    }

    // read log file line by line
    while ((read = getline(&line, &len, fp)) != -1) {
        struct Log log = parseLog(line);
        logs[logIndex] = log;
        logIndex++;

        if(logIndex >= MAX_LOG_SIZE) {
            printf("Error: Maximum log storage capacity reached.\n");
            return 0;
        }
    }

    fclose(fp);
    if (line) {
        free(line);
    }

    // traverse through logs to detect intrusions
    for(int i = 0; i < logIndex; i++) {
        int count = 0;
        char currentIP[MAX_IP_SIZE];
        strcpy(currentIP, logs[i].ip);

        for(int j = i + 1; j < logIndex; j++) {
            if(strcmp(currentIP, logs[j].ip) == 0) {
                count++;
                if(count >= 10) {
                    printf("Intrusion detected! IP %s has made %d requests within a short time frame.\n", currentIP, count);
                    break;
                }
            }
        }
    }

    return 0;
}