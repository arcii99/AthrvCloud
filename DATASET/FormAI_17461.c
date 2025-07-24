//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char buffer[MAX_BUFFER_SIZE];
    char keyword[] = "hack";
    int is_hacking_attempt = 0;

    printf("Welcome to the Intrusion Detection System.\n");
    printf("Please enter your input:\n");

    while (fgets(buffer, MAX_BUFFER_SIZE, stdin) != NULL) {
        if (strstr(buffer, keyword) != NULL) {
            is_hacking_attempt = 1;
            printf("Intrusion attempt detected! Terminating program...\n");
            break;
        }
    }

    if (!is_hacking_attempt) {
        printf("No hacking attempt detected. System is secure.\n");
    }

    return 0;
}