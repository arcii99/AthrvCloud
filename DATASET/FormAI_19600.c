//FormAI DATASET v1.0 Category: Spell checking ; Style: thoughtful
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

// function to check if a word is valid or not
int checkWord(char* word, char* dict[]) 
{ 
    int i; 
    for (i=0; dict[i] != NULL; i++) 
        if (strcmp(dict[i], word) == 0) 
            return 1; 
    return 0; 
} 

int main() 
{ 
    // dictionary of valid words
    char* dict[] = { "apple", "banana", "orange", "grape", "mango", "peach", "pear", "pineapple", "kiwi", "watermelon", NULL }; 

    char sentence[100]; 
    printf("Enter a sentence: "); 
    fgets(sentence, sizeof(sentence), stdin); 
    
    // tokenize sentence into words
    char* word = strtok(sentence, " .\n"); 
    
    while (word != NULL) 
    { 
        if (!checkWord(word, dict)) 
            printf("'%s' is not a valid word!\n", word); 
        word = strtok(NULL, " .\n"); 
    } 
    return 0; 
}