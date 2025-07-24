//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80
#define MAX_CHARS 128
#define ASCII_START 32

char ascii[MAX_CHARS][MAX_HEIGHT][MAX_WIDTH];

void print_ascii(int character) {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        printf("%s\n", ascii[character][i]);
    }
}

bool generate_ascii(char *input) {
    memset(ascii, ' ', sizeof(ascii)); // Initialize with spaces
    int char_width, char_height;
    for (int c = ASCII_START; c < MAX_CHARS; c++) { // Iterate through all characters
        for (int i = 0; i < strlen(input); i++) { // Iterate through user input string
            if (input[i] == c) { // Character match
                char_width = strlen(ascii[c][0]);
                char_height = MAX_HEIGHT;
                for (int j = 0; j < strlen(ascii[c][0]); j++) { // Find character dimensions
                    if (ascii[c][0][j] == '\0') {
                        char_width = j;
                        break;
                    }
                }
                for (int j = 0; j < MAX_HEIGHT; j++) { 
                    if (ascii[c][j][0] == '\0') {
                        char_height = j;
                        break;
                    }
                }
                if (i + char_width > strlen(input)) { // Not enough space for character
                    return false;
                }
                for (int j = 0; j < char_height; j++) { // Insert character into array
                    ascii[c][j][(i * (char_width + 1))] = '\0';
                    strcat(ascii[c][j], input + i);
                    ascii[c][j][i] = '\0';
                }
                i += char_width;
            }
        }
    }
    return true;
}

int main() {
    char input[1024];
    printf("Enter text: ");
    fgets(input, 1024, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    for (int i = 0; i < strlen(input); i++) {
        input[i] = (char)toupper(input[i]); // Convert to uppercase
    }
    if (generate_ascii(input)) {
        for (int i = 0; i < strlen(input); i++) {
            print_ascii((int)input[i]);
        }
    } else {
        printf("Error: input too long\n");
    }
    return 0;
}