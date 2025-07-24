//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <string.h>

void printMorseCode(char message[], int size) {
    char *morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " "};
    char *alpha[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "};

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 27; j++) {
            if (message[i] == toupper(alpha[j][0])) {
                printf("%s ", morseCode[j]);
            }
        }
    }   
}

int main() {
    char message[100];
    printf("Enter message to convert to Morse code: ");
    fgets(message, sizeof(message), stdin);

    int size = strlen(message);
    message[size-1] = '\0';

    printf("\nMorse code message :\n");
    printMorseCode(message, size);

    return 0;
}