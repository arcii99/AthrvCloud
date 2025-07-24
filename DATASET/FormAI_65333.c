//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i, freq[26] = {0}; //Creating an array of size 26 to store frequency of each letter

    printf("Enter a string: ");
    fgets(str, 100, stdin); //fgets() is used to read input string from user

    for(i=0; str[i]!='\0'; i++) {
        if(isalpha(str[i])) {
            freq[tolower(str[i]) - 'a']++; //to count frequency of each letter in the string
        }
    }

    printf("\nFrequency of each letter in the given string:\n");
    for(i=0; i<26; i++) {
        if(freq[i] != 0) {
            printf("%c - %d\n", i+'a', freq[i]); //Output each letter with its corresponding frequency
        }
    }
    return 0;
}