//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: random
#include <stdio.h>
#include <string.h>

void convertToMorse(char message[]) {

    int messageSize = strlen(message);
    char morse[26][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

    for (int i = 0; i < messageSize; i++) {
        if (message[i] == ' ') {
            printf("/ ");
        }
        else {
            int index = message[i] - 'a';
            printf("%s ", morse[index]);
        }
    }
}

int main() {
    char message[100];

    printf("Enter a word or message to convert to Morse Code: ");
    scanf("%[^\n]", message);

    printf("Your message in Morse Code: ");
    convertToMorse(message);

    return 0;
}