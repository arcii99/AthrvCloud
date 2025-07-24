//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: curious
#include <stdio.h>
#include <string.h>

// Alien language vocabulary
char alienWords[10][20] = {"gaw", "smoo", "snick", "thwap", "flak", "pssst", "kaboom", "glork", "oops", "yowza"};

// English translations of the alien words
char englishWords[10][20] = {"hello", "goodbye", "thank you", "sorry", "yes", "no", "explosion", "strange", "mistake", "excitement"};

// function to translate alien language to English
void translate(char *word) {

    int i;
    for(i = 0; i < 10; i++) {

        // compare the input word with the alien vocabulary
        if(strcmp(word, alienWords[i]) == 0) {

            // print the English translation
            printf("%s\n", englishWords[i]);

            // exit the function
            return;
        }
    }
    // if the input word is not found in the alien vocabulary, print an error message
    printf("I'm sorry, I do not understand the alien language.\n");
}

int main() {

    // prompt the user to enter an alien word
    printf("Please enter an alien word: ");

    // get the user input
    char word[20];
    scanf("%s", word);

    // translate the alien word to English
    translate(word);

    // exit the program
    return 0;
}