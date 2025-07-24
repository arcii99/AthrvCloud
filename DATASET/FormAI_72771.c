//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <string.h>

void capitalizeString(char *str) {
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
}

void reverseString(char *str) {
    int len = strlen(str);
    char temp;
    for(int i = 0; i < len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

void concatenate(char *str1, char *str2, char *result) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i, j;
    for(i = 0; i < len1; i++) {
        result[i] = str1[i];
    }
    for(j = 0; j < len2; j++) {
        result[i+j] = str2[j];
    }
    result[i+j] = '\0';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // remove trailing newline character
    
    // example usage of string manipulation functions
    printf("\nOriginal String: %s\n", str);
    capitalizeString(str);
    printf("Capitalized String: %s\n", str);
    
    char reversed_str[100];
    strcpy(reversed_str, str);
    reverseString(reversed_str);
    printf("Reversed String: %s\n", reversed_str);
    
    char str1[50], str2[50], result[100];
    printf("\nEnter a string to concatenate: ");
    fgets(str1, 50, stdin);
    str1[strcspn(str1, "\n")] = 0; // remove trailing newline character
    printf("Enter another string to concatenate: ");
    fgets(str2, 50, stdin);
    str2[strcspn(str2, "\n")] = 0; // remove trailing newline character
    
    concatenate(str1, str2, result);
    printf("Concatenated string: %s\n", result);
    
    return 0;
}