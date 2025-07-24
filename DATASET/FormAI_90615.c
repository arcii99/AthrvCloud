//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: automated
#include<stdio.h>
#include<string.h>
#define N 50 // Maximum length of the string

// Function to check if the string is palindrome or not
int isPalindrome(char *s){
    int len=strlen(s);
    char temp[N];
    int i;
    for(i=0;i<len;i++){
        temp[i]=s[len-1-i];
    }
    temp[i]='\0';

    if(strcmp(s,temp)==0){
        return 1; // Return true if the string is palindrome
    }
    else{
        return 0; // Return false if the string is not palindrome
    }
}

int main(){
    char str[N];

    printf("Enter a string: ");
    fgets(str, N, stdin);

    if (isPalindrome(str) == 1){
        printf("%s is a palindrome\n", str);
    }
    else{
        printf("%s is not a palindrome\n", str);
    }

    return 0;
}