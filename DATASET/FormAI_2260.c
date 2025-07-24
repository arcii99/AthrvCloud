//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: complex
#include <stdio.h>
#include <string.h>

void convert_to_morse(char *input_string);

const char *morse_codes[] = {".-", "-...", "-.-.", "-..", ".", /* A-E */ 
                             "..-.", "--.", "....", "..", ".---", /* F-J */ 
                             "-.-", ".-..", "--", "-.", "---", /* K-O */ 
                             ".--.", "--.-", ".-.", "...", "-", /* P-T */ 
                             "..-", "...-", ".--", "-..-", "-.--", /* U-Y */ 
                             "--..", "-----", ".----", "..---", "...--", /* Z, 0-4 */
                             "....-", ".....", "-....", "--...", "---..", /* 5-9 */
                             "--..--", ".-.-.-", "..--..", "-.-.--"}; /* Punctuation marks*/

const char *alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,?"; /* Morse code alphabets*/

int main() {
    char input[200] = ""; /* initialize input string*/
    
    printf("Input the text to be converted to Morse Code: ");
    fgets(input, 200, stdin); /* retrieves string input from user*/
    input[strcspn(input, "\n")] = 0; /* removes newline from input string*/
    convert_to_morse(input); /* converts input string to Morse code*/
    
    return 0;
}

void convert_to_morse(char *input_string) {
    char *token;
    char *in_ptr;
    
    in_ptr = input_string;
    
    while ((token = strtok_r(in_ptr, " ", &in_ptr))) { /* break input string into space-separated tokens*/
        int i, j;
        for (j = 0; j < strlen(token); j++) {
            for (i = 0; i < strlen(alphabets); i++) {
                if (token[j] == alphabets[i]) { /* match character with its Morse code*/
                    printf("%s ", morse_codes[i]); /* print Morse code*/
                }
            }
        }
        printf("/ "); /* separate tokens with forward slash*/
    }
}