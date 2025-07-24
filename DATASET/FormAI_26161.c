//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: automated
#include <stdio.h>
#include <string.h>

void convertToMorseCode(char message[]) {
    int length = strlen(message);
    int i;
    char morseCode[36][8] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"};
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    printf("Morse Code: ");
    for (i = 0; i < length; i++) {
        if (message[i] == ' ') {
            printf("   ");
        }else {
            char upperChar = toupper(message[i]);
            int index = strchr(characters, upperChar) - characters;
            
            if (index >= 0 && index <= 35) {
                printf("%s ", morseCode[index]);
            }
        }
    }
}

int main() {
    char message[100];
    printf("Enter a message to convert to Morse Code: ");
    fgets(message, sizeof(message), stdin);
    printf("Original Message: %s", message);
    convertToMorseCode(message);
    return 0;
}