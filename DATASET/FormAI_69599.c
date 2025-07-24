//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: Ada Lovelace
/* 
  Program: Text to Morse Code Converter
  Author: Ada Lovelace
  Date: October 10th, 1843
  Description: This program converts a text string to its Morse code equivalent and prints the result
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    // Define the Morse code array
    const char *morsecode[] = {
      ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", 
      "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", 
      "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", 
      "---..", "----.", "/", "--..--", ".-.-.-", "..--.."
    };
    
    // Declare variables
    char input[100];
    int i, j, len;
    
    // Prompt user for input
    printf("Enter a text string to convert to Morse code: ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);
    
    // Convert each character to Morse code
    for(i = 0; i < len; i++) {
        // Convert uppercase letters to Morse code
        if(input[i] >= 'A' && input[i] <= 'Z') {
            printf("%s ", morsecode[input[i] - 'A']);
        }
        // Convert lowercase letters to Morse code
        else if(input[i] >= 'a' && input[i] <= 'z') {
            printf("%s ", morsecode[input[i] - 'a']);
        }
        // Convert numbers to Morse code
        else if(input[i] >= '0' && input[i] <= '9') {
            printf("%s ", morsecode[input[i] - '0' + 26]);
        }
        // Convert whitespace and punctuation to Morse code
        else {
            switch(input[i]) {
                case ' ':
                    printf("/ ");
                    break;
                case ',': 
                    printf("--..-- ");
                    break;
                case '.': 
                    printf(".-.-.- ");
                    break;
                case '?': 
                    printf("..--.. ");
                    break;
                default: 
                    break;
            }
        }
    }
    
    printf("\n");
    
    return 0;
}