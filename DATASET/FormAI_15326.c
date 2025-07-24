//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: creative
#include <stdio.h>
#include <string.h>

#define MAX_HEIGHT 10
#define MAX_WIDTH 10

char* ASCII[128][MAX_HEIGHT] = {
    {
        "     ██╗",
        "    ██╔╝",
        "   ██╔╝ ",
        "  ██╔╝  ",
        " ██╔╝   ",
        "╚═╝     "
    }, // ASCII code for letter 'A'
    {
        " ██████╗ ",
        "██╔════╝ ",
        "██║  ███╗",
        "██║   ██║",
        "╚██████╔╝",
        " ╚═════╝ "
    }, // ASCII code for letter 'B'
    // ... and so on for the rest of the alphabet and special characters.
};

void convertTextToASCII(char* text) {
    int n = strlen(text);
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < n; j++) {
            if (text[j] >= 32 && text[j] <= 127) {
                printf("%s ", ASCII[text[j]][i]);
            } else {
                printf("        ");
            }
        }
        printf("\n");
    }
}

int main() {
    char text[50];
    printf("Enter text to convert to ASCII art: ");
    scanf("%[^\n]", text);
    convertTextToASCII(text);
    return 0;
}