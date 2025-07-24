//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {

    char text[100];
    int i, length, letter;

    const char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " ", "/", ""};
    const char *letters[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", " ", "\0"};

    printf("Enter text: ");
    fgets(text, 100, stdin);

    length = strlen(text);

    printf("Morse code:\n");

    for(i=0; i<length; i++) {
        
        letter = tolower(text[i]) - 'a';

        if(letter >= 0 && letter <= 25) { // letter is from a-z
            
            printf("%s ", morse_code[letter]);
            
        } else if(letter == 26) { // letter is a space
            
            printf("%s", morse_code[26]);
            
        } else if(letter == -85) { // letter is a newline character
            
            continue; // skip the newline character
            
        } else { // character is not a letter or space
            
            printf("%s ", morse_code[27]);
            
        }

    }

    return 0;

}