//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: thoughtful
#include <stdio.h>
#include <string.h>

void convertToMorse(char input[], char output[]);
void printMorse(char morse[]);

int main() {
    char input[100];
    char output[1000];

    printf("Enter your text here: ");
    scanf("%[^\n]%*c", input);

    convertToMorse(input, output);
    printMorse(output);

    return 0;
}

void convertToMorse(char input[], char output[]) {
    char morse[27][10] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","/"};
    int len = strlen(input);
    int outputIndex = 0;

    for (int i = 0; i < len; i++) {
        if (input[i] == ' ') {
            output[outputIndex] = '/';
            outputIndex++;
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            output[outputIndex] = morse[input[i] - 'a'][0];
            outputIndex++;
            output[outputIndex] = morse[input[i] - 'a'][1];
            outputIndex++;
            output[outputIndex] = morse[input[i] - 'a'][2];
            outputIndex++;
            output[outputIndex] = ' ';
            outputIndex++;
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[outputIndex] = morse[input[i] - 'A'][0];
            outputIndex++;
            output[outputIndex] = morse[input[i] - 'A'][1];
            outputIndex++;
            output[outputIndex] = morse[input[i] - 'A'][2];
            outputIndex++;
            output[outputIndex] = ' ';
            outputIndex++;
        }
    }

    output[outputIndex] = '\0';
}

void printMorse(char morse[]) {
    int len = strlen(morse);

    printf("Morse code: ");

    for (int i = 0; i < len; i++) {
        printf("%c", morse[i]);
    }

    printf("\n");
}