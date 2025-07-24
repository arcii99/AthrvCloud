//FormAI DATASET v1.0 Category: Spell checking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a valid letter
int isLetter(char c){
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    else
        return 0;
}

// Function to compare two strings and return 0 if they are equal
int compareStrings(char* s1, char* s2){
    if(strlen(s1) != strlen(s2))
        return 1;
    for(int i=0; i<strlen(s1); i++){
        if(tolower(s1[i]) != tolower(s2[i]))
            return 1;
    }
    return 0;
}

// Main function where all the magic happens
int main(){
    char* dictionary[10] = {"apple", "banana", "orange", "grape", "watermelon", "kiwi", "pineapple", "pear", "lemon", "peach"};
    int dictSize = 10;
    printf("\n\nWelcome to the most hilarious spell checker!\n");
    printf("Please type your sentence below:\n\n");
    char sentence[100];
    fgets(sentence, 100, stdin);
    char* word = strtok(sentence, " ,.-;:!?");
    while(word != NULL){
        int found = 0;
        for(int i=0; i<dictSize; i++){
            if(compareStrings(word, dictionary[i]) == 0){
                found = 1;
                break;
            }
        }
        if(found == 0){
            printf("\nThe word '%s' is not in our dictionary!\n", word);
            printf("Would you like to add it to the dictionary? (y/n)\n");
            char answer;
            scanf("%c", &answer);
            if(answer == 'y' || answer == 'Y'){
                char* newDictionary[dictSize+1];
                for(int i=0; i<dictSize; i++){
                    newDictionary[i] = dictionary[i];
                }
                newDictionary[dictSize] = word;
                dictSize++;
                printf("\n'%s' has been added to the dictionary!\n", word);
            }
        }
        word = strtok(NULL, " ,.-;:!?");
    }
    printf("\nThank you for using the most hilarious spell checker ever!\n\n");

    return 0;
}