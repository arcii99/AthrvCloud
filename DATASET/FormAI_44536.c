//FormAI DATASET v1.0 Category: Text processing ; Style: imaginative
#include <stdio.h>
#include <string.h>

// function to capitalize the first letter of each word in a sentence
void capitalize(char *sentence) {
    int i;

    // capitalize the first letter of the sentence
    sentence[0] = toupper(sentence[0]);

    // loop through the sentence, capitalize the first letter of each word after space
    for (i = 0; i < strlen(sentence); i++) {
        if (sentence[i] == ' ') {
            sentence[i+1] = toupper(sentence[i+1]);
        }
    }
}

int main() {
    char sentence[100];

    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // remove the newline character at the end of the sentence
    sentence[strlen(sentence) - 1] = '\0';

    // capitalize the first letter of each word in the sentence
    capitalize(sentence);

    printf("Capitalized sentence: %s\n", sentence);

    return 0;
}