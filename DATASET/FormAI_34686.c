//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <string.h>

char *morse(char c){
    switch(c){
        case 'A': return ".-";
            break;
        case 'B': return "-...";
            break;
        case 'C': return "-.-.";
            break;
        case 'D': return "-..";
            break;
        case 'E': return ".";
            break;
        case 'F': return "..-.";
            break;
        case 'G': return "--.";
            break;
        case 'H': return "....";
            break;
        case 'I': return "..";
            break;
        case 'J': return ".---";
            break;
        case 'K': return "-.-";
            break;
        case 'L': return ".-..";
            break;
        case 'M': return "--";
            break;
        case 'N': return "-.";
            break;
        case 'O': return "---";
            break;
        case 'P': return ".--.";
            break;
        case 'Q': return "--.-";
            break;
        case 'R': return ".-.";
            break;
        case 'S': return "...";
            break;
        case 'T': return "-";
            break;
        case 'U': return "..-";
            break;
        case 'V': return "...-";
            break;
        case 'W': return ".--";
            break;
        case 'X': return "-..-";
            break;
        case 'Y': return "-.--";
            break;
        case 'Z': return "--..";
            break;
        case '0': return "-----";
            break;
        case '1': return ".----";
            break;
        case '2': return "..---";
            break;
        case '3': return "...--";
            break;
        case '4': return "....-";
            break;
        case '5': return ".....";
            break;
        case '6': return "-....";
            break;
        case '7': return "--...";
            break;
        case '8': return "---..";
            break;
        case '9': return "----.";
            break;
        case ' ': return "/";
            break;
        default: return "";
    }
}

int main(){
    char sentence[100];
    printf("Enter a sentence to convert to Morse code:\n");
    fgets(sentence, 100, stdin);
    printf("Morse code translation:\n");
    for(int i=0; i<strlen(sentence); i++){
        char c = toupper(sentence[i]);
        printf("%s ", morse(c));
    }
    printf("\n");
    return 0;
}