//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: single-threaded
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    char word[100];
    printf("Enter a word: ");
    scanf("%s", word);

    int length = strlen(word);
    int left = 0, right = length - 1;
    int is_palindrome = 1; // Initialize to true

    while (left < right) {
        // Make sure that both characters are alphabets
        while (!isalpha(word[left])) {
            left++;
        }
        while (!isalpha(word[right])) {
            right--;
        }

        // Convert both characters to lowercase
        char left_char = tolower(word[left]);
        char right_char = tolower(word[right]);

        if (left_char != right_char) {
            is_palindrome = 0; // Mark as false
            break;
        }

        left++;
        right--;
    }

    if (is_palindrome) {
        printf("%s is a palindrome!\n", word);
    } else {
        printf("%s is not a palindrome.\n", word);
    }

    return 0;
}