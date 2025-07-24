//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: mathematical
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void increment(char c, int count[]) {
    if (isalpha(c)) {
        count[toupper(c) - 'A']++;
    }
}

int main() {
    char input[10000];
    int count[26] = {0};

    printf("Enter a string: ");
    fgets(input, 10000, stdin);
    
    // count the frequency of each letter
    for (int i = 0; i < strlen(input); i++) {
        increment(input[i], count);
    }

    // print the results
    printf("Letter\tCount\n");
    for (int i = 0; i < 26; i++) {
        printf("%c\t%d\n", i + 'A', count[i]);
    }

    return 0;
}