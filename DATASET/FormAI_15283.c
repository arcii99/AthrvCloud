//FormAI DATASET v1.0 Category: Spell checking ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to check whether a given character is a letter or not
int isLetter(char c) {
    if (isalpha(c)) {
        return 1;
    }
    return 0;
}

// Function to check the spelling of a word in the dictionary
int checkSpelling(char word[]) {
    FILE *fp;
    char dictionary_word[50];

    fp = fopen("dictionary.txt","r");
    if (fp == NULL) {
        printf("Error opening dictionary file.");
        exit(0);
    }

    while (fgets(dictionary_word,50,fp) != NULL) {
        if (strcmp(dictionary_word,word) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int main() {
    char sentence[1000], word[50], misspelled_words[1000];
    int word_index = 0, sentence_index = 0, misspelled_word_index = 0, misspelled_word_flag = 0;

    printf("Enter a sentence to do spell check: ");
    fgets(sentence, 1000, stdin);

    while (sentence[sentence_index] != '\0') {
        if (isLetter(sentence[sentence_index])) {
            word[word_index++] = tolower(sentence[sentence_index]);
        } else {
            word[word_index] = '\0';
            if (word_index > 0) {
                if (!checkSpelling(word)) {
                    misspelled_words[misspelled_word_index++] = ' ';
                    for (int i=0; i<word_index; i++) {
                        misspelled_words[misspelled_word_index++] = word[i];
                    }
                    misspelled_word_flag = 1;
                }
                word_index = 0;
            }
        }
        sentence_index++;
    }

    if (misspelled_word_flag) {
        printf("The following words are spelled incorrectly: %s\n", misspelled_words);
    } else {
        printf("No spelling errors found in the sentence.\n");
    }

    return 0;
}