//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(char *str){

    int start = 0;
    int end = strlen(str)-1;

    while (start < end){
        if (tolower(str[start]) != tolower(str[end])){
            return 0;
        }
        start++;
        end--;
    }
    return 1;

}

int main(){

    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);

    if (is_palindrome(input)){
        printf("The string is a palindrome.");
    } else {
        printf("The string is not a palindrome.");
    }

    return 0;
}