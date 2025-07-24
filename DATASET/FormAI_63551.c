//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//function to check if a word is misspelled
bool checkWord(char* word) {
    //list of correctly spelled words
    char* dictionary[] = {"apple", "banana", "cherry", "grape", "orange"};
    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);
    
    //convert word to lowercase for comparison
    for(int i = 0; word[i]; i++){
        word[i] = tolower(word[i]);
    }
    
    //search for word in dictionary
    for(int i = 0; i < dictSize; i++){
        if(strcmp(dictionary[i], word) == 0){
            return true;
        }
    }
    
    //if word is not found in dictionary, it is misspelled
    return false;
}

int main() {
    char input[100];
    
    //prompt user for input
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    
    //split input into words and check each word
    char* word = strtok(input, " ");
    while(word != NULL){
        //remove any trailing punctuation
        int len = strlen(word);
        if(ispunct(word[len-1])){
            word[len-1] = '\0';
        }
        
        //check if word is misspelled
        if(!checkWord(word)){
            printf("%s is misspelled\n", word);
        }
        
        //get next word
        word = strtok(NULL, " ");
    }
    
    return 0;
}