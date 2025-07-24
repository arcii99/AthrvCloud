//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: safe
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int count = 0;

    printf("Welcome to Intrusion Detection System!\n");

    while (1) {
        printf("\nEnter a command: ");
        fgets(input, sizeof(input), stdin);

        if (strstr(input, "sudo") != NULL) {
            printf("Access Denied! 'sudo' commands are not allowed.\n");
            count++;
        } else if (strstr(input, "|") != NULL) {
            printf("Access Denied! Piping commands are not allowed.\n");
            count++;
        } else if (strstr(input, "rm") != NULL || strstr(input, "mv") != NULL) {
            printf("Access Denied! File manipulation commands are not allowed.\n");
            count++;
        } else {
            printf("Command accepted.\n");
        }

        if (count >= 3) {
            printf("\nWARNING: You have exceeded the maximum number of denied commands.\n");
            printf("System shutting down...\n");
            break;
        }
    }

    return 0;
}