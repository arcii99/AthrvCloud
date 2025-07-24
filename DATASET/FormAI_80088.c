//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_MORSE_LENGTH 5000

char* text_to_morse(char letter);
void encode_to_morse(char* input_text, char* output_morse);

int main() {
    char input_text[MAX_INPUT_LENGTH];
    char output_morse[MAX_MORSE_LENGTH] = "";
    
    printf("Enter text to be encoded to Morse code (max length 1000 characters):\n");
    fgets(input_text, MAX_INPUT_LENGTH, stdin);
    input_text[strcspn(input_text, "\n")] = 0; // remove newline character
    
    encode_to_morse(input_text, output_morse);
    
    printf("\nEncoded message in Morse code:\n%s\n", output_morse);
    
    return 0;
}

// returns the Morse code equivalent of a single letter
char* text_to_morse(char letter) {
    switch (toupper(letter)) {
        case 'A':
            return ".- ";
        case 'B':
            return "-... ";
        case 'C':
            return "-.-. ";
        case 'D':
            return "-.. ";
        case 'E':
            return ". ";
        case 'F':
            return "..-. ";
        case 'G':
            return "--. ";
        case 'H':
            return ".... ";
        case 'I':
            return ".. ";
        case 'J':
            return ".--- ";
        case 'K':
            return "-.- ";
        case 'L':
            return ".-.. ";
        case 'M':
            return "-- ";
        case 'N':
            return "-. ";
        case 'O':
            return "--- ";
        case 'P':
            return ".--. ";
        case 'Q':
            return "--.- ";
        case 'R':
            return ".-. ";
        case 'S':
            return "... ";
        case 'T':
            return "- ";
        case 'U':
            return "..- ";
        case 'V':
            return "...- ";
        case 'W':
            return ".-- ";
        case 'X':
            return "-..- ";
        case 'Y':
            return "-.-- ";
        case 'Z':
            return "--.. ";
        case '0':
            return "----- ";
        case '1':
            return ".---- ";
        case '2':
            return "..--- ";
        case '3':
            return "...-- ";
        case '4':
            return "....- ";
        case '5':
            return "..... ";
        case '6':
            return "-.... ";
        case '7':
            return "--... ";
        case '8':
            return "---.. ";
        case '9':
            return "----. ";
        case ' ':
            return "   "; // 3 spaces to indicate word separation
        default:
            return " "; // return space for unrecognised characters
    }
}

// encodes input_text to Morse code and stores it in output_morse
void encode_to_morse(char* input_text, char* output_morse) {
    int i;
    for (i = 0; i < strlen(input_text); i++) {
        char* morse_code = text_to_morse(input_text[i]);
        strcat(output_morse, morse_code);
    }
}