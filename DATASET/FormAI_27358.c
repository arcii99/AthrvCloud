//FormAI DATASET v1.0 Category: String manipulation ; Style: thoughtful
#include <stdio.h>
#include <string.h>

int main() {
    // Declare and initialize a string
    char my_string[] = "Hello, World!";

    // Print the original string
    printf("Original string: %s\n\n", my_string);

    // Reverse the string using a for loop and swap method
    int length = strlen(my_string);
    for (int i = 0; i < length/2; i++) {
        char temp = my_string[i];
        my_string[i] = my_string[length - i - 1];
        my_string[length - i - 1] = temp;
    }

    // Print the reversed string
    printf("Reversed string: %s\n\n", my_string);

    // Count the number of vowels in the string
    int count = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < strlen(my_string); i++) {
        for (int j = 0; j < 5; j++) {
            if (my_string[i] == vowels[j]) {
                count++;
            }
        }
    }

    // Print the number of vowels in the string
    printf("Number of vowels in the string: %d\n\n", count);

    // Convert the string to uppercase
    for (int i = 0; i < strlen(my_string); i++) {
        my_string[i] = toupper(my_string[i]);
    }

    // Print the uppercase string
    printf("Uppercase string: %s\n\n", my_string);

    // Replace the first occurrence of a letter in the string
    char find = 'W';
    char replace = 'Z';
    char* index = strchr(my_string, find);
    if (index != NULL) {
        *index = replace;
    }

    // Print the string with the first occurrence of W replaced with Z
    printf("String with first occurrence of W replaced with Z: %s\n\n", my_string);

    return 0;
}