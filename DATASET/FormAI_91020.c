//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: configurable
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <string.h> 
#include <ctype.h> 

#define MAX_ALIEN_WORDS 1000 // maximum number of alien words in language set 
#define MAX_WORD_LENGTH 50 // maximum length of alien word 

int main() 
{ 
    char alienSet[MAX_ALIEN_WORDS][MAX_WORD_LENGTH]; 
    char engSet[MAX_ALIEN_WORDS][MAX_WORD_LENGTH]; 
    int numAlienWords; 
    printf("Enter number of words in alien language: "); 
    scanf("%d", &numAlienWords); 
    printf("Enter the alien language set: \n"); 
    for(int i=0; i<numAlienWords; i++){ 
        scanf("%s", alienSet[i]); 
    } 

    printf("Enter the corresponding English word set: \n"); 
    for(int i=0; i<numAlienWords; i++){ 
        scanf("%s", engSet[i]); 
    } 

    char alienWord[MAX_WORD_LENGTH]; 
    printf("Enter an alien word to be translated: "); 
    scanf("%s", alienWord); 

    // Compare entered word with each word in alien language set 
    for(int i=0; i<numAlienWords; i++){ 
        if(strcmp(alienWord, alienSet[i]) == 0){ // if the match is found 
            printf("Translated word: %s", engSet[i]); 
            return 0; 
        } 
    } 
    printf("Error: Word not found in alien language set."); 
    return 0; 
}