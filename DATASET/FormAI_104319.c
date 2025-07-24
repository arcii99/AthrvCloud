//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: thoughtful
#include<stdio.h>
#include<string.h>

void main(){
    char word[30];
    int i, len, half, j;

    printf("Please enter a word: ");
    scanf("%s", word);

    len = strlen(word);
    half = len/2;

    for(i=0, j=len-1; i<half; i++, j--){
        if(word[i]!=word[j]){
            printf("The word is not a palindrome.\n");
            return;
        }
    }

    printf("The word is a palindrome.\n");
}