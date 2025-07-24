//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: medieval
#include <stdio.h>
#include <string.h>

int main() {

    char input[1000];
    char output[1000];
    int i,j;

    printf("Welcome to the Alien Language Translator. Please enter the text you wish to translate:\n");

    fgets(input, 1000, stdin);

    // loop through each character in the input string
    for(i = 0; i < strlen(input); i++) {

        // convert the character to its ASCII code
        int ascii = (int)input[i];

        // if the character is a letter
        if(ascii >= 65 && ascii <= 90 || ascii >= 97 && ascii <= 122) {

            // add 13 to the ASCII code (rot13 encryption)
            ascii += 13;

            // if the character is now outside the range of letters
            if((ascii > 90 && ascii < 97) || ascii > 122) {

                // subtract 26 to get back within the range
                ascii -= 26;
            }
        }

        // add the translated character to the output string
        output[i] = (char)ascii;
    }

    printf("Your translated text is:\n%s\n", output);

    return 0;
}