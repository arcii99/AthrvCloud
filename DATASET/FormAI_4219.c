//FormAI DATASET v1.0 Category: String manipulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = *(str + i);
        *(str + i) = *(str + len - i - 1);
        *(str + len - i - 1) = temp;
    }
}

int main() {
    char input_str[MAX_LEN]; // string to store user input
    char reversed_str[MAX_LEN]; // string to store the reversed string
    
    printf("Enter a string to reverse: ");
    fgets(input_str, MAX_LEN, stdin);
    
    // remove newline character from input string
    char *pos = strchr(input_str, '\n');
    if (pos) {
        *pos = '\0';
    }
    
    // copy input string to reversed string
    strcpy(reversed_str, input_str);
    
    // reverse the reversed string
    reverse_string(reversed_str);
    
    // print both strings
    printf("Original string: %s\n", input_str);
    printf("Reversed string: %s\n", reversed_str);
    
    // check if the original and reversed strings are equal
    if (strcmp(input_str, reversed_str) == 0) {
        printf("The string is a palindrome!\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    // convert the original string to uppercase
    printf("Original string in uppercase: ");
    for (int i = 0; i < strlen(input_str); i++) {
        printf("%c", toupper(*(input_str + i)));
    }
    printf("\n");
    
    // remove all vowels from the reversed string
    char *vowels = "aeiouAEIOU";
    int index = 0;
    for (int i = 0; i < strlen(reversed_str); i++) {
        if (strchr(vowels, *(reversed_str + i)) == NULL) {
            *(reversed_str + index) = *(reversed_str + i);
            index++;
        }
    }
    *(reversed_str + index) = '\0';
    printf("Reversed string without vowels: %s\n", reversed_str);
    
    return 0;
}