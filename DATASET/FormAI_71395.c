//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 30
#define MAX_CHARS 95

char asciiChars[MAX_CHARS][MAX_HEIGHT][MAX_WIDTH + 1];

void generateAsciiChars() {
    FILE *file = fopen("ascii_chars.txt", "r");
    if (!file) {
        printf("Error opening ascii_chars.txt");
        exit(1);
    }

    char line[MAX_HEIGHT * (MAX_WIDTH + 1)];
    int idx = 0;
    while (fgets(line, sizeof(line), file)) {
        int i, j;
        for (i = 0; i < MAX_HEIGHT; i++) {
            strncpy(asciiChars[idx][i], &line[i * (MAX_WIDTH + 1)], MAX_WIDTH);
            asciiChars[idx][i][MAX_WIDTH] = '\0';
        }
        idx++;
    }

    fclose(file);
}

void printAsciiArt(char *text) {
    int i, j, k;
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < strlen(text); j++) {
            if (text[j] < 32 || text[j] > 126) text[j] = '?';
            int idx = text[j] - 32;
            if (idx < 0 || idx >= MAX_CHARS) idx = 0;
            printf("%s", asciiChars[idx][i]);
        }
        printf("\n");
    }
}

int main() {
    generateAsciiChars();
    char text[256];
    printf("Enter text to convert to ASCII art:\n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character
    printAsciiArt(text);
    return 0;
}