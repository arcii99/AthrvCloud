//FormAI DATASET v1.0 Category: Spell checking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is an alphabet
int isAlpha(char c){
    return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}

// Function to perform the spell check
void spellCheck(char *word){
    int len = strlen(word);
    if(!isAlpha(word[0])){
        printf("\033[1;31m");  // Change text color to red
        printf("Error: %s starts with a non-alphabetic character!\n", word);
        printf("\033[0m");  // Reset text color
        return;
    }
    for(int i=1; i<len; i++){
        if(isAlpha(word[i])) continue;
        printf("\033[1;31m");  // Change text color to red
        printf("Error: %s contains illegal characters!\n", word);
        printf("\033[0m");  // Reset text color
        return;
    }
    printf("\033[1;32m");  // Change text color to green
    printf("No errors found in: %s\n", word);
    printf("\033[0m");  // Reset text color
}

int main(){
    char word[100];
    printf("Enter word to spell check: ");
    scanf("%[^\n]", word);
    spellCheck(word);
    return 0;
}