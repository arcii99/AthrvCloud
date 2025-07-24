//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10 // Number of rows in ASCII art
#define COLS 50 // Number of columns in ASCII art
#define MAX_LINE_LEN 255 // Maximum length of input string

// ASCII art for letters A-Z
const char* ASCII_ART[] = {
    "  __  ",
    " /__\\ ",
    "/_\\L_\\",
    " /_\\  ",
    "/_/_\\_\\",
    "  __  ",
    " /_ | ",
    "  | | ",
    "  | | ",
    "  |_| ",
    " _____ ",
    "|___ / ",
    "  |_ \\",
    " ___) |",
    "|____/ ",
    "  ___  ",
    " / _ \\ ",
    "| | | |",
    "| |_| |",
    " \\___/ ",
    " _____ ",
    "|___ / ",
    "  |_ \\",
    " ___) |",
    "|____/ ",
    "  ____ ",
    " /___\\",
    "|___ |",
    "  ___|",
    " |____|",
    " ______",
    "|____  |",
    "    / / ",
    "   / /  ",
    "  / /   ",
    " /_/    ",
    "  _____",
    " |__  /",
    "   / / ",
    "  / /_ ",
    " /____|",
    "  ____ ",
    " / ___|",
    "| |    ",
    "| |___ ",
    " \\____|",
    " ______",
    "|___  /",
    "   / / ",
    "  / /  ",
    " /_/   ",
    " _____ ",
    "|___ / ",
    "  |_ \\",
    " ___) |",
    "|____/ ",
    "   ___ ",
    "  / _ \\",
    " | (_) |",
    "  \\__, |",
    "    /_/ ",
    " _  __",
    "| |/ /",
    "| ' / ",
    "| . \\ ",
    "|_|\\_\\",
    " ____ ",
    "| ___|",
    "|___ \\",
    " ___) |",
    "|____/ ",
    " __  __",
    "|  \\/  |",
    "| |\\/| |",
    "| |  | |",
    "|_|  |_|",
    " _  _ ",
    "| || |",
    "| || |_",
    "|__   _|",
    "   |_| ",
    " __   _",
    "/_ | | |",
    " | | | |",
    " | |_| |",
    " |_| |_|",
    " _    _ ",
    "| |  | |",
    "| |  | |",
    "| |__| |",
    "|_____/ "
};

// Function that converts input string to uppercase
void to_uppercase(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

// Function that prints ASCII art of input string
void print_ascii_art(char str[]) {
    int len = strlen(str);
    char ch;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < len * COLS; col++) {
            ch = str[col / COLS];
            if (ch >= 'A' && ch <= 'Z') {
                printf("%c", ASCII_ART[ch - 'A'][row]);
            } else {
                printf("%c", ' ');
            }
        }
        printf("\n");
    }
}

int main() {
    char input[MAX_LINE_LEN];
    printf("Enter text to convert to ASCII art: ");
    fgets(input, MAX_LINE_LEN, stdin); // Read input string from user
    to_uppercase(input); // Convert input string to uppercase
    print_ascii_art(input); // Print ASCII art of input string
    return 0;
}