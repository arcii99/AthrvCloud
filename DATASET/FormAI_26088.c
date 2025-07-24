//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: dynamic
#include <stdio.h>
#include <string.h>

// Function to convert character to Morse Code
char* charToMorse(char c){
    switch(c){
        case 'a': case 'A': return ".-";
        case 'b': case 'B': return "-...";
        case 'c': case 'C': return "-.-.";
        case 'd': case 'D': return "-..";
        case 'e': case 'E': return ".";
        case 'f': case 'F': return "..-.";
        case 'g': case 'G': return "--.";
        case 'h': case 'H': return "....";
        case 'i': case 'I': return "..";
        case 'j': case 'J': return ".---";
        case 'k': case 'K': return "-.-";
        case 'l': case 'L': return ".-..";
        case 'm': case 'M': return "--";
        case 'n': case 'N': return "-.";
        case 'o': case 'O': return "---";
        case 'p': case 'P': return ".--.";
        case 'q': case 'Q': return "--.-";
        case 'r': case 'R': return ".-.";
        case 's': case 'S': return "...";
        case 't': case 'T': return "-";
        case 'u': case 'U': return "..-";
        case 'v': case 'V': return "...-";
        case 'w': case 'W': return ".--";
        case 'x': case 'X': return "-..-";
        case 'y': case 'Y': return "-.--";
        case 'z': case 'Z': return "--..";
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
        default: return " ";
    }
}

int main(){
    char text[100], morse[1000]="", *token;
    printf("Enter text to convert to Morse Code:\n");
    fgets(text,100,stdin); // Read the input text from console
    text[strcspn(text,"\n")]='\0'; // Remove the trailing '\n' character
    
    token=strtok(text," "); // Tokenize the input text by space
    while(token!=NULL){
        for(int i=0;i<strlen(token);i++){
            strcat(morse,charToMorse(token[i]));
            strcat(morse," "); // Separate each character in the Morse code with a space
        }
        strcat(morse,"  "); // Separate each word in the Morse code with two spaces
        token=strtok(NULL," ");
    }
    printf("\nMorse Code:\n%s\n",morse); // Print the Morse code to console
    return 0;
}