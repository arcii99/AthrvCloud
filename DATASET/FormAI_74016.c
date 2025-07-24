//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Configurable values:
int char_width = 4; // width of each character (default: 4)
int char_height = 5; // height of each character (default: 5)
const char* char_set = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()-=_+[]\\{}|;':\",./<>? "; // characters to use (default: all ASCII printable characters)
const char* ascii_art_chars = "@#*+:-. "; // ASCII art symbols to use (default: these 7)
int ascii_art_char_count = 7; // number of ASCII art symbols to use (default: 7)

// Helper function to convert a given character into its ASCII art representation
char get_ascii_art_char(char c) {
    int index = c % ascii_art_char_count;
    return ascii_art_chars[index];
}

// Main function to convert a given string into ASCII art
void convert_to_ascii_art(char* str, int str_len) {
    int total_width = char_width * str_len;
    int total_height = char_height;
    char result[total_height][total_width + 1];
    memset(result, ' ', sizeof(result));
    for (int i = 0; i < str_len; i++) {
        char c = str[i];
        for (int y = 0; y < char_height; y++) {
            for (int x = 0; x < char_width; x++) {
                char art_char = get_ascii_art_char(c);
                result[y][i * char_width + x] = art_char;
            }
        }
    }
    for (int y = 0; y < total_height; y++) {
        printf("%s\n", result[y]);
    }
}

// Main function for user input and program execution
int main() {
    char input[256];
    printf("Enter a string to convert to ASCII art:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // remove newline character
    printf("Configurations:\n");
    printf("Character width: %d\n", char_width);
    printf("Character height: %d\n", char_height);
    printf("Selected character set: %s\n", char_set);
    printf("ASCII art symbols used: %s\n", ascii_art_chars);
    printf("ASCII art character count: %d\n", ascii_art_char_count);
    printf("\nResult:\n");
    convert_to_ascii_art(input, strlen(input));
    return 0;
}