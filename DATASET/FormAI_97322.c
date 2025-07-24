//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: invasive
#include <stdio.h>
#include <string.h>

// Function to convert alpha characters of text to Morse code
void alpha_to_morse(char input[], int len) {
    for (int i = 0; i < len; i++) {
        switch(input[i]) {
            case 'A':
            case 'a':
                printf(".- ");
                break;
            case 'B':
            case 'b':
                printf("-... ");
                break;
            case 'C':
            case 'c':
                printf("-.-. ");
                break;
            case 'D':
            case 'd':
                printf("-.. ");
                break;
            case 'E':
            case 'e':
                printf(". ");
                break;
            case 'F':
            case 'f':
                printf("..-. ");
                break;
            case 'G':
            case 'g':
                printf("--. ");
                break;
            case 'H':
            case 'h':
                printf(".... ");
                break;
            case 'I':
            case 'i':
                printf(".. ");
                break;
            case 'J':
            case 'j':
                printf(".--- ");
                break;
            case 'K':
            case 'k':
                printf("-.- ");
                break;
            case 'L':
            case 'l':
                printf(".-.. ");
                break;
            case 'M':
            case 'm':
                printf("-- ");
                break;
            case 'N':
            case 'n':
                printf("-. ");
                break;
            case 'O':
            case 'o':
                printf("--- ");
                break;
            case 'P':
            case 'p':
                printf(".--. ");
                break;
            case 'Q':
            case 'q':
                printf("--.- ");
                break;
            case 'R':
            case 'r':
                printf(".-. ");
                break;
            case 'S':
            case 's':
                printf("... ");
                break;
            case 'T':
            case 't':
                printf("- ");
                break;
            case 'U':
            case 'u':
                printf("..- ");
                break;
            case 'V':
            case 'v':
                printf("...- ");
                break;
            case 'W':
            case 'w':
                printf(".-- ");
                break;
            case 'X':
            case 'x':
                printf("-..- ");
                break;
            case 'Y':
            case 'y':
                printf("-.-- ");
                break;
            case 'Z':
            case 'z':
                printf("--.. ");
                break;
            default:
                break;
        }
    }
}

int main() {
    char text[100];
    printf("Enter the text: ");
    fgets(text, 100, stdin);
    int len = strlen(text);
    printf("Morse code: ");
    alpha_to_morse(text, len);
    return 0;
}