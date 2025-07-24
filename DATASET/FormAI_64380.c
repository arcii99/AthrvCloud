//FormAI DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[100], c;
    int i;
    printf("Enter a string: ");
    fgets(input, 100, stdin); // get input from user
    printf("Original string: %s", input);

    // Convert all characters to uppercase
    for(i = 0; input[i] != '\0'; i++){
        input[i] = toupper(input[i]);
    }
    printf("Uppercase string: %s", input);

    // Remove spaces from the string
    i = 0;
    while(input[i] != '\0'){
        if(input[i] == ' '){
            memmove(&input[i], &input[i + 1], strlen(input) - i);
        } else {
            i++;
        }
    }
    printf("String without spaces: %s", input);

    // Reverse the string
    int length = strlen(input);
    for(i = 0; i < length/2; i++) {
        c = input[i];
        input[i] = input[length-i-1];
        input[length-i-1] = c;
    }
    printf("Reversed string: %s", input);

    // Count number of vowels and consonants in the string
    int vowels = 0, consonants = 0;
    for(i = 0; input[i] != '\0'; ++i) {
        c = input[i];
        if(isalpha(c)){
            if(c == 'A' || c == 'E' || c == 'I' ||
               c == 'O' || c == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}