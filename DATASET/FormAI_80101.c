//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: imaginative
#include <stdio.h>
#include <string.h>

int main() {
    char morse[26][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char input[255];
    printf("Enter text to convert to morse code: ");
    fgets(input, 255, stdin);
    printf("\nMorse Code:\n");
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\n') {
            printf("  ");
        } else if (input[i] >= 'a' && input[i] <= 'z') {
            printf("%s ", morse[input[i]-'a']);
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            printf("%s ", morse[input[i]-'A']);
        } else {
            printf("%c ", input[i]);
        }
    }
    return 0;
}