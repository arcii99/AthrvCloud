//FormAI DATASET v1.0 Category: String manipulation ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char phrase[100], new_phrase[100], reversed[100];

    printf("Hello! Let's manipulate some strings!\n\n");

    // Inputting a phrase
    printf("Enter a phrase: ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0';

    // Making every letter in the phrase upper case
    for(int i = 0; i < strlen(phrase); i++) {
        new_phrase[i] = toupper(phrase[i]);
    }
    printf("Your phrase in all CAPS is: %s\n", new_phrase);

    // Reversing the phrase
    int j = strlen(phrase)-1;
    for(int i = 0; i < strlen(phrase); i++) {
        reversed[i] = phrase[j];
        j--;
    }
    printf("Your phrase reversed is: %s\n", reversed);

    // Replacing vowels with "#"
    for(int i = 0; i < strlen(phrase); i++) {
        if(phrase[i] == 'a' || phrase[i] == 'e' || phrase[i] == 'i' || phrase[i] == 'o' || phrase[i] == 'u' || 
        phrase[i] == 'A' || phrase[i] == 'E' || phrase[i] == 'I' || phrase[i] == 'O' || phrase[i] == 'U') {
            phrase[i] = '#';
        }
    }
    printf("Your phrase with vowels replaced with '#' is: %s\n", phrase);

    printf("\nHooray! We're done manipulating strings!\n");

    return 0;
}