//FormAI DATASET v1.0 Category: Spell checking ; Style: multivariable
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// function to check if a character is a valid letter 
int is_letter(char c) {
    if (isalpha(c) || c == '\'' || c == '-') {
        return 1;
    }
    return 0;
}

// function to remove whitespace and convert to lowercase
void sanitize_word(char *word) {
    int n = strlen(word);
    int i, j;
    for (i = 0, j = 0; i < n; i++) {
        if (!isspace(word[i])) {
            word[j++] = tolower(word[i]);
        }
    }
    word[j] = '\0';
}

// function to check if a word is spelled correctly
int spell_check(char *word) {
    // add your own implementation for spell checking here
    // for the sake of this example, just return 1 if the word is not "misspelled"
    if (strcmp(word, "misspelled") == 0) {
        return 0;
    }
    return 1;
}

// function to print a suggestion for a misspelled word
void suggest_word(char *word) {
    // add your own implementation for suggesting a word
    // for the sake of this example, just print a default message
    printf("Did you mean %s?\n", word);
}

int main() {
    char sentence[1000]; // input sentence
    char word[50]; // current word being checked
    char misspelled[50]; // buffer for storing misspelled words
    int i, j, n = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    for (i = 0; sentence[i] != '\0'; i++) {
        if (is_letter(sentence[i])) { // start of a new word
            for (j = 0; is_letter(sentence[i+j]); j++) { // get the whole word
                word[j] = sentence[i+j];
            }
            word[j] = '\0';
            i += j; // skip to next non-letter character
            
            sanitize_word(word); // remove whitespace and convert to lowercase
            
            if (spell_check(word)) { // check if the word is spelled correctly
                printf("%s ", word);
            }
            else { // word is misspelled, suggest a correction
                suggest_word(word);
                strcpy(misspelled, word); // add to the list of misspelled words
                n++;
            }
        }
        else { // not a letter, just print the character
            printf("%c", sentence[i]);
        }
    }

    if (n > 0) { // print summary of misspelled words at the end
        printf("\nThe following %d words were misspelled:\n", n);
        for (i = 0; i < n; i++) {
            printf("%d. %s\n", i+1, misspelled);
        }
    }
    else { // no misspelled words
        printf("\nNo misspelled words found!\n");
    }

    return 0;
}