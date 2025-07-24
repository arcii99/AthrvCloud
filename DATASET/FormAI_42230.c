//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: portable
#include <stdio.h>

int main() {
    char alien_alphabet[] = {'m', 'x', 'g', 'l', 's', 'a', 'o', 'p', 't', 'u', 'e', 'd', 'n', 'w', 'i', 'c', 'y', 'h', 'f', 'b', 'k', 'v', 'j', 'z', 'q', '\0'}; //initialize alien alphabet
    char english_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'}; //initialize English alphabet
    char input[100];
    int i, j;

    printf("Enter your message in alien language: ");
    fgets(input, 100, stdin); //get input from user

    for (i = 0; input[i] != '\0'; i++) { //iterate through input string
        for (j = 0; alien_alphabet[j] != '\0'; j++) { //iterate through alien alphabet
            if (input[i] == alien_alphabet[j]) { //if letter in input matches alien alphabet letter
                printf("%c", english_alphabet[j]); //print corresponding English letter
                break;
            }
        }
        if (alien_alphabet[j] == '\0') { //if letter not found in alien alphabet
            printf("%c", input[i]); //print original letter
        }
    }
    return 0;
}