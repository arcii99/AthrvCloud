//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: modular
#include <stdio.h>
#include <string.h>

void convertToMorse(char message[], char morse[]){
    char *morseTable[] = {".- ", "-... ", "-.-. ", "-.. ", ". ", "..-. ", "--. ", ".... ", ".. ", ".--- ", "-.- ", ".-.. ", "-- ", "-. ", "--- ", ".--. ", "--.- ", ".-. ", "... ", "- ", "..- ", "...- ", ".-- ", "-..- ", "-.-- ", "--.. ", " "};
    int i, j, messageLength;
    messageLength = strlen(message);
    for(i=0; i<messageLength; i++){
        if(message[i] == ' '){
            strcat(morse, " ");
        }
        else{
            j = *(message+i) - 'a';
            strcat(morse, morseTable[j]);
        }
    }
}

int main(){
    char message[100], morse[500];
    printf("Enter the message to be converted to Morse code: ");
    scanf("%[^\n]", message);
    convertToMorse(message, morse);
    printf("The Morse code is: %s", morse);
    return 0;
}