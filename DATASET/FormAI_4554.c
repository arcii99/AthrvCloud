//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert text to ASCII art
void text_to_ascii_art(char *string) {
    int len = strlen(string);

    // define the ASCII art characters
    char art_char[] = {'#','%','&','@','$','*','o','/','c','v','^'};

    int art_len = sizeof(art_char)/sizeof(char);

    for (int i=0; i<len; i++) {
        int ascii_val = (int) string[i];
        int art_val = ((ascii_val*art_len)/128)%art_len;

        if (ascii_val == 32) { // space character
            printf("\n"); // print a new line
        }
        else { // non-space character
            printf("%c ", art_char[art_val]); // print the corresponding ASCII art character
        }
    }
}

int main() {
    char string[100];
    printf("Enter a string: ");
    scanf("%[^\n]", string); // read the input string

    text_to_ascii_art(string); // convert the string to ASCII art
    return 0;
}