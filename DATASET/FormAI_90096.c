//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

// Cyberpunk style ASCII art generator
int main(int argc, char *argv[]) {
    char input[MAX_HEIGHT][MAX_WIDTH];
    char output[MAX_HEIGHT][MAX_WIDTH * 4];
    char buffer[MAX_WIDTH];
    int row_count = 0;
    int col_count = 0;

    // Read input from user
    printf("Enter up to %d lines of text:\n", MAX_HEIGHT);
    while (fgets(buffer, MAX_WIDTH, stdin) != NULL && row_count < MAX_HEIGHT) {
        buffer[strcspn(buffer, "\r\n")] = 0; // Remove newline character(s)

        // Add input to input array
        strncpy(input[row_count], buffer, MAX_WIDTH - 1);
        input[row_count][MAX_WIDTH - 1] = '\0';

        // Increment row count and calculate maximum column count
        row_count++;
        col_count = (int)fmax(col_count, strlen(buffer));
    }

    // Convert input to ASCII art
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            char c = input[i][j];

            // Convert character to ASCII art
            if (c >= 'a' && c <= 'z') {
                snprintf(output[i], sizeof(output[i]), "%s%c%s", output[i], c - 96, (j == col_count - 1) ? "  " : "");
            } else if (c >= 'A' && c <= 'Z') {
                snprintf(output[i], sizeof(output[i]), "%s%c%s", output[i], c - 38, (j == col_count - 1) ? "  " : "");
            } else if (c >= '0' && c <= '9') {
                snprintf(output[i], sizeof(output[i]), "%s%c%s", output[i], c + 16, (j == col_count - 1) ? "  " : "");
            } else {
                snprintf(output[i], sizeof(output[i]), "%s  ", output[i]);
            }
        }
    }

    // Print the ASCII art
    for (int i = 0; i < row_count; i++) {
        printf("%s\n", output[i]);
    }

    return 0;
}