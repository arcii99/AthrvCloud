//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int main() {
    char input[MAX_STRING_LENGTH]; // buffer to hold user input
    int count = 0; // count of malicious characters detected
    int i; // loop variable
    
    // Enter the program name
    printf("Welcome to Intrusion Detection System\n");
    printf("Please enter the name of the program you wish to monitor: ");
    fgets(input, MAX_STRING_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character
    
    // Alert the user that monitoring has started
    printf("Monitoring of %s has begun...\n", input);
    printf("Please enter any input to test for malicious characters.\n");
    
    // Monitor user input for malicious characters
    while (1) {
        fgets(input, MAX_STRING_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // remove newline character
        
        for (i = 0; i < strlen(input); i++) {
            if (input[i] == ';' || input[i] == '|' || input[i] == '<' || input[i] == '>' || input[i] == '(' || input[i] == ')') {
                count++;
                break;
            }
        }
        
        // Print an alert message if a malicious character is detected
        if (count > 0) {
            printf("ALERT: Malicious character detected in input: %s\n", input);
            break;
        }
        // Clear the input buffer
        memset(input, 0, MAX_STRING_LENGTH);
    }
    
    printf("Monitoring of %s complete.\n", input);
    printf("Thank you for using Intrusion Detection System!\n");
    
    return 0;
}