//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void convert_to_morse(char* message);
char convert_char(char character);

int main() {
    char message[MAX_LENGTH];
    
    printf("Enter a message to convert to Morse code:\n");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0'; // remove newline character
    
    convert_to_morse(message); // convert message to Morse code
    
    return 0;
}

void convert_to_morse(char* message) {
    int length = strlen(message);
    
    printf("Morse code translation of your message:\n");
    
    // loop through each character in message
    for (int i = 0; i < length; i++) {
        char character = toupper(message[i]);
        char morse_code = convert_char(character);
        
        if (morse_code == '-') {
            printf("%s ", "--"); // dash
        }
        else if (morse_code == '.') {
            printf("%s ", "-"); // dot
        }
        else {
            printf("%c ", character); // print original character
        }
    }
    
    printf("\n"); // print newline character
}

char convert_char(char character) {
    // returns Morse code equivalent of character
    
    switch (character) {
        case 'A':
            return '.-';
        case 'B':
            return '-...';
        case 'C':
            return '-.-.';
        case 'D':
            return '-..';
        case 'E':
            return '.';
        case 'F':
            return '..-.';
        case 'G':
            return '--.';
        case 'H':
            return '....';
        case 'I':
            return '..';
        case 'J':
            return '.---';
        case 'K':
            return '-.-';
        case 'L':
            return '.-..';
        case 'M':
            return '--';
        case 'N':
            return '-.';
        case 'O':
            return '---';
        case 'P':
            return '.--.';
        case 'Q':
            return '--.-';
        case 'R':
            return '.-.';
        case 'S':
            return '...';
        case 'T':
            return '-';
        case 'U':
            return '..-';
        case 'V':
            return '...-';
        case 'W':
            return '.--';
        case 'X':
            return '-..-';
        case 'Y':
            return '-.--';
        case 'Z':
            return '--..';
        default:
            return character;
    }
}