//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <string.h>

// height of the ASCII art
#define HEIGHT 10

// define the characters to use for each ASCII character
char ascii_art[128][HEIGHT][6] = {
    {
        {"  ____  "},
        {" / ___| "},
        {"| |     "},
        {"| |___  "},
        {" \\____| "},
    },
    {
        {" _ "},
        {"| |"},
        {"| |"},
        {"| |"},
        {"|_|"},
    },
    {
        {"  ____  "},
        {" / __ \\ "},
        {"| |  | |"},
        {"| |__| |"},
        {" \\____/ "},
    },
    // continue defining ASCII art for the remaining characters
};

// function to print the ASCII art for a given string
void print_ascii_art(char *s) {
    int len = strlen(s);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < len; j++) {
            int c = (int)s[j];
            if (c < 0 || c > 127) {
                c = 63;
            }
            printf("%s ", ascii_art[c][i]);
        }
        printf("\n");
    }
}

// example usage
int main() {
    char *s = "Hello, World!";
    print_ascii_art(s);
    return 0;
}