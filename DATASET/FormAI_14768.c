//FormAI DATASET v1.0 Category: Spell checking ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_word(char* word){
    // Check if word only contains letters
    for(int i = 0; i < strlen(word); i++){
        if(!isalpha(word[i])){
            return 0;
        }
    }
    return 1;
}

int is_misspelled(char* word, char** dictionary, int dictionary_length){
    // Check if word is in dictionary
    for(int i = 0; i < dictionary_length; i++){
        if(strcmp(word, dictionary[i]) == 0){
            return 0;
        }
    }
    return 1;
}

void print_suggestion(char* word, char** dictionary, int dictionary_length){
    // Generate suggestions by swapping letters
    char suggestion[strlen(word)];
    for(int i = 0; i < strlen(word); i++){
        strcpy(suggestion, word);
        for(int j = i+1; j < strlen(word); j++){
            // Swap letters
            char tmp = suggestion[i];
            suggestion[i] = suggestion[j];
            suggestion[j] = tmp;

            // Check if suggestion is in dictionary
            for(int k = 0; k < dictionary_length; k++){
                if(strcmp(suggestion, dictionary[k]) == 0){
                    printf("\nDid you mean: %s?", suggestion); 
                }
            }
        }
    }
}

int main(){
    // Sample dictionary
    char* dictionary[] = {"anaconda", "ape", "baboon", "badger", "beagle", "bear", "bobcat", "butterfly"};
    int dictionary_length = 8;

    // Sample sentence
    char sentence[] = "The qck brown fox jmps over the lazy dog";

    // Split sentence into words
    char* word = strtok(sentence, " ");
    while(word != NULL){
        // Convert word to lowercase
        for(int i = 0; i < strlen(word); i++){
            word[i] = tolower(word[i]);
        }

        // Check if word is valid and misspelled
        if(is_valid_word(word) && is_misspelled(word, dictionary, dictionary_length)){
            printf("\nMisspelled word: %s", word);

            // Print suggestions
            print_suggestion(word, dictionary, dictionary_length);
        }

        // Move to next word
        word = strtok(NULL, " ");
    }

    return 0;
}