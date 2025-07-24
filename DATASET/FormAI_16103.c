//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: sophisticated
#include <stdio.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40

// Function to print ASCII art text
void print_ascii_art(char* text) {
    char ascii_map[26][MAX_HEIGHT][MAX_WIDTH] = {
        // ASCII art for A
        {
            "        /\\        ",
            "       /  \\       ",
            "      /    \\      ",
            "     /------\\     ",
            "    /        \\    ",
            "   /          \\   ",
            "  /            \\  "
        },
        // ASCII art for B
        {
            "  ____   ",
            " | __ )  ",
            " |  _ \\  ",
            " | |_) | ",
            " |____/  "
        },
        // ASCII art for C
        {
            "   _____ ",
            "  / ____|",
            " | |     ",
            " | |     ",
            " | |____ ",
            "  \\_____|"
        },
        // Add more characters here...
    };
    
    // Determine maximum height of ASCII art characters
    int max_height = 0;
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            int index = text[i] - 'A';
            int height = 0;
            for (int j = 0; j < MAX_HEIGHT; j++) {
                if (ascii_map[index][j][0] != '\0') {
                    height++;
                }
            }
            if (height > max_height) {
                max_height = height;
            }
        }
    }
    
    // Print ASCII art for each character in the text
    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < strlen(text); j++) {
            if (text[j] >= 'A' && text[j] <= 'Z') {
                int index = text[j] - 'A';
                for (int k = 0; k < MAX_WIDTH; k++) {
                    if (ascii_map[index][i][k] != '\0') {
                        printf("%c", ascii_map[index][i][k]);
                    } else {
                        printf(" ");
                    }
                }
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    char* text = "HELLO WORLD";
    print_ascii_art(text);
    return 0;
}