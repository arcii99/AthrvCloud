//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: post-apocalyptic
#include<stdio.h>
#include<string.h>

int main(){
    char word[100];
    printf("Enter a string: ");
    scanf("%s", word);

    int start = 0;
    int end = strlen(word) - 1;
    int is_palindrome = 1;

    while(start < end){
        if(word[start] != word[end]){
            is_palindrome = 0;
            break;
        }
        start++;
        end--;
    }

    if(is_palindrome){
        printf("\n%s is a palindrome.", word);
    } else {
        printf("\n%s is not a palindrome.", word);
    }

    return 0;
}