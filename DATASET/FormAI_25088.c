//FormAI DATASET v1.0 Category: Text processing ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count_occurrences(char* str, char* pattern) {
    int count = 0;
    int len = strlen(pattern);

    while(*str) {
        if(strncmp(str, pattern, len) == 0) {
            count++;
        }
        str++;
    }

    return count;
}

int main() {
    char str[1000];
    char pattern[100];
    int n;

    printf("Enter the text to be processed: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the pattern to search for: ");
    fgets(pattern, sizeof(pattern), stdin);

    // Remove newline characters from input strings
    str[strcspn(str, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    n = count_occurrences(str, pattern);

    printf("The pattern '%s' appears %d times in the text.\n", pattern, n);

    return 0;
}