//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: creative
//Welcome to our Morse Code conversion program!
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Defining the Morse code dictionary as a constant array of strings
const char* MCODE[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "/", ".----", "..---", "...--",
                            "....-", ".....", "-....", "--...", "---..", "----.", "-----" };

// Function to convert a single character to its Morse code equivalent
void charToMorse(char c)
{
    if(c == ' ') {
        printf("/");
    } else if(isalpha(c)) {
        int index = toupper(c) - 'A';
        printf("%s", MCODE[index]);
    } else if(isdigit(c)) {
        int index = c - '0' + 26;
        printf("%s", MCODE[index]);
    } else {
        printf("?");
    }
}

int main()
{
    char input[1000];
    printf("Enter the string you want to convert to Morse Code: ");
    fgets(input, 1000, stdin);

    printf("Morse Code Translation: ");

    for(int i = 0; i < strlen(input); i++)
    {
        charToMorse(input[i]);
        printf(" ");
    }

    printf("\nThank you for using our Morse Code Conversion Program!\n");

    return 0;
}