//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

vowelsCode(char ch);

int main() {
    char input[1000], output[1000] = {'\0'};
    int i, j = 0;

    // Get input string from user
    printf("Enter a string in English: ");
    fgets(input, 1000, stdin);

    // Iterate through each character of the input string
    for(i = 0; i < strlen(input); i++) {

        if(input[i] == ' ' || input[i] == ',' || input[i] == '.' || input[i] == '\n') {
            output[j++] = input[i];
        }
        
        // If the current character is a vowel, replace it with "meow"
        else if(strchr("AEIOUaeiou", input[i])) {
            output[j++] = 'm';
            output[j++] = 'e';
            output[j++] = 'o';
            output[j++] = 'w';
        }
        
        // If the current character is not a vowel, replace it with its corresponding C Cat code
        else {
            output[j++] = input[i];
            output[j++] = vowelsCode(input[i]);
        }
    }

    // Print the converted string
    printf("The C Cat version of your input string is: %s", output);

    return 0;
}

// Function to return the corresponding C Cat code of a given consonant
vowelsCode(char ch) {
    switch(ch) {
        case 'b': return 'o';
        case 'c': return 'a';
        case 'd': return 'e';
        case 'f': return 'i';
        case 'g': return 'u';
        case 'h': return 'e';
        case 'j': return 'o';
        case 'k': return 'a';
        case 'l': return 'e';
        case 'm': return 'i';
        case 'n': return 'u';
        case 'p': return 'e';
        case 'q': return 'o';
        case 'r': return 'a';
        case 's': return 'e';
        case 't': return 'i';
        case 'v': return 'u';
        case 'w': return 'e';
        case 'x': return 'o';
        case 'y': return 'a';
        case 'z': return 'e';        
        default:  return ' ';
    }
}