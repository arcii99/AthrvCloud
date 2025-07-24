//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int counter = 0;

    // Loop through input from stdin
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        // Check for malicious code
        if (strstr(buffer, "rm -rf /") != NULL) {
            // Counter to keep track of number of times malicious code is detected
            counter++;
            // Alert user of possible attack
            printf("Malicious code detected!\n");
        }
    }

    // Check if any attacks were detected
    if (counter == 0) {
        printf("No attacks detected\n");
    } else {
        printf("%d attacks detected\n", counter);
    }

    return 0;
}