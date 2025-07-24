//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: creative
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(char str[]) {
    int len = strlen(str);
    for (int i = 0; i <= len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (is_palindrome(str)) {
        printf("Yes, %s is a palindrome!\n", str);
    } else {
        printf("No, %s is not a palindrome.\n", str);
    }
    
    return 0;
}