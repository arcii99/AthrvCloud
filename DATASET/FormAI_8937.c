//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: puzzling
#include <stdio.h>
#include <string.h>

void delay(int milliseconds) {
    for (int i = 0; i < 100000 * milliseconds; i++) {}
}

int main() {
    char message[100];
    printf("Enter a message in English: ");
    scanf("%[^\n]", message);

    printf("Converting message to Morse code...\n\n");
    delay(2000);

    for (int i = 0; i < strlen(message); i++) {
        char c = tolower(message[i]);  // Convert to lowercase

        switch (c) {
            case 'a':
                printf(".- ");
                break;
            case 'b':
                printf("-... ");
                break;
            case 'c':
                printf("-.-. ");
                break;
            case 'd':
                printf("-.. ");
                break;
            case 'e':
                printf(". ");
                break;
            case 'f':
                printf("..-. ");
                break;
            case 'g':
                printf("--. ");
                break;
            case 'h':
                printf(".... ");
                break;
            case 'i':
                printf(".. ");
                break;
            case 'j':
                printf(".--- ");
                break;
            case 'k':
                printf("-.- ");
                break;
            case 'l':
                printf(".-.. ");
                break;
            case 'm':
                printf("-- ");
                break;
            case 'n':
                printf("-. ");
                break;
            case 'o':
                printf("--- ");
                break;
            case 'p':
                printf(".--. ");
                break;
            case 'q':
                printf("--.- ");
                break;
            case 'r':
                printf(".-. ");
                break;
            case 's':
                printf("... ");
                break;
            case 't':
                printf("- ");
                break;
            case 'u':
                printf("..- ");
                break;
            case 'v':
                printf("...- ");
                break;
            case 'w':
                printf(".-- ");
                break;
            case 'x':
                printf("-..- ");
                break;
            case 'y':
                printf("-.-- ");
                break;
            case 'z':
                printf("--.. ");
                break;
            case ' ':
                printf("  ");  // Word spacing
                break;
            default:
                printf("? ");  // Character not supported
        }

        fflush(stdout);  // Flush output
        delay(500);  // Pause before next character
    }

    printf("\n\nDone!");
    return 0;    
}