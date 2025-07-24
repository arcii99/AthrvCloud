//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: random
#include <stdio.h>
#include <string.h>

void stripNewline(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            return;
        }
    }
}

int isPalindrome(char* str) {
    int length = strlen(str);
    for (int i = 0; i <= length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("Enter a word or phrase: ");
    char input[100];
    fgets(input, 100, stdin);
    stripNewline(input);
    
    if (isPalindrome(input)) {
        printf("Wow! %s is a palindrome!", input);
    } else {
        printf("%s is not a palindrome :( ", input);
    }
    
    return 0;
}