//FormAI DATASET v1.0 Category: String manipulation ; Style: accurate
#include <stdio.h>
#include <string.h>

int main() {
    char string1[50], string2[50], temp[50];
    int string_length;

    printf("Enter the first string: ");
    fgets(string1, 50, stdin);

    printf("Enter the second string: ");
    fgets(string2, 50, stdin);

    // Removing the newline character from string inputs
    string1[strcspn(string1, "\n")] = 0;
    string2[strcspn(string2, "\n")] = 0;

    // Finding length of the first string
    string_length = strlen(string1);

    // Reversing the first string
    for(int i=0; i<string_length/2; i++) {
        temp[i] = string1[i];
        string1[i] = string1[string_length-i-1];
        string1[string_length-i-1] = temp[i];
    }

    // Concatenating the first and second string
    strcat(string1, string2);

    // Converting the concatenated string to upper case
    for(int i=0; string1[i]!='\0'; i++) {
        if(string1[i] >= 'a' && string1[i] <= 'z') {
            string1[i] = string1[i] - 32;
        }
    }

    printf("The final string is: %s\n", string1);

    return 0;
}