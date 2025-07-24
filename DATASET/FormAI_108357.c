//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printChar(char c, int n) {
    for (int i = 0; i < n; i++) {
        putchar(c);
    }
}

void printText(char *text, int n) {
    int len = strlen(text);
    int half = (n - len) / 2;
    if (half < 0) {
        half = 0;
    }
    printChar('*', n);
    putchar('\n');
    for (int i = 0; i < half; i++) {
        putchar('*');
        printChar(' ', n - 2);
        putchar('*');
        putchar('\n');
    }
    putchar('*');
    printChar(' ', (n - len - 2) / 2);
    printf("%s", text);
    printChar(' ', (n - len - 1) / 2);
    putchar('*');
    putchar('\n');
    for (int i = 0; i < half; i++) {
        putchar('*');
        printChar(' ', n - 2);
        putchar('*');
        putchar('\n');
    }
    printChar('*', n);
    putchar('\n');
}

int main() {
    char *text = "Text to ASCII Art Generator";
    printText(text, 60);
    return 0;
}