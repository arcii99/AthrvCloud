//FormAI DATASET v1.0 Category: Text processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the number of occurrences of a character in a given string
int countOccurrences(char* str, char ch) {
    int count = 0;
    for(int i=0; str[i]; i++) {
        count += (str[i] == ch);
    }
    return count;
}

// Function to trim leading and trailing whitespace from a given string
char* trim(char* str) {
    int start = 0, end = strlen(str) - 1;
    while(start <= end && str[start] == ' ') start++;
    while(end >= start && str[end] == ' ') end--;
    int len = end - start + 1;
    char* trimmed = (char*)malloc(sizeof(char) * (len + 1));
    strncpy(trimmed, str + start, len);
    trimmed[len] = '\0';
    return trimmed;
}

int main() {
    char* input = "   This is a sample text with multiple occurrences of a character.   ";
    char ch = 't';

    // Count the number of occurrences of a character in the given string
    int count = countOccurrences(input, ch);
    printf("Number of occurrences of '%c' in the given string: %d\n", ch, count);

    // Trim the given string and print the trimmed string
    char* trimmed = trim(input);
    printf("Trimmed string: '%s'", trimmed);

    return 0;
}