//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: realistic
#include <stdio.h>
#include <string.h>

int main() {
    char msg[100];
    int i, j;

    // Character to Morse code lookup table
    char *morseTable[] = {
        ".-", "-...", "-.-.", "-..", ".", 
        "..-.", "--.", "....", "..", ".---", 
        "-.-", ".-..", "--", "-.", "---", 
        ".--.", "--.-", ".-.", "...", "-", 
        "..-", "...-", ".--", "-..-", "-.--", 
        "--.."
    };
    
    // Alphabet lookup table
    char letterTable[] = "abcdefghijklmnopqrstuvwxyz";

    printf("Enter a message: ");
    fgets(msg, 100, stdin);

    // Remove newline character from input string
    msg[strcspn(msg, "\n")] = 0;

    for(i=0; i<strlen(msg); i++) {
        char c = tolower(msg[i]);

        if(c == ' ') {
            printf(" / ");
            continue;
        }

        // Find the index of the character in the letter table
        for(j=0; j<26; j++) {
            if(c == letterTable[j]) {
                printf("%s ", morseTable[j]);
                break;
            }
        }
    }

    return 0;
}