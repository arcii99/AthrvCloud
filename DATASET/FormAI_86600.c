//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: protected
#include<stdio.h>
#include<string.h>

//Function to convert character to morse code
char* charToMorse(char c){
    switch(c){
        case 'a':
        case 'A': return ".-";
        case 'b':
        case 'B': return "-...";
        case 'c':
        case 'C': return "-.-.";
        case 'd':
        case 'D': return "-..";
        case 'e':
        case 'E': return ".";
        case 'f':
        case 'F': return "..-.";
        case 'g':
        case 'G': return "--.";
        case 'h':
        case 'H': return "....";
        case 'i':
        case 'I': return "..";
        case 'j':
        case 'J': return ".---";
        case 'k':
        case 'K': return "-.-";
        case 'l':
        case 'L': return ".-..";
        case 'm':
        case 'M': return "--";
        case 'n':
        case 'N': return "-.";
        case 'o':
        case 'O': return "---";
        case 'p':
        case 'P': return ".--.";
        case 'q':
        case 'Q': return "--.-";
        case 'r':
        case 'R': return ".-.";
        case 's':
        case 'S': return "...";
        case 't':
        case 'T': return "-";
        case 'u':
        case 'U': return "..-";
        case 'v':
        case 'V': return "...-";
        case 'w':
        case 'W': return ".--";
        case 'x':
        case 'X': return "-..-";
        case 'y':
        case 'Y': return "-.--";
        case 'z':
        case 'Z': return "--..";
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
        case ' ': return "/";
        default: return "ERROR";
    }
}

int main(){
    char text[100];
    char morse[100];
    int len,i;

    printf("Enter text to convert to morse code:\n");
    gets(text);

    len=strlen(text);

    //Convert each character to morse code and append to morse array
    for(i=0;i<len;i++){
        char* morse_char=charToMorse(text[i]);
        if(strcmp(morse_char,"ERROR")==0){
            printf("Error! Invalid Character\n");
            return 0;
        }
        strcat(morse,morse_char);
        strcat(morse," ");
    }

    //Print original text and corresponding morse code
    printf("Text: %s\n",text);
    printf("Morse Code: %s\n",morse);

    return 0;
}