//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void detect_intrusion(char input[]) {
    // Check input for malicious code
    // If found, notify authorities and terminate program
    if (strstr(input, "malware") != NULL || strstr(input, "virus") != NULL) {
        printf("Intrusion detected! Notifying authorities...\n");
        exit(1);
    }
}

int main() {
    char input[100];
    printf("Welcome to the Intrusion Detection System. Please input your command:\n");

    // Loop through input until user enters "exit"
    while (strcmp(input, "exit") != 0) {
        // Prompt for input
        printf("> ");
        scanf("%s", input);
        // Check input for malicious code
        detect_intrusion(input);
        // Process input
        printf("Input processed.\n");
    }

    printf("Exiting Intrusion Detection System...\n");
    return 0;
}