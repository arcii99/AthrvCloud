//FormAI DATASET v1.0 Category: String manipulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* str) {
    int len = strlen(str);
    char* result = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        result[i] = str[len - 1 - i];
    }
    result[len] = '\0';
    return result;
}

int main() {
    char name[100];
    printf("Please enter your name: ");
    fgets(name, 100, stdin);
    strtok(name, "\n"); // remove trailing newline from input
    printf("Your name reversed is: %s\n", reverseString(name));

    char str1[100], str2[100];
    printf("Please enter the first string: ");
    fgets(str1, 100, stdin);
    strtok(str1, "\n"); // remove trailing newline from input

    printf("Please enter the second string to concatenate with the first: ");
    fgets(str2, 100, stdin);
    strtok(str2, "\n"); // remove trailing newline from input

    int len1 = strlen(str1), len2 = strlen(str2);
    char* result = malloc(sizeof(char) * (len1 + len2 + 1));
    strcpy(result, str1);
    strcat(result, str2);
    printf("The concatenated string is: %s\n", result);
    free(result);

    return 0;
}