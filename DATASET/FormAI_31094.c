//FormAI DATASET v1.0 Category: String manipulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[50], output[100];
    int length;

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character
    strtok(input, "\n");

    length = strlen(input);

    // Check for buffer overflow
    if (length >= sizeof(output)) {
        printf("Error: input too large\n");
        exit(1);
    }

    // Copy input into output
    strncpy(output, input, sizeof(output));

    // Append " is a nice string" to output
    strncat(output, " is a nice string", sizeof(output) - length - 1);

    printf("Modified string: %s\n", output);

    return 0;
}