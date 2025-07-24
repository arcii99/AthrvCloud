//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <string.h>

// Converts input characters to ASCII art symbols
char toAscii(char ch) {
    switch(ch) {
        case 'a': return 64;
        case 'b': return 91;
        case 'c': return 62;
        case 'd': return 125;
        case 'e': return 94;
        case 'f': return 120;
        case 'g': return 47;
        case 'h': return 92;
        case 'i': return 33;
        case 'j': return 43;
        case 'k': return 67;
        case 'l': return 108;
        case 'm': return 77;
        case 'n': return 110;
        case 'o': return 111;
        case 'p': return 80;
        case 'q': return 113;
        case 'r': return 57;
        case 's': return 53;
        case 't': return 43;
        case 'u': return 85;
        case 'v': return 118;
        case 'w': return 119;
        case 'x': return 88;
        case 'y': return 89;
        case 'z': return 122;
        case ' ': return 32;
        default: return ch;
    }
}

int main(void) {
    char input[50];
    printf("Enter text here: ");
    fgets(input, 50, stdin);
    int len = strlen(input);

    printf("\n");
    printf("             ******  **********   **********   ***************  ********\n");
    printf("         ***** **   ****    **   ****    **   ****   ********   **    **\n");
    printf("        **    **    **     **    **     **    **    **         **     **\n");
    printf("              **    **    **            **           ********  ********\n");
    printf("             **     **     **           **                   ** **\n");
    printf("            **     **       **          **   ****************     **\n");
    printf("                        **  **    **  **    **   **********    **    **\n");
    printf("                         ** **    ** **     **    ********      ********\n");
    printf("\n");

    // Generate ASCII art from input
    for (int i = 0; i < len; i++) {
        char ch = toAscii(tolower(input[i]));
        for (int j = 0; j < ch; j++) {
            printf("=");
        }
        printf("\n");
    }

    printf("\n\nMade with love by a futuristic ASCII art generator\n");

    return 0;
}