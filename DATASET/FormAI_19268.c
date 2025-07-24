//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: artistic
#include<stdio.h>
#include<string.h>

int isPalindrome(char str[]){
    int len = strlen(str);
    for (int i=0; i<len/2; i++){
        if (str[i] != str[len-i-1])
            return 0;
    }
    return 1;
}

int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isPalindrome(str)){
        printf("Cool, you've entered a palindrome!\n");
        printf("Here it is in reverse: ");
        for (int i=strlen(str)-1; i>=0; i--){
            printf("%c", str[i]);
        }
        printf("\n");
    }
    else{
        printf("Sorry, but %s is not a palindrome.\n", str);
    }
    return 0;
}