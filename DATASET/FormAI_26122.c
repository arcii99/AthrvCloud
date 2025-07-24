//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100];
    char str2[100];

    printf("Enter two strings to manipulate: ");

    fgets(str1, 100, stdin);
    fgets(str2, 100, stdin);

    // Remove the newline character from each string
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    // Print the original strings
    printf("Original String 1: %s\n", str1);
    printf("Original String 2: %s\n", str2);

    // Concatenate the two strings
    strcat(str1, str2);
    printf("Concatenated String: %s\n", str1);

    // Reverse the order of the characters in the concatenated string
    int len = strlen(str1);
    for(int i=0; i<len/2; i++) {
        char temp = str1[i];
        str1[i] = str1[len-i-1];
        str1[len-i-1] = temp;
    }
    printf("Reversed String: %s\n", str1);

    // Convert the string to UPPERCASE
    for(int i=0; i<len; i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] -= 'a' - 'A';
        }
    }
    printf("Uppercase String: %s\n", str1);

    // Copy the first 5 characters of the reversed string to a new string
    char new_str[6];
    strncpy(new_str, str1, 5);
    new_str[5] = '\0';
    printf("New String: %s\n", new_str);

    // Compare the new string with "hello"
    if(strcmp(new_str, "hello") == 0) {
        printf("New String is equal to 'hello'\n");
    } else {
        printf("New String is not equal to 'hello'\n");
    }

    return 0;
}