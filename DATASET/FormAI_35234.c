//FormAI DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100] = "Hello, ";
    char str2[50] = "world!";
    char str3[150];
    
    // Concatenate two strings
    strcpy(str3, str1);
    strcat(str3, str2);
    printf("Concatenated string: %s\n", str3);
    
    // Find the length of a string
    int len = strlen(str3);
    printf("Length of string: %d\n", len);
    
    // Copy a string
    char str4[150];
    strcpy(str4, str3);
    printf("Copied string: %s\n", str4);
    
    // Convert all characters in a string to uppercase
    for (int i = 0; i < len; i++) {
        if (str4[i] >= 'a' && str4[i] <= 'z') {
            str4[i] -= 32;
        }
    }
    printf("Uppercased string: %s\n", str4);
    
    // Reverse a string
    int start = 0;
    int end = len - 1;
    while (start < end) {
        char temp = str4[start];
        str4[start] = str4[end];
        str4[end] = temp;
        start++;
        end--;
    }
    printf("Reversed string: %s\n", str4);
    
    // Replace a substring in a string
    char substr[10] = "wor";
    char replace[10] = "WORLD";
    char* pos = strstr(str4, substr);
    if (pos != NULL) {
        int index = pos - str4;
        strncpy(str4 + index, replace, strlen(replace));
    }
    printf("Replaced string: %s\n", str4);
    
    return 0;
}