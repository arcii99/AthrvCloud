//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: modular
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPalindrome(char *str);
void getWord(char *word);

int main() {
    char *word = (char*) malloc(100 * sizeof(char));    //allocate memory for the word
    getWord(word);    //get the word from user
    bool result = isPalindrome(word);    //check if it's a palindrome
    if(result) {
        printf("\n%s is a palindrome.", word);
    }
    else {
        printf("\n%s is not a palindrome.", word);
    }
    free(word);    //free the memory
    return 0;
}

bool isPalindrome(char *str) {
    int len = strlen(str);
    for(int i=0;i<len/2;i++) {
        if(str[i]!=str[len-1-i]) {    //check for mismatches
            return false;
        }
    }
    return true;
}

void getWord(char *word) {
    printf("Enter a word: ");
    scanf("%s", word);
}