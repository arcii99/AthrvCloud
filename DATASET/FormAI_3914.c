//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024

int main(int argc, char *argv[]) {

    char input[MAX_INPUT_LENGTH];
    char trigger[] = "password";
    int trigger_count = 0;

    printf("Enter input: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);

    printf("Checking for intrusion...\n");

    // Check for presence of trigger keyword
    if (strstr(input, trigger) != NULL) {
        trigger_count++;
    }
    
    // If trigger keyword present more than once, raise alarm
    if (trigger_count > 1) {
        printf("Intrusion detected! Multiple instances of trigger word found.\n");
    } else if (trigger_count == 1) {
        printf("Potential intrusion detected. One instance of trigger word found.\n");
    } else {
        printf("No intrusion detected.\n");
    }

    // Print details of input
    printf("Details of input:\n");
    printf("Length: %d\n", strlen(input));
    printf("Last character: %c\n", input[strlen(input) - 1]);
    printf("First word: %s\n", strtok(input, " "));

    return 0;
}