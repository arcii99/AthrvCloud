//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 100

bool check_palindrome(char s[]) {
    int left = 0, right = strlen(s) - 1;
    while(left < right) {
        if(s[left++] != s[right--]) 
            return false;      
    }
    return true;
}

void print_result(char s[]) {
    if(check_palindrome(s))
        printf("%s is a palindrome\n", s);
    else
        printf("%s is not a palindrome\n", s);
}

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    //Removing the '\n' character at the end
    str[strcspn(str, "\n")] = '\0';
    print_result(str);
    return 0;
}