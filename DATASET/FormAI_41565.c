//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char morse_code[36][6] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                          "-.-",".-..","--","-.","---",".--.","--.-",".-.","...",
                          "-","..-","...-",".--","-..-","-.--","--..","-----",".----",
                          "..---","...--","....-",".....","-....","--...","---..","----."};

char *alphabet = "abcdefghijklmnopqrstuvwxyz0123456789";

char *to_morse(char ch) {
    char *morse = NULL;
    ch = tolower(ch);
    if(ch >= 'a' && ch <= 'z')
        morse = morse_code[ch - 'a'];
    else if(ch >= '0' && ch <= '9')        
        morse = morse_code[ch - '0' + 26];
    return morse;
}

int main() {
    char input[101];
    printf("Enter the text to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove trailing newline character
    printf("\nMorse code: ");
    for(int i=0; i<strlen(input); i++) {
        char *morse = to_morse(input[i]);
        if(morse != NULL)
            printf("%s ", morse);
    }
    return 0;
}