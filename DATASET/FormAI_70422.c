//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: excited
#include <stdio.h>
#include <string.h>

int main(){
    printf("Welcome to the Palindrome Checker! Let's see if your word is a palindrome!\n");
    char word[50];
    printf("Enter your word: ");
    scanf("%s", word);
    int length = strlen(word);
    int is_palindrome = 1;

    for(int i=0; i<length/2; i++){
        if(word[i] != word[length-i-1]){
            is_palindrome = 0;
            break;
        }
    }
    if(is_palindrome){
        printf("Congratulations! '%s' is a palindrome!\n", word);
    } else {
        printf("Sorry, '%s' is not a palindrome. Try again!\n", word);
    }

    printf("Try another word!\n");

    return 0;
}