//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char *reverse(char str[]) {
    int len = strlen(str);
    char *rev_str = (char *) malloc(len + 1);
    for (int i = len-1, j = 0; i >= 0; i--, j++) {
        rev_str[j] = str[i];
    }
    rev_str[len] = '\0';
    return rev_str;
}

int main() {
    char str[MAX_SIZE], concat[MAX_SIZE], sub_str[MAX_SIZE];
    
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';  // remove newline character from string
    
    printf("Original String: %s\n", str);
    
    // Reversing the string
    char *rev_str = reverse(str);
    printf("Reversed String: %s\n", rev_str);
    free(rev_str);
    
    // Concatenating two strings
    printf("Enter a string to concatenate with the original string: ");
    fgets(concat, MAX_SIZE, stdin);
    concat[strcspn(concat, "\n")] = '\0';  // remove newline character from string
    strcat(str, concat);
    printf("Concatenated String: %s\n", str);
    
    // Finding a substring
    printf("Enter a substring to find in the original string: ");
    fgets(sub_str, MAX_SIZE, stdin);
    sub_str[strcspn(sub_str, "\n")] = '\0';  // remove newline character from string
    if (strstr(str, sub_str) != NULL) {
        printf("'%s' found in '%s'\n", sub_str, str);
    } else {
        printf("'%s' not found in '%s'\n", sub_str, str);
    }
    
    return 0;
}