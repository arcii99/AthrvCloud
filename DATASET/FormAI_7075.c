//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char convertCharToASCII(char ch) {
    if (ch == ' ') {
        return 32;
    }
    else if (ch >= 'A' && ch <= 'Z') {
        return ch + 6;
    }
    else if (ch >= 'a' && ch <= 'z') {
        return ch - 58;
    }
    else if (ch >= '0' && ch <= '9') {
        return ch + 17;
    }
    else {
        return ch;
    }
}

void generateASCIIArt(char *text) {
    int length = strlen(text);
    char asciiArt[length][9];

    for (int i = 0; i < length; i++) {
        char ch = convertCharToASCII(text[i]);  

        for (int j = 0; j < 8; j++) {
            asciiArt[i][j] = (ch & (1 << (7 - j))) ? '#' : ' ';
        }

        asciiArt[i][8] = '\0';
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < length; j++) {
            printf("%s  ", asciiArt[j][i] == '#' ? "##" : "  ");
        }

        printf("\n");
    }
}

int main() {
    char text[100];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    generateASCIIArt(text);

    return 0;
}