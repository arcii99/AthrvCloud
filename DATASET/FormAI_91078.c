//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100 // maximum length of input string
#define DOT_LENGTH 200 // length of a dot in milliseconds
#define DASH_LENGTH 600 // length of a dash in milliseconds

// morse code table
char *morse_table[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
    "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
    "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
    "-.--", "--..", ".----", "..---", "...--", "....-", ".....",
    "-....", "--...", "---..", "----.", "-----", "/", ""
};

// function to convert a character to morse code
void char_to_morse(char c)
{
    int idx, i;

    // convert to uppercase if necessary
    c = toupper(c);

    // find the character in the morse table
    idx = c - 'A';
    if (idx < 0 || idx > 25) {
        idx = 26; // if not found, use slash
    }

    // print the morse code
    for (i = 0; morse_table[idx][i]; i++) {
        switch (morse_table[idx][i]) {
            case '.':
                printf(".");
                break;
            case '-':
                printf("-");
                break;
        }
    }
}

// function to convert a string to morse code
void str_to_morse(char *str)
{
    int i, j, len;
    char c;

    len = strlen(str);

    // iterate through the string and convert each character to morse code
    for (i = 0; i < len; i++) {
        c = str[i];
        if (isspace(c)) {
            printf(" "); // if it's a space, print a space
        } else {
            char_to_morse(c);
            if (i < len-1 && !isspace(str[i+1])) {
                printf(" "); // if the next character is not a space, print a space
            }
        }
    }
    printf("\n"); // print a new line at the end
}

// main function
int main()
{
    char str[MAX_LENGTH];

    // get input string from user
    printf("Enter a string to convert to Morse code:\n");
    fgets(str, MAX_LENGTH, stdin);

    // remove newline character from input string
    str[strcspn(str, "\n")] = '\0';

    // convert input string to morse code
    str_to_morse(str);

    return 0;
}