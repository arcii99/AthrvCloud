//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

void convert(char capital, char* morseCode) {
    switch (capital) {
        case 'A': strcpy(morseCode,".-");
                  break;

        case 'B': strcpy(morseCode,"-...");
                  break;

        case 'C': strcpy(morseCode,"-.-.");
                  break;

        case 'D': strcpy(morseCode,"-..");
                  break;

        case 'E': strcpy(morseCode,".");
                  break;

        case 'F': strcpy(morseCode,"..-.");
                  break;

        case 'G': strcpy(morseCode,"--.");
                  break;

        case 'H': strcpy(morseCode,"....");
                  break;

        case 'I': strcpy(morseCode,"..");
                  break;

        case 'J': strcpy(morseCode,".---");
                  break;

        case 'K': strcpy(morseCode,"-.-");
                  break;

        case 'L': strcpy(morseCode,".-..");
                  break;

        case 'M': strcpy(morseCode,"--");
                  break;

        case 'N': strcpy(morseCode,"-.");
                  break;

        case 'O': strcpy(morseCode,"---");
                  break;

        case 'P': strcpy(morseCode,".--.");
                  break;

        case 'Q': strcpy(morseCode,"--.-");
                  break;

        case 'R': strcpy(morseCode,".-.");
                  break;

        case 'S': strcpy(morseCode,"...");
                  break;

        case 'T': strcpy(morseCode,"-");
                  break;

        case 'U': strcpy(morseCode,"..-");
                  break;

        case 'V': strcpy(morseCode,"...-");
                  break;

        case 'W': strcpy(morseCode,".--");
                  break;

        case 'X': strcpy(morseCode,"-..-");
                  break;

        case 'Y': strcpy(morseCode,"-.--");
                  break;

        case 'Z': strcpy(morseCode,"--..");
                  break;

        case '0': strcpy(morseCode,"-----");
                  break;

        case '1': strcpy(morseCode,".----");
                  break;

        case '2': strcpy(morseCode,"..---");
                  break;

        case '3': strcpy(morseCode,"...--");
                  break;

        case '4': strcpy(morseCode,"....-");
                  break;

        case '5': strcpy(morseCode,".....");
                  break;

        case '6': strcpy(morseCode,"-....");
                  break;

        case '7': strcpy(morseCode,"--...");
                  break;

        case '8': strcpy(morseCode,"---..");
                  break;

        case '9': strcpy(morseCode,"----.");
                  break;

        case ' ': strcpy(morseCode,"/");
                  break;

        default : strcpy(morseCode,"");
                  break;
    }
}

int main() {
    char message[100];
    char morse[1000];

    printf("Enter a message to be converted into Morse code: ");
    fgets(message, 100, stdin);

    for (int i=0; i<strlen(message); i++) {
        char capital = toupper(message[i]);
        char morseCode[5];
        convert(capital, morseCode);
        strcat(morse, morseCode);
        strcat(morse, " ");
    }

    printf("The Morse code of the message is:\n");
    puts(morse);

    return 0;
}