//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: active
#include <stdio.h>
#include <string.h>

// Morse code conversion function
void toMorse(char str[], char morse[][6]) {
    // Morse code reference array
    char* code[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
 
    int len = strlen(str);
    int i, j;

    // Convert each character to Morse code
    for (i = 0; i < len; i++) {
        if (str[i] == ' ') {
            strcpy(morse[i], "/");
        }
        else {
            j = str[i] - 'A';
            if (j < 0 || j > 25) {
                printf("Error: Invalid input string\n");
                return;
            }
            strcpy(morse[i], code[j]);
        }
    }
}

int main() {
    char str[100], morse[100][6];
    int i;

    // Input a string
    printf("Enter a string to convert into Morse code: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    // Convert the string to Morse code
    toMorse(str, morse);

    // Print the input string and its Morse code representation
    printf("\nInput string: %s\n", str);
    printf("Morse code: ");
    for (i = 0; i < strlen(str); i++) {
        printf("%s ", morse[i]);
    }
    printf("\n");

    return 0;
}