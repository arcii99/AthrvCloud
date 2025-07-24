//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char str[100];
    int i, len, flag = 0;
    
    printf("Welcome to Palindrome Checker Chatbot, I can tell you if a word/phrase is a palindrome or not! \n");
    printf("Enter word/phrase: ");
    scanf("%s", str);
    
    len = strlen(str);
    
    for(i=0;i<len;i++){
        if(str[i] != str[len-1-i]){
            flag = 1;
            break;
        }
    }
    
    if(flag == 0) 
        printf("Yes! Your word/phrase is a palindrome! I'm good at telling jokes too, wanna hear one?\n");
    else 
        printf("Oops! Your word/phrase is NOT a palindrome. Sorry, I cannot tell jokes now, try again with a palindrome!\n");
    
    return 0;
}