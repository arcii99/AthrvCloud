//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: authentic
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 100

int length(char *str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

char to_upper(char ch){
    if(ch >= 'a' && ch <= 'z'){
        ch -= 32;
    }
    return ch;
}

int is_palindrome(char *str){
    int len = length(str);
    int i;
    for(i=0; i<len/2; i++){
        if(to_upper(str[i]) != to_upper(str[len-i-1])){
            return 0;
        }
    }
    return 1;
}

int main(){
    char str[MAX_SIZE];
    printf("Enter a string: ");
    gets(str);
    if(is_palindrome(str)){
        printf("\n%s is a palindrome!\n",str);
    }
    else{
        printf("\n%s is not a palindrome!\n",str);
    }
    return 0;
}