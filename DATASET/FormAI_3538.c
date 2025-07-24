//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    printf("Enter alien language sentence:\n");
    fgets(input, 1000, stdin); // read input from user
    
    int i, j;
    char output[1000] = ""; // initialize translated output
    
    for (i = 0; i < strlen(input); i++) {
        switch(input[i]) {
            case '1':
                strcat(output, "a"); // append 'a' to output for '1'
                break;
            case '2':
                strcat(output, "e"); // append 'e' to output for '2'
                break;
            case '3':
                strcat(output, "i"); // append 'i' to output for '3'
                break;
            case '4':
                strcat(output, "o"); // append 'o' to output for '4'
                break;
            case '5':
                strcat(output, "u"); // append 'u' to output for '5'
                break;
            default:
                break; // do nothing if character is not a vowel representation
        }
    }

    printf("Translated sentence: %s\n", output); // output translated sentence
    
    return 0; // end program
}