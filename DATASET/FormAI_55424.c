//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60

int main(int argc, char *argv[]) {
    // Accept user input through command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }
    char *text = argv[1];

    // Define character patterns for each ASCII character
    char chars[128][MAX_HEIGHT][MAX_WIDTH] = {0};
    for (int i = 0; i < 128; i++) {
        char filename[15];
        sprintf(filename, "patterns/%d.txt", i);
        FILE *file = fopen(filename, "r");
        if (!file) {
            fprintf(stderr, "Error opening file: %s\n", filename);
            return 1;
        }
        for (int j = 0; j < MAX_HEIGHT; j++) {
            if (!fgets(chars[i][j], MAX_WIDTH + 1, file)) {
                fprintf(stderr, "Error reading file: %s\n", filename);
                return 1;
            }
            if (strchr(chars[i][j], '\n')) {
                *strchr(chars[i][j], '\n') = '\0'; // remove newline character
            }
        }
        fclose(file);
    }

    // Generate ASCII art
    int len = strlen(text);
    char output[MAX_HEIGHT][MAX_WIDTH * len + 1];
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH * len + 1; j++) {
            output[i][j] = ' ';
        }
    }
    for (int i = 0; i < len; i++) {
        int c = (int) text[i];
        if (c < 0 || c >= 128) {
            fprintf(stderr, "Error: Unsupported character: %c\n", text[i]);
            return 1;
        }
        for (int j = 0; j < MAX_HEIGHT; j++) {
            for (int k = 0; k < MAX_WIDTH; k++) {
                output[j][i * MAX_WIDTH + k] = chars[c][j][k];
            }
        }
    }
    for (int i = 0; i < MAX_HEIGHT; i++) {
        printf("%s\n", output[i]);
    }

    return 0;
}