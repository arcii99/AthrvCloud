//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <string.h>

char* morse_code(char ch);

int main(){
    char message[100];
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        char morse_char[6];
        if (message[i] == ' ') {
            printf("   ");
        } else {
            strcpy(morse_char, morse_code(toupper(message[i])));
            printf("%s ", morse_char);
        }
    }
    printf("\n");
    return 0;
}

char* morse_code(char ch){
    switch(ch){
        case 'A': return ".-";
        case 'B': return "-...";
        case 'C': return "-.-.";
        case 'D': return "-..";
        case 'E': return ".";
        case 'F': return "..-.";
        case 'G': return "--.";
        case 'H': return "....";
        case 'I': return "..";
        case 'J': return ".---";
        case 'K': return "-.-";
        case 'L': return ".-..";
        case 'M': return "--";
        case 'N': return "-.";
        case 'O': return "---";
        case 'P': return ".--.";
        case 'Q': return "--.-";
        case 'R': return ".-.";
        case 'S': return "...";
        case 'T': return "-";
        case 'U': return "..-";
        case 'V': return "...-";
        case 'W': return ".--";
        case 'X': return "-..-";
        case 'Y': return "-.--";
        case 'Z': return "--..";
        default: return "";
    }
}