//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
                     "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", 
                     "..-", "...-", ".--", "-..-", "-.--", "--.."};

char* text[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", 
                "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", 
                "U", "V", "W", "X", "Y", "Z"};

void convertTextToMorseCode(char* message) {
    int i, j;
    char ch;

    printf("Message in Text: %s\n", message);

    printf("Message in Morse Code: ");
    for(i = 0; i < strlen(message); i++) {
        ch = toupper(message[i]);
        if(ch == ' ') {
            printf("  ");
        } else if(ch >= 'A' && ch <= 'Z'){
            j = ch - 'A';
            printf("%s ", morseCode[j]);
        }
    }
    printf("\n");
}

int main() {
    char message[100];

    printf("Enter the message to be converted to Morse Code: ");
    fgets(message, 100, stdin);
    message[strlen(message) - 1] = '\0';

    convertTextToMorseCode(message);

    return 0;
}