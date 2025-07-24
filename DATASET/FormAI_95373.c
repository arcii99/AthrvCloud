//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printChar(char c, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }
}

void printText(char* text) {
    char ascii[94][11] = {
        "         ", "    /\\\\   ", "   //\\\\   ", "  //  \\\\  ", " //    \\\\ ",
        "//======\\\\", "\\\\      //", " \\\\    // ", "  \\\\  //  ", "   \\\\//   ",
        "    \\/    ", "         ", "         ", "         ", "         ",
        "         ", "         ", "         ", "         ", "         ",
        "         ", "         ", "         ", "         ", "         ",
        "         ", "         ", "         ", "         ", "         ",
        "         ", "         ", "         ", "         ", "         ",
        "         ", "         ", "         ", "         ", "         ",
        "   _    ", " _( )_  ", "(_,...,_)", "         ", "         ",
        "         ", "   _    ", " _( )_  ", "(_,...,_)", "   _    ",
        " _( )_  ", "(_,...,_)", "         ", "    ____      ", "  /\\' .\\   ",
        " /: \\___\\  ", " \\' / . /  ", " \\' \\ / /  ", "  \\' \\/ /   ",
        "   \\'__/    ", "            ", "         ", "         ", "         ",
        "         ", "         ", "         ", "         ", "         ",
        "         ", "         ", "         ", "         ", "         ",
        "         ", "         ", "         ", "         ", "         ",
        "    __     ", "  /    )   ", " /    /_   ", "/    // \\  ", "\\_/_(_,/  ",
        "           ", "         ", "         ", "         ", "         ",
        " __   ", "/ _\\  ", "\\/    ", "/\\_/\\ ", "\\_\\_\\ ", "      ",
        "         ", "      ", "      ", "      ", "      ",
        " ____ ", "|___ \\/", "  __) |", " / __/ ", "|_____\\", "       ",
        "       ", "       ", "       ", "       ", "       "
    };
    
    int length = strlen(text);
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < length; j++) {
            int index = (int)text[j] - 32;
            if (index >= 0 && index <= 93) {
                printf("%s ", ascii[index][i] == '_' ? " " : "_");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    char text[100];
    printf("Enter text to convert to ASCII art:\n");
    fgets(text, 100, stdin);
    printf("\n");
    
    printText(text);
    
    return 0;
}