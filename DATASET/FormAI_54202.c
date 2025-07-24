//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: detailed
#include <stdio.h>
#include <string.h>

// Function to convert a single character to Morse code
void convert(char c) {
    switch(c) {
        case 'a':
        case 'A':
            printf(".- ");
            break;
        case 'b':
        case 'B':
            printf("-... ");
            break;
        case 'c':
        case 'C':
            printf("-.-. ");
            break;
        case 'd':
        case 'D':
            printf("-.. ");
            break;
        case 'e':
        case 'E':
            printf(". ");
            break;
        case 'f':
        case 'F':
            printf("..-. ");
            break;
        case 'g':
        case 'G':
            printf("--. ");
            break;
        case 'h':
        case 'H':
            printf(".... ");
            break;
        case 'i':
        case 'I':
            printf(".. ");
            break;
        case 'j':
        case 'J':
            printf(".--- ");
            break;
        case 'k':
        case 'K':
            printf("-.- ");
            break;
        case 'l':
        case 'L':
            printf(".-.. ");
            break;
        case 'm':
        case 'M':
            printf("-- ");
            break;
        case 'n':
        case 'N':
            printf("-. ");
            break;
        case 'o':
        case 'O':
            printf("--- ");
            break;
        case 'p':
        case 'P':
            printf(".--. ");
            break;
        case 'q':
        case 'Q':
            printf("--.- ");
            break;
        case 'r':
        case 'R':
            printf(".-. ");
            break;
        case 's':
        case 'S':
            printf("... ");
            break;
        case 't':
        case 'T':
            printf("- ");
            break;
        case 'u':
        case 'U':
            printf("..- ");
            break;
        case 'v':
        case 'V':
            printf("...- ");
            break;
        case 'w':
        case 'W':
            printf(".-- ");
            break;
        case 'x':
        case 'X':
            printf("-..- ");
            break;
        case 'y':
        case 'Y':
            printf("-.-- ");
            break;
        case 'z':
        case 'Z':
            printf("--.. ");
            break;
        case ' ':
            printf("/ ");
            break;
        default:
            break;
    }
}

int main() {
    char input[100];    // Input string
    printf("Enter a string: ");
    fgets(input, 100, stdin);  // Read input string from user

    int len = strlen(input);   // Length of input string
    input[len-1] = '\0';    // Removing the '\n' character at the end of the input string

    // Loop through the input string and print the Morse code for each character
    for(int i=0; i<len-1; i++) {
        convert(input[i]);
    }

    printf("\n");

    return 0;
}