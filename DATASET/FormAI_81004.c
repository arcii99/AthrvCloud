//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: imaginative
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 100

int checkPalindrome(char *string, int length){
    int i, j;
    for(i=0, j=length-1; i<length/2; i++, j--){
        if(string[i]!=string[j])
            return 0;
    }
    return 1;
}

int main(){
    char palindrome[MAX_LENGTH];
    printf("\nWelcome to the Palindrome Checker!\n");
    while(1){
        printf("\nEnter a word to check (enter 'exit' to quit): ");
        scanf("%s", palindrome);
        if(strcmp(palindrome, "exit")==0){
            break;
        }
        int length = strlen(palindrome);
        if(checkPalindrome(palindrome, length))
            printf("The word is a palindrome!\n");
        else
            printf("The word is not a palindrome.\n");
    }
    printf("\nThank you for using the Palindrome Checker!\n");
    return 0;
}