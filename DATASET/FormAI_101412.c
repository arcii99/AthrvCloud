//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

char ascii[MAX_HEIGHT][MAX_WIDTH]; // 25x80 ASCII art buffer

// Function to print ASCII art buffer
void print_ascii() {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        printf("%s\n", ascii[i]);
    }
}

// Generate ASCII art from input text
void generate_ascii(char text[]) {
    int length = strlen(text);
    int offset = 0;
    int row = 0;
    while (row < MAX_HEIGHT && offset < length) {
        int max_width = MAX_WIDTH;
        if (offset + max_width > length) {
            max_width = length - offset;
        }

        // Fill in row with characters from input text
        for (int i = 0; i < max_width; i++) {
            ascii[row][i] = text[offset + i];
        }

        if (max_width < MAX_WIDTH) {
            // Pad row with spaces
            for (int i = max_width; i < MAX_WIDTH; i++) {
                ascii[row][i] = ' ';
            }
        }

        offset += max_width;
        row++;
    }
}

int main() {
    char text[100];

    // Get input text from user
    printf("Enter text to convert to ASCII art:\n");
    fgets(text, 100, stdin);

    // Remove newline character from input text
    text[strcspn(text, "\n")] = 0;

    // Generate ASCII art
    generate_ascii(text);

    // Print ASCII art
    print_ascii();

    return 0;
}