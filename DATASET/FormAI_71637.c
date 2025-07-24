//FormAI DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char lines[MAX_LINES][MAX_LENGTH];
    int count = 0;
    int i;

    printf("Enter text (maximum 100 lines):\n");

    // Read in text line by line
    while (count < MAX_LINES && fgets(input, MAX_LENGTH, stdin) != NULL) {
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Copy input into lines array
        strcpy(lines[count], input);
        count++;
    }

    // Print out each line in reverse order
    for (i = count - 1; i >= 0; i--) {
        printf("%s\n", lines[i]);
    }

    return 0;
}