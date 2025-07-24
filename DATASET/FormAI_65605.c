//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: portable
#include <stdio.h>
#include <string.h>

/* Function to convert text to ASCII art */
void text2ascii(char* text) {
    int len = strlen(text);
    int i, j;

    /* Print ASCII art for each character in the text */
    for (i = 0; i < len; i++) {
        /* Get ASCII code for the current character */
        int ascii = (int)text[i];
        
        /* Calculate row and column size for the ASCII art */
        int row_size = 5;
        int col_size = 5;
        
        /* Set the ASCII art for the current character */
        char art[row_size][col_size];
        
        /* Convert ASCII code to ASCII art */
        switch (ascii) {
            case 65: /* A */
            case 97: /* a */
                strcpy(art[0], "   /\\   ");
                strcpy(art[1], "  /  \\  ");
                strcpy(art[2], " /----\\ ");
                strcpy(art[3], "/      \\");
                strcpy(art[4], "");
                break;
            case 66: /* B */
            case 98: /* b */
                strcpy(art[0], "|------\\ ");
                strcpy(art[1], "|-----/| ");
                strcpy(art[2], "|----/ | ");
                strcpy(art[3], "|------/");
                strcpy(art[4], "");
                break;
            /* Add more cases for other ASCII characters */
            default:
                strcpy(art[0], "");
                strcpy(art[1], "");
                strcpy(art[2], "");
                strcpy(art[3], "");
                strcpy(art[4], "");
                break;
        }
        
        /* Print the ASCII art for the current character */
        for (j = 0; j < row_size; j++) {
            printf("%s\n", art[j]);
        }
    }
}

int main() {
    char text[] = "Hello, World!";
    text2ascii(text);
    return 0;
}