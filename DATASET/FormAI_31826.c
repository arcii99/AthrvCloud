//FormAI DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STRING_SIZE 1000

bool isPalindrome(char *str) {
    int len = strlen(str);
    for (int i=0; i<len/2; i++) {
        if (str[i] != str[len-i-1]) {
            return false;
        }
    }
    return true;
}

bool containsWord(char *str, char *word) {
    char *pos = strstr(str, word);
    if (pos != NULL) {
        return true;
    }
    return false;
}

void reverseString(char *str) {
    int len = strlen(str);
    char temp;
    for (int i=0; i<len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

int main() {
    char str[MAX_STRING_SIZE];
    printf("Enter a string (max %d characters): ", MAX_STRING_SIZE-1);
    fgets(str, MAX_STRING_SIZE, stdin);
    
    // Remove newline character from input
    str[strcspn(str, "\n")] = '\0';
    
    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Check if string is a palindrome\n");
        printf("2. Check if string contains a word\n");
        printf("3. Reverse the string\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                if (isPalindrome(str)) {
                    printf("The string is a palindrome.\n");
                } else {
                    printf("The string is not a palindrome.\n");
                }
                break;
            case 2:
                char word[MAX_STRING_SIZE];
                printf("Enter the word to search for: ");
                scanf("%s", word);
                if (containsWord(str, word)) {
                    printf("The string contains the word.\n");
                } else {
                    printf("The string does not contain the word.\n");
                }
                break;
            case 3:
                reverseString(str);
                printf("The reversed string is: %s\n", str);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);
    
    return 0;
}