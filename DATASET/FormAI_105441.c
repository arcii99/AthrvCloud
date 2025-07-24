//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LEN = 100;

// Function to check if the given input has any forbidden keywords
int checkKeywords(char *input) {
    char keywords[5][10] = {"rm", "sudo", "shutdown", "halt", "reboot"};
    int i;

    for (i = 0; i < 5; i++) {
        if (strstr(input, keywords[i])) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char input[MAX_LEN], c;
    int index = 0;

    printf("Enter the command:\n");

    // Read the command character by character and check for forbidden keywords
    while ((c = getchar()) != '\n') {
        // Check for buffer overflow
        if (index >= MAX_LEN) {
            printf("Buffer overflow!\n");
            exit(EXIT_FAILURE);
        }

        input[index++] = c;
    }

    input[index] = '\0';

    if (checkKeywords(input)) {
        printf("Intrusion detected!\n");
    } else {
        printf("Command accepted.\n");
    }

    return 0;
}