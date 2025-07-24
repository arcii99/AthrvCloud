//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <string.h>

char* toMorse(char letter);

int main(){
    char text[100];
    printf("Enter text to convert to Morse code:\n");
    scanf("%[^\n]%*c", text); //scans until the end of input line

    printf("\nMorse code:\n");

    for(int i = 0; i < strlen(text); i++){
        char letter = toupper(text[i]); //convert to uppercase
        if(letter == ' '){
            printf("    "); //four spaces for a space
        }
        else{
            char* morseCode = toMorse(letter);
            printf("%s   ", morseCode); //three spaces between each Morse code letter
            free(morseCode); //free the dynamic memory allocated by toMorse function
        }
    }

    printf("\n");
    return 0;
}

char* toMorse(char letter){
    char* morseCode = malloc(6*sizeof(char)); //allocate dynamic memory for Morse code string

    switch(letter){
        case 'A': strcpy(morseCode, ".-"); break;
        case 'B': strcpy(morseCode, "-..."); break;
        case 'C': strcpy(morseCode, "-.-."); break;
        case 'D': strcpy(morseCode, "-.."); break;
        case 'E': strcpy(morseCode, "."); break;
        case 'F': strcpy(morseCode, "..-."); break;
        case 'G': strcpy(morseCode, "--."); break;
        case 'H': strcpy(morseCode, "...."); break;
        case 'I': strcpy(morseCode, ".."); break;
        case 'J': strcpy(morseCode, ".---"); break;
        case 'K': strcpy(morseCode, "-.-"); break;
        case 'L': strcpy(morseCode, ".-.."); break;
        case 'M': strcpy(morseCode, "--"); break;
        case 'N': strcpy(morseCode, "-."); break;
        case 'O': strcpy(morseCode, "---"); break;
        case 'P': strcpy(morseCode, ".--."); break;
        case 'Q': strcpy(morseCode, "--.-"); break;
        case 'R': strcpy(morseCode, ".-."); break;
        case 'S': strcpy(morseCode, "..."); break;
        case 'T': strcpy(morseCode, "-"); break;
        case 'U': strcpy(morseCode, "..-"); break;
        case 'V': strcpy(morseCode, "...-"); break;
        case 'W': strcpy(morseCode, ".--"); break;
        case 'X': strcpy(morseCode, "-..-"); break;
        case 'Y': strcpy(morseCode, "-.--"); break;
        case 'Z': strcpy(morseCode, "--.."); break;
        case '0': strcpy(morseCode, "-----"); break;
        case '1': strcpy(morseCode, ".----"); break;
        case '2': strcpy(morseCode, "..---"); break;
        case '3': strcpy(morseCode, "...--"); break;
        case '4': strcpy(morseCode, "....-"); break;
        case '5': strcpy(morseCode, "....."); break;
        case '6': strcpy(morseCode, "-...."); break;
        case '7': strcpy(morseCode, "--..."); break;
        case '8': strcpy(morseCode, "---.."); break;
        case '9': strcpy(morseCode, "----."); break;
        default: strcpy(morseCode, ""); break; //for non-convertible characters
    }

    return morseCode;
}