//FormAI DATASET v1.0 Category: String manipulation ; Style: complete
#include <stdio.h>
#include <string.h>

int main() {
    // Define a string
    char str[100] = "Hello World!";

    // Print the original string
    printf("Original String: %s\n", str);

    // Convert all the characters to uppercase
    for(int i = 0; str[i]; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32; 
        }
    }

    // Print the uppercase string
    printf("Uppercase String: %s\n", str);

    // Reverse the string
    int length = strlen(str);
    for(int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }

    // Print the reversed string
    printf("Reversed String: %s\n", str);

    // Extract a substring
    char subStr[20];
    int startIndex = 6;
    int endIndex = 10;
    int index = 0;
    for(int i = startIndex; i <= endIndex; i++) {
        subStr[index] = str[i];
        index++;
    }
    subStr[index] = '\0';

    // Print the extracted substring
    printf("Substring from index %d to %d: %s\n", startIndex, endIndex, subStr);

    return 0;
}