//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: brave
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(char *str) {
    int length = strlen(str);
    for(int i = 0; i < length/2; i++) {
        if(str[i] != str[length-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char user_input[1000];
    printf("Enter a string to check if it's a palindrome: "); 
    fgets(user_input, 1000, stdin);
    user_input[strcspn(user_input, "\n")] = 0; // remove newline character
    if(is_palindrome(user_input)) {
        printf("%s is a palindrome!\n", user_input);
    }
    else {
        printf("%s is not a palindrome :(\n", user_input);
    }
    return 0;
}