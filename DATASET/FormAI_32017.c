//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, len, flag = 0;
    
    printf("Please enter a string (max length 100 characters): ");
    scanf("%[^\n]s", str);
    
    len = strlen(str);
    
    for(i = 0; i < len; i++) {
        if(str[i] != str[len - i - 1]) {
            flag = 1;
            break;
        }
    }
    
    if(flag == 1) {
        printf("The given string is not a palindrome.");
    }
    else {
        printf("The given string is a palindrome.");
    }
    
    return 0;
}