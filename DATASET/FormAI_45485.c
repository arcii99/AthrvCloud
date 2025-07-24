//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: genious
#include<stdio.h>
#include<string.h>

void checkPalindrome(char *word);

int main(){
    char word[100];

    printf("Welcome to the Palindrome Checker!\n");
    printf("Enter a word to check if it's a Palindrome:\n");

    fgets(word, sizeof(word), stdin);
    word[strcspn(word, "\n")] = 0; // remove newline character

    checkPalindrome(word);

    return 0;

}

void checkPalindrome(char *word){

    int length = strlen(word);
    int flag = 1;

    for(int i=0; i<length/2; i++){
        if(word[i] != word[length-i-1]){
            flag = 0;
            break; // exit loop if the word is not a palindrome
        }
    }

    if(flag){
        printf("Hurray! %s is a Palindrome\n", word);
    }
    else{
        printf("Oops! %s is not a Palindrome\n", word);
    }
}