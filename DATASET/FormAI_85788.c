//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: rigorous
#include <stdio.h>
#include <string.h>

// function to convert text to Morse code
void textToMorse(char *text)
{
    int i, j;
    // array to store Morse code equivalent of alphabets
    const char *MORSE_CODE[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", 
                                  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
                                  ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    for (i = 0; i < strlen(text); i++) { // loop through each character of the text
        if (text[i] == ' ') { // if the character is space, Morse code equivalent is '/'
            printf("/");
        }
        else if (text[i] >= 'a' && text[i] <= 'z') { // if the character is lowercase alphabet
            j = text[i] - 'a'; // calculate index of the alphabet
            printf("%s ", MORSE_CODE[j]); // print Morse code equivalent
        }
        else if (text[i] >= 'A' && text[i] <= 'Z') { // if the character is uppercase alphabet
            j = text[i] - 'A'; // calculate index of the alphabet
            printf("%s ", MORSE_CODE[j]); // print Morse code equivalent
        }
    }
}

int main()
{
    char text[100];
    printf("Enter text to convert to Morse code: ");
    fgets(text, sizeof(text), stdin); // read input text from user
    printf("Morse code: ");
    textToMorse(text); // call function to convert text to Morse code
    return 0;
}