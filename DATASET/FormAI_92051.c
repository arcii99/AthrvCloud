//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <string.h>

void convertToMorse(char message[], char morseCode[][6]) {
    int i, j;
    char morseChar[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *morseTable[] = {
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
        "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
        "-.--", "--.."
    };
    
    for(i=0; i<strlen(message); i++) {
        if (message[i] == ' ') {
            printf("/ ");
        }
        else {
            for(j=0; j<36; j++) {
                if (toupper(message[i]) == morseChar[j]) {
                    printf("%s ", morseTable[j]);
                }
            }
        }
    }
}

int main() {
    char message[100];
    char morseCode[36][6];
    
    printf("Enter a message to convert to morse code: ");
    fgets(message, 100, stdin);
    printf("Morse Code: ");
    convertToMorse(message, morseCode);
    
    return 0;
}