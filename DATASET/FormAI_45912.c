//FormAI DATASET v1.0 Category: String manipulation ; Style: careful
#include <stdio.h>
#include <string.h>

int main() {
    // Declare the char array and initialize it
    char str[] = "Hello, world!";

    // Print the original string
    printf("Original String: %s\n", str);

    // Reverse the string using a loop and swap function
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }

    // Print the reversed string
    printf("Reversed String: %s\n", str);

    // Count the number of vowels in the string using a loop
    int vowelCount = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
            || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            vowelCount++;
        }
    }

    // Print the number of vowels
    printf("Number of vowels: %d\n", vowelCount);

    // Replace the word "world" with "universe" using the strstr function
    char* replaceStr = "universe";
    char* worldStr = strstr(str, "world");
    int replaceIndex = worldStr - str;
    int replaceLen = strlen(replaceStr);
    strncpy(str + replaceIndex, replaceStr, replaceLen);
    strncpy(str + replaceIndex + replaceLen, worldStr + 5, len - replaceIndex - 5);

    // Print the replaced string
    printf("Replaced String: %s\n", str);

    // Split the string into separate words using the strtok function
    char* token = strtok(str, " ,!");
    while (token != NULL) {
        printf("Word: %s\n", token);
        token = strtok(NULL, " ,!");
    }

    return 0;
}