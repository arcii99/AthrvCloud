//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

// Struct for storing log information
typedef struct {
    char timestamp[30];
    char ip_addr[20];
    char action[50];
} Log;

// Global variable for storing logs
Log logs[100];
int log_index = 0;

// Handler function for SIGINT signal
void sigint_handler(int signum) {
    printf("\nReceived SIGINT signal. Saving logs to file...\n");
    // Open file for writing
    FILE *fptr;
    fptr = fopen("ids_logs.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    // Write logs to file
    for (int i = 0; i < log_index; i++) {
        fprintf(fptr, "[%s] [IP: %s] [Action: %s]\n", logs[i].timestamp, logs[i].ip_addr, logs[i].action);
    }
    fclose(fptr);
    printf("Logs saved to file: ids_logs.txt\n");
    exit(0);
}

int main() {
    // Register SIGINT handler
    signal(SIGINT, sigint_handler);
    srand(time(NULL));

    while (1) {
        // Generate random IP address (for simulation)
        char ip[20];
        strcpy(ip, "192.168.0.");
        strcat(ip, (rand() % 256) + 1);

        // Simulate attack - 10% probability
        if ((rand() % 10) == 0) {
            char action[50] = "Possible attack detected";
            printf("[%s] [IP: %s] [Action: %s]\n", __TIME__, ip, action);
            strcpy(logs[log_index].timestamp, __TIME__);
            strcpy(logs[log_index].ip_addr, ip);
            strcpy(logs[log_index].action, action);
            log_index++;
        }
        // Simulate normal activity - 90% probability
        else {
            char action[50] = "Normal activity";
            printf("[%s] [IP: %s] [Action: %s]\n", __TIME__, ip, action);
            strcpy(logs[log_index].timestamp, __TIME__);
            strcpy(logs[log_index].ip_addr, ip);
            strcpy(logs[log_index].action, action);
            log_index++;
        }
        // Wait for some time before generating next log entry
        sleep(1);
    }

    return 0;
}