//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: introspective
#include <stdio.h>
#include <string.h>

int main(){
    printf("Please enter a word: ");
    char word[100]; // maximum word length of 100 characters
    scanf("%s", word);
    int length = strlen(word);

    // creating a copy of the original word to compare later
    char originalWord[100];
    strcpy(originalWord, word);

    // reversing the word
    int i, j;
    char temp;
    for(i=0, j=length-1; i<j; i++, j--){
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }

    // comparing the reversed word with the original word
    if(strcmp(originalWord, word) == 0){
        printf("The word is a palindrome!");
    } else {
        printf("The word is not a palindrome.");
    }

    return 0;
}