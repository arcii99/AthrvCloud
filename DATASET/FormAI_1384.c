//FormAI DATASET v1.0 Category: String manipulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to concatenate two C strings
char* concatenate_strings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // allocate memory for new string
    char* result = (char*)malloc((len1 + len2 + 1) * sizeof(char));

    // copy the first string into the result
    strcpy(result, str1);

    // concatenate the second string into the result
    strcat(result, str2);

    // return the new concatenated string
    return result;
}

// function to reverse a C string
void reverse_string(char* str) {
    int len = strlen(str);

    // swap characters starting from the middle
    for(int i = 0; i < len/2; i++) {
        char temp = str[len-i-1];
        str[len-i-1] = str[i];
        str[i] = temp;
    }
}

int main() {
    char* str1 = "Hello";
    char* str2 = "World";
    char* result_concatenated = concatenate_strings(str1, str2);
    printf("Concatenated string: %s\n", result_concatenated);

    char str3[] = "This is a test string";
    reverse_string(str3);
    printf("Reversed string: %s\n", str3);

    free(result_concatenated);

    return 0;
}