//FormAI DATASET v1.0 Category: String manipulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    
    char str1[100], str2[100];
    char temp;

    // Get user input for string 1
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; // Remove newline character from input

    // Get user input for string 2
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    // Create a copy of string 1
    char str1_copy[strlen(str1)+1];
    strcpy(str1_copy, str1);

    // Length of string 1
    int len_str1 = strlen(str1);

    // Reverse string 1
    for(int i = 0; i < len_str1/2; i++) {
        temp = str1[i];
        str1[i] = str1[len_str1-i-1];
        str1[len_str1-i-1] = temp;
    }

    // Compare string 1 to string 2
    int cmp = strcmp(str1, str2);

    // Convert string 1 to uppercase
    for(int i = 0; i < len_str1; i++) {
        if(str1[i] >= 'a' && str1[i] <= 'z') {
            str1[i] -= 32;
        }
    }

    // Find the first occurrence of string 2 in string 1
    char *found = strstr(str1, str2);

    // Replace all occurrences of string 2 in string 1 with "***"
    int index;
    int len_str2 = strlen(str2);
    char new_str1[100] = "";
    while(found != NULL) {
        index = found - str1;
        str1[index] = '*';
        str1[index+1] = '*';
        str1[index+2] = '*';
        strcat(new_str1, str1_copy);
        strcat(new_str1, str1+len_str2);
        strcpy(str1, new_str1);
        found = strstr(str1, str2);
    }

    // Print the manipulated string 1
    printf("The manipulated string is: %s\n", str1);

    return 0;
}