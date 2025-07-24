//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Cryptic
#include <stdio.h>
#include <string.h>

int main(void)
{
    char text[255];
    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin);

    printf("Morse code conversion: ");

    for (int i = 0; i < strlen(text); i++)
    {
        // Handle spaces
        if (text[i] == ' ')
        {
            printf(" / ");
            continue;
        }

        // Convert to Morse code
        switch (text[i])
        {
            case 'a': printf(".- "); break;
            case 'b': printf("-... "); break;
            case 'c': printf("-.-. "); break;
            case 'd': printf("-.. "); break;
            case 'e': printf(". "); break;
            case 'f': printf("..-. "); break;
            case 'g': printf("--. "); break;
            case 'h': printf(".... "); break;
            case 'i': printf(".. "); break;
            case 'j': printf(".--- "); break;
            case 'k': printf("-.- "); break;
            case 'l': printf(".-.. "); break;
            case 'm': printf("-- "); break;
            case 'n': printf("-. "); break;
            case 'o': printf("--- "); break;
            case 'p': printf(".--. "); break;
            case 'q': printf("--.- "); break;
            case 'r': printf(".-. "); break;
            case 's': printf("... "); break;
            case 't': printf("- "); break;
            case 'u': printf("..- "); break;
            case 'v': printf("...- "); break;
            case 'w': printf(".-- "); break;
            case 'x': printf("-..- "); break;
            case 'y': printf("-.-- "); break;
            case 'z': printf("--.. "); break;
            default: break; // Ignore other characters
        }
    }

    return 0;
}