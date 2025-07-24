//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_palindrome(char *str);

int main(){
    char input_str[50];
    
    printf("Hey there! Let's check if your word is a palindrome!\n");
    printf("Enter a word: ");
    scanf("%s", input_str);
    
    if(check_palindrome(input_str) == 1){
        printf("Woohoo! '%s' is a palindrome! 😃\n", input_str);
    } else {
        printf("Oops! '%s' is not a palindrome. 😕\n", input_str);
    }
    
    return 0;
}

int check_palindrome(char *str){
    int i, j;
    j = strlen(str) - 1;
    
    for(i = 0; i < strlen(str)/2; i++){
        if(str[i] != str[j]){
            return 0;
        }
        j--;
    }
    
    return 1;
}