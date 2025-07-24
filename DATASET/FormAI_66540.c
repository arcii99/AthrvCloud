//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    printf("Welcome to the Text to Morse code converter!\n");
    printf("Please enter the text you wish to convert: \n");
    char input[100];
    fgets(input,100,stdin);

    printf("Input received!\n");

    printf("Converting...\n");
    char morse[1000];
    for(int i = 0; i < strlen(input); i++){
        switch(input[i]){
            case 'a':
            case 'A': strcat(morse, ".- "); break;
            case 'b':
            case 'B': strcat(morse, "-... "); break;
            case 'c':
            case 'C': strcat(morse, "-.-. "); break;
            case 'd':
            case 'D': strcat(morse, "-.. "); break;
            case 'e':
            case 'E': strcat(morse, ". "); break;
            case 'f':
            case 'F': strcat(morse, "..-. "); break;
            case 'g':
            case 'G': strcat(morse, "--. "); break;
            case 'h':
            case 'H': strcat(morse, ".... "); break;
            case 'i':
            case 'I': strcat(morse, ".. "); break;
            case 'j':
            case 'J': strcat(morse, ".--- "); break;
            case 'k':
            case 'K': strcat(morse, "-.- "); break;
            case 'l':
            case 'L': strcat(morse, ".-.. "); break;
            case 'm':
            case 'M': strcat(morse, "-- "); break;
            case 'n':
            case 'N': strcat(morse, "-. "); break;
            case 'o':
            case 'O': strcat(morse, "--- "); break;
            case 'p':
            case 'P': strcat(morse, ".--. "); break;
            case 'q':
            case 'Q': strcat(morse, "--.- "); break;
            case 'r':
            case 'R': strcat(morse, ".-. "); break;
            case 's':
            case 'S': strcat(morse, "... "); break;
            case 't':
            case 'T': strcat(morse, "- "); break;
            case 'u':
            case 'U': strcat(morse, "..- "); break;
            case 'v':
            case 'V': strcat(morse, "...- "); break;
            case 'w':
            case 'W': strcat(morse, ".-- "); break;
            case 'x':
            case 'X': strcat(morse, "-..- "); break;
            case 'y':
            case 'Y': strcat(morse, "-.-- "); break;
            case 'z':
            case 'Z': strcat(morse, "--.. "); break;
            case ' ': strcat(morse, "| "); break;
            case '\n': strcat(morse, "\n"); break;
            default: strcat(morse, "? "); break;
        }
    }

    printf("Conversion complete!\n");

    printf("The Morse code output is:\n");
    printf("%s\n", morse);

    return 0;
}