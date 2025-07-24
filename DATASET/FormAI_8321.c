//FormAI DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    int len = strlen(s), index=0, start=0, end=0, wordCount=0;

    // reverse the entire string
    while (index < len) {
        char temp = s[index];
        s[index] = s[len-1];
        s[len-1] = temp;
        index++;
        len--;
    }

    // reverse each word
    for (index = 0; index < strlen(s); index++) {
        if (s[index] == ' ') {
            end = index-1;

            // reverse the word
            while (start < end) {
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                start++;
                end--;
            }

            start = index+1;
            wordCount++;
        }
    }

    // reverse the last word
    end = strlen(s)-1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }

    return s;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, 100, stdin);

    printf("The original string is: %s", input);

    char* output = reverseWords(input);

    printf("The modified string is: %s", output);

    return 0;
}