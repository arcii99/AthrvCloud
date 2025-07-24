//FormAI DATASET v1.0 Category: String manipulation ; Style: future-proof
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

/* This function takes two C strings and combines them into a new C string */
char* combineStrings(const char* str1, const char* str2) {
    char* newStr = malloc(strlen(str1) + strlen(str2) + 1);  // Allocate memory for the new string
    strcpy(newStr, str1);  // Copy the first string into the new string
    strcat(newStr, str2);  // Append the second string onto the new string
    return newStr;  // Return the new string
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    printf("Enter first string: ");
    fgets(str1, MAX_LENGTH, stdin);
    str1[strcspn(str1, "\n")] = 0;  // Remove trailing newline character

    printf("Enter second string: ");
    fgets(str2, MAX_LENGTH, stdin);
    str2[strcspn(str2, "\n")] = 0;  // Remove trailing newline character

    printf("First string: %s\n", str1);
    printf("Second string: %s\n", str2);

    char* combinedStr = combineStrings(str1, str2);
    printf("Combined string: %s\n", combinedStr);

    // Convert all characters in the combined string to uppercase
    for (int i = 0; i < strlen(combinedStr); i++) {
        combinedStr[i] = toupper(combinedStr[i]);
    }
    printf("Uppercase string: %s\n", combinedStr);

    // Reverse the order of characters in the combined string
    int len = strlen(combinedStr);
    for (int i = 0; i < len / 2; i++) {
        char temp = combinedStr[i];
        combinedStr[i] = combinedStr[len - i - 1];
        combinedStr[len - i - 1] = temp;
    }
    printf("Reversed string: %s\n", combinedStr);

    free(combinedStr);  // Free memory allocated for combined string
    return 0;
}