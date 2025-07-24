//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: light-weight
#include <stdio.h>
#include <string.h>

int main() {
    char text[100], output[1000];
    int i, j, len;
    printf("Enter the text to convert to Morse code: ");
    fgets(text, 100, stdin); // read input from user
    len = strlen(text);

    char *morseCode[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
        "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
    }; // Morse code alphabet

    for (i = 0, j = 0; i < len; i++) {
        if (text[i] == ' ') {
            strcpy(output+j, " "); // add a space between words
            j++;
            continue;
        }

        if (text[i] >= 'a' && text[i] <= 'z') {
            // convert lowercase letters to uppercase
            text[i] = text[i] - 'a' + 'A';
        }

        if (text[i] >= 'A' && text[i] <= 'Z') {
            // convert letters to Morse code
            strcpy(output+j, morseCode[text[i]-'A']);
            j += strlen(morseCode[text[i]-'A']);
            strcpy(output+j, " "); // add a space between letters
            j++;
        }

        if (text[i] >= '0' && text[i] <= '9') {
            // convert numbers to Morse code
            strcpy(output+j, morseCode[text[i]-'0'+26]);
            j += strlen(morseCode[text[i]-'0'+26]);
            strcpy(output+j, " "); // add a space between digits
            j++;
        }
    }

    printf("Morse code: %s\n", output);

    return 0;
}