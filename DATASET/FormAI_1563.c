//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LOGS 1000
#define MAX_IP_LENGTH 20

//structure to hold log data
typedef struct {
    char ip[MAX_IP_LENGTH];
    char time[30];
    char action[50];
} Log;

//function to read logs from file and store in Log array
int getLogs(Log logs[]) {
    FILE *file;
    int i = 0;

    file = fopen("logs.txt", "r");
    if(file == NULL) {
        printf("Error reading logs file.\n");
        return -1;
    }

    while(!feof(file) && i < MAX_LOGS) {
        fscanf(file, "%s %s %[^\n]%*c", logs[i].ip, logs[i].time, logs[i].action);
        i++;
    }

    fclose(file);
    return i; //return number of logs read
}

//function to check for suspicious activity
void checkSuspicious(Log logs[], int numLogs) { 
    int i, j, count;
    char currIP[MAX_IP_LENGTH];
    char prevIP[MAX_IP_LENGTH] = "";
    char currTime[30];
    char prevTime[30];
    char currAction[50];
    char prevAction[50] = "";
    char path[MAX_LOGS][MAX_IP_LENGTH];
    count = 0;

    for(i = 0; i < numLogs; i++) {
        strcpy(currIP, logs[i].ip);
        strcpy(currTime, logs[i].time);
        strcpy(currAction, logs[i].action);

        if(strcmp(currIP, prevIP) == 0 && strcmp(currAction, prevAction) == 0) {
            if(count == 0) { //store previous log
                strcpy(path[count], currIP);
                count++;
            }
            if(count == 1 && strcmp(currIP, path[count-1]) != 0) { //store second log
                strcpy(path[count], currIP);
                count++;
            }
            if(count == 2 && strcmp(currIP, path[count-1]) != 0) { //store third log
                strcpy(path[count], currIP);
                count++;
            }

            if(count == 3 && strcmp(currIP, path[count-1]) != 0) { //suspicious activity detected
                printf("Suspicious activity detected:\n");
                for(j = 0; j < 3; j++) {
                    printf("%d. IP: %s Time: %s Action: %s\n", j+1, path[j], prevTime, prevAction);
                }
                printf("%d. IP: %s Time: %s Action: %s\n", j+1, currIP, currTime, currAction);
                printf("\n");

                //reset values
                strcpy(path[0], prevIP);
                strcpy(path[1], "");
                strcpy(path[2], "");
                count = 1;
            }
        }
        else { //reset values
            strcpy(path[0], currIP);
            strcpy(prevIP, currIP);
            strcpy(prevTime, currTime);
            strcpy(prevAction, currAction);
            count = 1;
        }
    }
}

int main() {
    Log logs[MAX_LOGS];
    int numLogs;

    numLogs = getLogs(logs);
    if(numLogs == -1) {
        return 0;
    }

    checkSuspicious(logs, numLogs);

    return 0;
}