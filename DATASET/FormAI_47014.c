//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: ultraprecise
#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);
    int i, j = len-1;
    char temp;
    for(i=0; i<len/2; i++) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        j--;
    }
}

int isPalindrome(char str[]) {
    char copyStr[strlen(str)+1];
    strcpy(copyStr, str);
    
    reverseString(copyStr);
    
    if(strcmp(str, copyStr) == 0)
        return 1;
    else
        return 0;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0'; // remove \n character from fgets
    
    if(isPalindrome(str))
        printf("%s is a palindrome.", str);
    else
        printf("%s is not a palindrome.", str);
        
    return 0;
}