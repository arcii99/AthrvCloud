//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40
#define MAX_CHARS 128

char ascii[MAX_CHARS][MAX_HEIGHT][MAX_WIDTH + 1];
int ascii_width[MAX_CHARS];
int ascii_height[MAX_CHARS];

void init_ascii() {
    int i, j;

    for (i = 0; i < MAX_CHARS; i++) {
        ascii_width[i] = 0;
        ascii_height[i] = 0;
        for (j = 0; j < MAX_HEIGHT; j++) {
            ascii[i][j][0] = '\0';
        }
    }

    ascii['A'][0][0] =  "      /\\      ";
    ascii['A'][1][0] =  "     /  \\     ";
    ascii['A'][2][0] =  "    /    \\    ";
    ascii['A'][3][0] =  "   /------\\   ";
    ascii['A'][4][0] =  "  /        \\  ";
    ascii['A'][5][0] =  " /          \\ ";
    ascii['A'][6][0] =  "/            \\";
    ascii_width['A'] = 14;
    ascii_height['A'] = 7;

    ascii['B'][0][0] =  "+------+  ";
    ascii['B'][1][0] =  "|      |  ";
    ascii['B'][2][0] =  "|      |  ";
    ascii['B'][3][0] =  "+------+  ";
    ascii['B'][4][0] =  "|      |  ";
    ascii['B'][5][0] =  "|      |  ";
    ascii['B'][6][0] =  "+------+  ";
    ascii_width['B'] = 10;
    ascii_height['B'] = 7;

    ascii['C'][0][0] =  "  +-----+ ";
    ascii['C'][1][0] =  " /       \\";
    ascii['C'][2][0] =  "/         ";
    ascii['C'][3][0] =  "|         ";
    ascii['C'][4][0] =  "\\         ";
    ascii['C'][5][0] =  " \\       /";
    ascii['C'][6][0] =  "  +-----+ ";
    ascii_width['C'] = 10;
    ascii_height['C'] = 7;

    // more letters here ...
}

void print_ascii(const char *str) {
    int i, j, k, len = strlen(str);
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < len; j++) {
            int c = str[j];
            for (k = 0; k < ascii_width[c]; k++) {
                putchar(ascii[c][i][k] ? ascii[c][i][k] : ' ');
            }
            putchar(' ');
        }
        putchar('\n');
    }
}

int main() {
    init_ascii();

    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    print_ascii(str);

    return 0;
}