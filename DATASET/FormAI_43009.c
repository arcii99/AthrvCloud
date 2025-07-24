//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* toMorseCode(char letter) {
    static char* morseCodes[] = {".-", "-...", "-.-.", "-..", ".", 
                                 "..-.", "--.", "....", "..", ".---", 
                                 "-.-", ".-..", "--", "-.", "---", 
                                 ".--.", "--.-", ".-.", "...", "-", 
                                 "..-", "...-", ".--", "-..-", "-.-.", 
                                 "--.."};
    if (isalpha(letter)) {
        return morseCodes[toupper(letter) - 'A'];
    } else if (isdigit(letter)) {
        return morseCodes[letter - '0' + 26];
    } else switch (letter) {
        case ' ': return "  ";
        case '.': return ".-.-.-";
        case ',': return "--..--";
        case '?': return "..--..";
        case '!': return "-.-.--";
        case '/': return "-..-.";
        case '@': return ".--.-.";
        default: return "";
    }
}

int main() {
    printf("CYBERPUNK MORSE CODE CONVERTER\n");
    printf("=============================\n\n");
    printf("Enter the text to convert to Morse code:\n");

    char input[256];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\r\n")] = 0; // remove trailing newline

    printf("\nConverting...\n\n");

    for (int i = 0; i < strlen(input); i++) {
        printf("%s ", toMorseCode(input[i]));
    }
    printf("\n");

    return 0;
}