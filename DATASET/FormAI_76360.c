//FormAI DATASET v1.0 Category: String manipulation ; Style: expert-level
/*
 * C String Manipulation Example Program
 * Author: [Your Name]
 * Date: [Date of Creation]
 * Description: This program demonstrates the use of various string manipulation functions in C
 */

#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100    // Define the maximum length of a string

int main() {

    char string_1[MAX_STRING_LENGTH];   // Declare two character arrays to store two strings
    char string_2[MAX_STRING_LENGTH];
    int string_length_1, string_length_2;

    printf("Enter the first string: ");
    fgets(string_1, MAX_STRING_LENGTH, stdin);    // Take input of first string

    printf("Enter the second string: ");
    fgets(string_2, MAX_STRING_LENGTH, stdin);    // Take input of second string

    string_length_1 = strlen(string_1);   // Calculate the length of the first string
    string_length_2 = strlen(string_2);   // Calculate the length of the second string

    // Convert the first string to uppercase
    for (int i = 0; i < string_length_1; i++) {
        if (string_1[i] >= 'a' && string_1[i] <= 'z') {
            string_1[i] = string_1[i] - 32;
        }
    }
    printf("The first string in uppercase: %s", string_1);

    // Concatenate the two strings and print the result
    strcat(string_1, string_2);
    printf("The concatenated string: %s", string_1);

    // Count the number of vowels in the second string
    int vowel_count = 0;
    for (int i = 0; i < string_length_2; i++) {
        if (string_2[i] == 'a' || string_2[i] == 'e' || string_2[i] == 'i' || string_2[i] == 'o' || string_2[i] == 'u') {
            vowel_count++;
        }
    }
    printf("The number of vowels in the second string: %d", vowel_count);

    // Replace all occurrences of 'the' with 'THE' in the concatenated string
    char* result = strstr(string_1, "the");
    while (result != NULL) {
        strncpy(result, "THE", 3);
        result = strstr(result + 3, "the");
    }
    printf("The modified string: %s", string_1);

    return 0;
}