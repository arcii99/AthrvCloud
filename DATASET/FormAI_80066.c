//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: genious
#include <stdio.h>
#include <string.h>

// Define an array of symbols in the alien language
char symbols[10] = {'!', '@', '#', '$', '%', '&', '*', '+', '-', '='};

// Define an array of corresponding translations in English
char translations[10][10] = {"Hello", "World", "Program", "Computer", "Science", 
                            "Great", "Fantastic", "Amazing", "Incredible", "Brilliant"};

// Function to translate a single word
void translate_word(char word[]) {
    int i;
    for(i=0; i<strlen(word); i++) {
        // Match the symbol to its corresponding translation
        if(word[i] == symbols[0]) {
            printf("%s ", translations[0]);
        } else if(word[i] == symbols[1]) {
            printf("%s ", translations[1]);
        } else if(word[i] == symbols[2]) {
            printf("%s ", translations[2]);
        } else if(word[i] == symbols[3]) {
            printf("%s ", translations[3]);
        } else if(word[i] == symbols[4]) {
            printf("%s ", translations[4]);
        } else if(word[i] == symbols[5]) {
            printf("%s ", translations[5]);
        } else if(word[i] == symbols[6]) {
            printf("%s ", translations[6]);
        } else if(word[i] == symbols[7]) {
            printf("%s ", translations[7]);
        } else if(word[i] == symbols[8]) {
            printf("%s ", translations[8]);
        } else if(word[i] == symbols[9]) {
            printf("%s ", translations[9]);
        }
    }
}

int main() {
    char sentence[100];
    printf("Enter a sentence in the alien language: ");
    fgets(sentence, 100, stdin);

    // Split the sentence into words using strtok()
    char *word = strtok(sentence, " ");

    while(word != NULL) {
        // Translate each word using the translate_word() function
        translate_word(word);
        // Move on to the next word
        word = strtok(NULL, " ");
    }

    return 0;
}