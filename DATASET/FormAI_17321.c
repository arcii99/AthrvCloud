//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

void morseCode(char);

int main() {
    char message[100];
    printf("Enter message in text to convert to Morse code: ");
    fgets(message, 100, stdin);

    // Remove newline character from message
    message[strcspn(message, "\n")] = 0;
    printf("Morse code equivalent is: ");

    for (int i = 0; i < strlen(message); i++) {
        char ch = message[i];
        // Convert each character to uppercase
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 'a' + 'A';
        }
        morseCode(ch);
        // Separate characters with a space
        printf(" ");
    }

    return 0;
}

void morseCode(char ch) {
    switch (ch) {
        case 'A':
            printf(".-");
            break;
        case 'B':
            printf("-...");
            break;
        case 'C':
            printf("-.-.");
            break;
        case 'D':
            printf("-..");
            break;
        case 'E':
            printf(".");
            break;
        case 'F':
            printf("..-.");
            break;
        case 'G':
            printf("--.");
            break;
        case 'H':
            printf("....");
            break;
        case 'I':
            printf("..");
            break;
        case 'J':
            printf(".---");
            break;
        case 'K':
            printf("-.-");
            break;
        case 'L':
            printf(".-..");
            break;
        case 'M':
            printf("--");
            break;
        case 'N':
            printf("-.");
            break;
        case 'O':
            printf("---");
            break;
        case 'P':
            printf(".--.");
            break;
        case 'Q':
            printf("--.-");
            break;
        case 'R':
            printf(".-.");
            break;
        case 'S':
            printf("...");
            break;
        case 'T':
            printf("-");
            break;
        case 'U':
            printf("..-");
            break;
        case 'V':
            printf("...-");
            break;
        case 'W':
            printf(".--");
            break;
        case 'X':
            printf("-..-");
            break;
        case 'Y':
            printf("-.--");
            break;
        case 'Z':
            printf("--..");
            break;
        case '0':
            printf("-----");
            break;
        case '1':
            printf(".----");
            break;
        case '2':
            printf("..---");
            break;
        case '3':
            printf("...--");
            break;
        case '4':
            printf("....-");
            break;
        case '5':
            printf(".....");
            break;
        case '6':
            printf("-....");
            break;
        case '7':
            printf("--...");
            break;
        case '8':
            printf("---..");
            break;
        case '9':
            printf("----.");
            break;
        default:
            printf("/");
    }
}