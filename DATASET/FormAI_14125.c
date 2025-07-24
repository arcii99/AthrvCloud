//FormAI DATASET v1.0 Category: Spell checking ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// function to check spellings
int check_spelling(char* word){
    // list of correct words
    char correct_words[5][20]={"apple", "banana", "orange", "grape", "mango"};
    // comparing the entered word with each correct word
    for(int i=0;i<5;i++){
        if(strcmp(word, correct_words[i]) == 0){
            printf("The word '%s' is spelled correctly.\n", word);
            return 1; // return 1 if spelled correctly
        }
    }
    printf("The word '%s' is spelled incorrectly.\nDid you mean: ", word);
    // printing suggestions for incorrectly spelled word
    for(int i=0; i<strlen(word); i++){
        char temp = word[i];
        for(char j='a'; j<='z'; j++){
            if(temp == j) continue; // skip if the same character
            word[i] = j; // replace the character with other character
            for(int k=0; k<5; k++){
                if(strcmp(word, correct_words[k]) == 0){
                    printf("%s ", word);
                }
            }
            word[i] = temp; // replace the character back to the original
        }
    }
    printf("\n");
    return 0; // return 0 if spelled incorrectly
}

// main function
int main(){
    char word[20];
    printf("Enter a word: ");
    scanf("%s", word);
    // converting word to lowercase
    for(int i=0; i<strlen(word); i++){
        word[i] = tolower(word[i]);
    }
    check_spelling(word); // calling function to check spelling
    return 0; // end of program
}