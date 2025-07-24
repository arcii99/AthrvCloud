//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: innovative
#include<stdio.h>
#include<string.h>

void main(){
    char word[50];
    char temp_word[50];
    int i, j, len, flag = 0;
    
    // User input
    printf("Enter a word: ");
    scanf("%s", word);
    
    // Store the word in reverse order
    len = strlen(word);
    for(i=len-1, j=0; i>=0; i--, j++) {
        temp_word[j] = word[i];
    }
    temp_word[j] = '\0';
    
    // Compare original and reversed word
    for(i=0; i<len; i++) {
        if(temp_word[i] != word[i]) {
            flag = 1;
            break;
        }
    }
    
    // Check for palindrome
    if(flag == 0) {
        printf("%s is a palindrome.\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }
}