//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_ATTEMPTS 5
    
int main() {
    int attempts = 0;
    char password[MAX_LENGTH];
    char input[MAX_LENGTH];
    printf("Welcome to the Intrusion Detection System.\n");
    printf("Please enter the password to access the system:\n");
    scanf("%s", password);
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter command:\n");
        fgets(input, MAX_LENGTH, stdin);
        if (strstr(input, "sudo") != NULL) {
        // If the input contains "sudo", trigger intrusion detection.
            printf("INTRUSION DETECTED. ACCESS DENIED.\n");
            return 0;
        }
        attempts++;
    }
    printf("MAXIMUM NUMBER OF ATTEMPTS REACHED. ACCESS DENIED.\n");
    return 0;
}