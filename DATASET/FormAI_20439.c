//FormAI DATASET v1.0 Category: String manipulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* str, int start, int end) {
    if(start >= end) {
        return str;
    }

    // Swapping the first and last character
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Calling the recursion on the substring
    reverseString(str, start+1, end-1);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    int len = strlen(str);

    // Reversing the string recursively
    reverseString(str, 0, len-1);

    printf("The reversed string is: %s\n", str);

    return 0;
}