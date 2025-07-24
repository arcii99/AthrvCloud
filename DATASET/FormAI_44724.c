//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

char* convert_to_morse(char* text) {
    int len = strlen(text);
    char *morse_text = (char*)malloc(len*5 + 1); // Each character takes 5 Morse code characters at max
    
    for(int i=0; i<len; i++) {
        if(text[i] == ' ') {
            strcat(morse_text, " ");
            continue;
        }
        int index = tolower(text[i]) - 'a'; // Index for each character in morse_table
        if(index < 0 || index >= 26) {
            printf("Unknown character %c", text[i]);
            continue;
        }
        strcat(morse_text, morse_table[index]);
        strcat(morse_text, " ");
    }
    return morse_text;
}

int main() {
    char *text = malloc(100);
    printf("Enter the text to convert to Morse code: ");
    scanf("%[^\n]%*c", text);
    
    char *morse_text = convert_to_morse(text);
    
    printf("Morse code: %s", morse_text);
    
    free(text);
    free(morse_text);
    
    return 0;
}