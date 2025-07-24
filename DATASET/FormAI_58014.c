//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Morse Code conversion function
char* morseCode(char ch) {
    static char *morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int index = (int) ch - 97;
    
    if (index < 0 || index > 25) {
        return NULL;
    }
    return morse[index];
}

// Function to convert text to Morse code
void convertTextToMorseCode(char text[], char *morseCodeText[]) {
    int textLength = strlen(text);
    int morseCodeLength = MAX_LENGTH;
    int i, j;
    
    for (i = 0; i < textLength; i++) {
        char ch = text[i];
        char *morse = morseCode(ch);
        
        if (morse == NULL) {
            continue;
        }
        
        int morseLength = strlen(morse);
        
        for (j = 0; j < morseLength; j++) {
            *morseCodeText++ = (char *) morse[j];
        }
        *morseCodeText++ = ' ';
    }
    *morseCodeText = '\0';
}

int main() {
    char text[MAX_LENGTH];
    printf("Enter the text to convert to Morse Code: ");
    fgets(text, MAX_LENGTH, stdin);
    text[strcspn(text, "\n")] = '\0';
    
    char *morseCodeText[MAX_LENGTH] = {};
    convertTextToMorseCode(text, morseCodeText);
    
    printf("Morse Code of the text '%s':\n", text);
    int i;
    for (i = 0; morseCodeText[i] != NULL; i++) {
        printf("%s", morseCodeText[i]);
    }
    printf("\n");
    
    return 0;
}