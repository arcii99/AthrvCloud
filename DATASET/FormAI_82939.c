//FormAI DATASET v1.0 Category: String manipulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100

int main() {
    char string[MAX_STR_LEN] = "this is a string to manipulate";
    int len = strlen(string);

    printf("Original string: %s\n\n", string);

    // Reversing the string
    for(int i = 0; i < len/2; i++) {
        char temp = string[i];
        string[i] = string[len-1-i];
        string[len-1-i] = temp;
    }
    printf("Reversed string: %s\n\n", string);

    // Converting string to uppercase
    for(int i = 0; i < len; i++) {
        if(string[i] >= 'a' && string[i] <= 'z') {
            string[i] -= ('a' - 'A');
        }
    }
    printf("Uppercase string: %s\n\n", string);

    // Converting string to lowercase
    for(int i = 0; i < len; i++) {
        if(string[i] >= 'A' && string[i] <= 'Z') {
            string[i] += ('a' - 'A');
        }
    }
    printf("Lowercase string: %s\n\n", string);

    // Counting words in the string
    int word_count = 0;
    int in_word = 0;
    for(int i = 0; i < len; i++) {
        if(string[i] == ' ' || string[i] == '\n' || string[i] == '\t') {
            if(in_word) {
                word_count++;
            }
            in_word = 0;
        } else {
            in_word = 1;
        }
    }
    if(in_word) {
        word_count++;
    }
    printf("Number of words in the string: %d\n\n", word_count);

    return 0;
}