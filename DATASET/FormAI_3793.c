//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_ENTRIES 1000
#define MAX_IP_ADDRESSES 100
#define MAX_LOG_LINE_LENGTH 100

typedef struct {
    char ipAddress[16];
    int count;
} IpAddress;

int isIpAddressValid(char *ipAddress);
int isIpAddressInList(IpAddress ipAddresses[], char *ipAddress, int numIpAddresses);
void addIpAddressToList(IpAddress ipAddresses[], char *ipAddress, int *numIpAddresses);

int main(int argc, char *argv[]) {
    FILE *logFile;
    char logLine[MAX_LOG_LINE_LENGTH];
    IpAddress ipAddresses[MAX_IP_ADDRESSES];
    int numIpAddresses = 0;
    int numLogEntries = 0;
    
    if(argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    if((logFile = fopen(argv[1], "r")) == NULL) {
        printf("Error: File %s could not be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    while(fgets(logLine, MAX_LOG_LINE_LENGTH, logFile) != NULL) {
        if(isIpAddressValid(logLine)) {
            if(!isIpAddressInList(ipAddresses, logLine, numIpAddresses)) {
                addIpAddressToList(ipAddresses, logLine, &numIpAddresses);
            }
            
            if(++numLogEntries >= MAX_LOG_ENTRIES) {
                printf("Error: Maximum log entries reached.\n");
                break;
            }
        }
    }
    
    printf("Intrusion Detection System Report:\n");
    printf("Number of unique IP addresses found in log file: %d\n", numIpAddresses);
    
    fclose(logFile);
    exit(EXIT_SUCCESS);
}

int isIpAddressValid(char *ipAddress) {
    char *token;
    int numTokens = 0;
    int num;
    
    token = strtok(ipAddress, ".");
    while(token != NULL) {
        numTokens++;
        num = atoi(token);
        if(num < 0 || num > 255) {
            return 0;
        }
        token = strtok(NULL, ".");
    }
    
    return numTokens == 4;
}

int isIpAddressInList(IpAddress ipAddresses[], char *ipAddress, int numIpAddresses) {
    int i;
    
    for(i = 0; i < numIpAddresses; i++) {
        if(strcmp(ipAddresses[i].ipAddress, ipAddress) == 0) {
            ipAddresses[i].count++;
            return 1;
        }
    }
    
    return 0;
}

void addIpAddressToList(IpAddress ipAddresses[], char *ipAddress, int *numIpAddresses) {
    strcpy(ipAddresses[*numIpAddresses].ipAddress, ipAddress);
    ipAddresses[*numIpAddresses].count = 1;
    (*numIpAddresses)++;
}