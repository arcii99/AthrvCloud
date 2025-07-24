//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

// Function to check if the user input contains a known malicious string
int detect_intrusion(char *input) {
    char *malicious_strings[] = {"DROP TABLE", "DELETE FROM", "INSERT INTO", "SELECT * FROM"};

    for(int i=0; i<4; i++) {
        if(strstr(input, malicious_strings[i]) != NULL) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char user_input[MAX_INPUT_LENGTH];

    printf("Enter your input:\n");
    fgets(user_input, MAX_INPUT_LENGTH, stdin);
    user_input[strcspn(user_input, "\n")] = 0; // Strip the newline character from the user input

    if(detect_intrusion(user_input)) {
        printf("INTRUSION DETECTED! Terminating program...\n");
        exit(1);
    } else {
        printf("Input accepted. Continuing with program...\n");
        // Rest of the program code goes here...
    }

    return 0;
}