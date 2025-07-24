//FormAI DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <string.h>

int main()
{
    char text[100];
    printf("Enter the text to be converted to Morse code:\n");
    fgets(text, 100, stdin); // input from the user

    int i, j;
    char code[27][5] = { // Morse code mapping for each letter
        {".-"},{"-..."},{"-.-."},{"-.."},{"."},{".-.."},{"--."},{"...."},{".."},{"-.--"},{"--"},{"-.-"},{".-."},{".-."},{"---"},{".--."},{"--.-"},{".-."},{"..."},{"-"},{"..-"},{"...-"},{".--"},{"-..-"},{"-.--"},{"--.."},{" "}
    };

    char letters[27] = { // Letters in the same order as Morse code mapping above
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' '
    };

    printf("The Morse code equivalent of the input is:\n");
    int length = strlen(text); // get the length of the text
    for (i = 0; i < length; i++) {
        // find the index of the current letter in the letters array
        for (j = 0; j < 27; j++) {
            if (tolower(text[i]) == letters[j]) {
                printf("%s ", code[j]); // print the Morse code equivalent
                break; // no need to search the rest of the array
            }
        }
        if (text[i] == '\n') {
            printf("\n"); // add newline after each complete input line
        }
    }

    return 0;
}