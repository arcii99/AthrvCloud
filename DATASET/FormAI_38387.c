//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: excited
#include<stdio.h>
#include<string.h>

// Morse code function
char* textToMorseCode(char letter) {
    switch (letter) {
        case 'a': return ".- ";
        case 'b': return "-... ";
        case 'c': return "-.-. ";
        case 'd': return "-.. ";
        case 'e': return ". ";
        case 'f': return "..-. ";
        case 'g': return "--. ";
        case 'h': return ".... ";
        case 'i': return ".. ";
        case 'j': return ".--- ";
        case 'k': return "-.- ";
        case 'l': return ".-.. ";
        case 'm': return "-- ";
        case 'n': return "-. ";
        case 'o': return "--- ";
        case 'p': return ".--. ";
        case 'q': return "--.- ";
        case 'r': return ".-. ";
        case 's': return "... ";
        case 't': return "- ";
        case 'u': return "..- ";
        case 'v': return "...- ";
        case 'w': return ".-- ";
        case 'x': return "-..- ";
        case 'y': return "-.-- ";
        case 'z': return "--.. ";
        case '1': return ".---- ";
        case '2': return "..--- ";
        case '3': return "...-- ";
        case '4': return "....- ";
        case '5': return "..... ";
        case '6': return "-.... ";
        case '7': return "--... ";
        case '8': return "---.. ";
        case '9': return "----. ";
        case '0': return "----- ";
        default: return " ";
    }
}

// Main function
int main() {
    char input[100];
    printf("Excited to convert your text to Morse Code, let's get started!\n");
    printf("Please enter the text you want to convert: ");
    scanf("%[^\n]s", input);
    printf("\n\nMorse code translation: \n");

    //Convert to Morse Code and Print
    for(int i=0;i<strlen(input);i++) {
        printf("%s", textToMorseCode(tolower(input[i])));
    }
    printf("\n\nThanks for using this program!\n");
    return 0;
}