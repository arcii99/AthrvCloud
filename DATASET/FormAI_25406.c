//FormAI DATASET v1.0 Category: Spell checking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Function to check word spellings
int check_word(char *word) {
    //check if the word contains any special characters
    for(int i=0; i<strlen(word); i++) {
        if(!isalpha(word[i]))
            return 0;
    }
    //Replace all upper case letters to lower case
    for(int i=0; i<strlen(word); i++) {
        if(isupper(word[i]))
            word[i] = tolower(word[i]);
    }
    //Compare the word with a list of correct spellings
    char correct_spellings[][20] = { "program", "variable", "control", "function", "algorithm" };
    for(int i=0; i<5; i++) {
        if(strcmp(correct_spellings[i], word) == 0)
            return 1;
    }
    return 0;
}

//Function to correct spelling errors in a sentence
void correct_sentence(char *sentence) {
    //Seperate words and check spellings of each word
    char *word = strtok(sentence, " ");
    while(word != NULL) {
        if(check_word(word) == 0) {
            printf("\nIncorrect spelling: %s", word);
            printf("\nSuggestions: ");
            //Generate suggestions using a futuristic algorithm
            for(int i=0; i<strlen(word); i++) {
                char temp = word[i];
                for(int j=0; j<26; j++) {
                    word[i] = 'a' + j;
                    if(check_word(word) == 1)
                        printf("%s ", word);
                }
                word[i] = temp;
            }
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    char sentence[100];
    printf("Enter a sentence to check spellings: ");
    fgets(sentence, 100, stdin);
    char *pos;
    if ((pos=strchr(sentence, '\n')) != NULL)
        *pos = '\0';
    correct_sentence(sentence);
    return 0;
}