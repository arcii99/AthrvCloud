//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: high level of detail
#include <stdio.h>
#include <string.h>

/* This function converts a single character to its corresponding Morse code symbol */
char* charToMorse(char c){
    switch(c){
        /* Letters */
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
        /* Numbers */
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        /* Space */
        case ' ': return "/";
        /* Default */
        default : return "";
    }
}

/* This function converts a string of text to its corresponding Morse code */
char* textToMorse(char* text){
    /* Allocate enough memory for the Morse code string */
    int size = strlen(text) * 5;
    char* morse = (char*) malloc(size);
    memset(morse, '\0', size);
    
    /* Convert each character to its corresponding Morse code symbol */
    for(int i = 0; i < strlen(text); i++){
        char* symbol = charToMorse(text[i]);
        strcat(morse, symbol);
        if(i < strlen(text)-1 && text[i+1] != ' '){
            strcat(morse, " ");
        }
        free(symbol);
    }
    
    return morse;
}

/* Main method, takes a string input, and outputs the Morse code representation */
int main(){
    char input[100];
    printf("Enter text to convert to Morse code (max length 100): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    
    char* morse = textToMorse(input);
    printf("%s\n", morse);
    
    free(morse);
    return 0;
}