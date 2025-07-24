//FormAI DATASET v1.0 Category: String manipulation ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to replace all occurrences of character 'c1' with 'c2' in the string 'str'
void replaceChar(char str[], char c1, char c2)
{
    int i;

    // iterate through all the characters in the string 'str'
    for (i = 0; i < strlen(str); i++) {
        
        // If the current character is equal to the character 'c1', replace it with 'c2'
        if (str[i] == c1) {
            str[i] = c2;
        }
    }
}

// Function to find the first occurrence of character 'c' in the string 'str'
int findChar(char str[], char c)
{
    int i;

    // iterate through all the characters in the string 'str'
    for (i = 0; i < strlen(str); i++) {

        // If the current character is equal to 'c', return its index value
        if (str[i] == c) {
            return i;
        }
    }

    // If character 'c' is not found in the string 'str', return -1
    return -1;
}

int main(void) {

    char str[100] = "Hello World!";
    char c1 = 'o';
    char c2 = '0';
    char c = 'W';

    // Replace all occurrences of character 'o' with '0'
    replaceChar(str, c1, c2);

    // Print the string 'str' after replacing all the occurrences of character 'o' with '0'
    printf("After replacing all occurrences of character 'o' with '0': \"%s\"\n", str);

    // Find the index of the first occurrence of character 'W'
    int index = findChar(str, c);

    // If the character 'W' is found in the string 'str', print its index value
    if (index != -1) {
        printf("Index of the first occurrence of character 'W': %d\n", index);
    } else {
        printf("Character 'W' not found in the string 'str'\n");
    }

    return 0;
}