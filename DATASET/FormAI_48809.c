//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *morse(char c) {
    switch (toupper(c)) {
        case 'A': return ".-";      case 'B': return "-...";    case 'C': return "-.-.";
        case 'D': return "-..";     case 'E': return ".";       case 'F': return "..-.";
        case 'G': return "--.";     case 'H': return "....";    case 'I': return "..";
        case 'J': return ".---";    case 'K': return "-.-";     case 'L': return ".-..";
        case 'M': return "--";      case 'N': return "-.";      case 'O': return "---";
        case 'P': return ".--.";    case 'Q': return "--.-";    case 'R': return ".-.";
        case 'S': return "...";     case 'T': return "-";       case 'U': return "..-";
        case 'V': return "...-";    case 'W': return ".--";     case 'X': return "-..-";
        case 'Y': return "-.--";    case 'Z': return "--..";    case '0': return "-----";
        case '1': return ".----";   case '2': return "..---";   case '3': return "...--";
        case '4': return "....-";   case '5': return ".....";   case '6': return "-....";
        case '7': return "--...";   case '8': return "---..";   case '9': return "----.";
        case ' ': return "/";                               // Space is /
        default:  return "";                                 // No conversion
    }
}

int main() {
    char input[256];
    printf("Enter text to convert to morse code: ");
    fgets(input, sizeof(input), stdin);         // Get input from user
    input[strlen(input)-1] = '\0';              // Remove trailing newline
    
    printf("\nMorse code: ");
    for (int i = 0; i < strlen(input); i++) {
        char *code = morse(input[i]);
        if (*code != '\0') {                     // Only print if a valid character
            printf("%s ", code);
        }
    }

    return 0;
}