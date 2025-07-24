//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ART_SIZE 200
#define MAX_LINE_SIZE 100
#define ART_WIDTH 60

void draw_ascii_art(char* art);

int main() {
    char art[MAX_ART_SIZE + 1] = {0}; // Initialize all to 0
    char line[MAX_LINE_SIZE] = {0}; // Initialize all to 0
    printf("Welcome to the ASCII Art generator!\n");
    printf("Enter your art, up to %d characters. Press Ctrl-D when done:\n", MAX_ART_SIZE);
    while (fgets(line, MAX_LINE_SIZE, stdin)) {
        if (strlen(art) + strlen(line) > MAX_ART_SIZE) {
            printf("Maximum art size exceeded! Ignoring remaining input.\n");
            break;
        }
        strcat(art, line);
    }
    draw_ascii_art(art);
    return 0;
}

void draw_ascii_art(char* art) {
    int row = 0;
    int col = 0;
    int index = 0;
    int length = strlen(art);
    printf("\n");
    for (index = 0; index < length; index++) {
        if (isalpha(art[index])) {
            col++;
            putchar(art[index]);
        } else if (isspace(art[index])) {
            col++;
            putchar(' ');
        } else {
            putchar('\n');
            row++;
            col = 0;
            if (art[index] == '\n') {
                continue;
            }
            for (int i = 0; i < (ART_WIDTH - col) / 2; i++) {
                putchar(' ');
            }
            putchar(art[index]);
            col++;
        }
        if (col >= ART_WIDTH) {
            putchar('\n');
            row++;
            col = 0;
            for (int i = 0; i < (ART_WIDTH - col) / 2; i++) {
                putchar(' ');
            }
        }
        if (row >= 20) {
            printf("End of page. Press enter to continue...\n");
            getchar();
            printf("\n");
            row = 0;
        }
    }
    printf("\n");
}