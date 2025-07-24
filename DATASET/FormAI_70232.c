//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_LEN 15
#define MAX_USER_LEN 20
#define MAX_LINE_LEN 100

int main() {
    FILE *fp;
    char line[MAX_LINE_LEN];
    char currIP[MAX_IP_LEN];
    char currUser[MAX_USER_LEN];
    char prevIP[MAX_IP_LEN] = "";
    char prevUser[MAX_USER_LEN] = "";
    int count = 0;

    fp = fopen("access_log.txt", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while(fgets(line, MAX_LINE_LEN, fp)) {
        char *token = strtok(line, " ");
        int tokenCount = 0;
        while(token != NULL) {
            if(tokenCount == 0) {
                strcpy(currIP, token);
            } else if(tokenCount == 2) {
                strcpy(currUser, token);
            }
            token = strtok(NULL, " ");
            tokenCount++;
        }

        if(strcmp(currIP, prevIP) == 0 && strcmp(currUser, prevUser) != 0) {
            count++;
            printf("Possible intrusion attempt on IP address %s by user %s\n", currIP, currUser);
        }

        strcpy(prevIP, currIP);
        strcpy(prevUser, currUser);
    }

    fclose(fp);

    if(count == 0) {
        printf("No intrusion attempts detected.\n");
    }

    return 0;
}