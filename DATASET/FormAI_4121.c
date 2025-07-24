//FormAI DATASET v1.0 Category: Word Count Tool ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void wordCount(char str[]) {
    int i, words=1; //initialize words to 1 since there is atleast 1 word in any given string
    int len = strlen(str);
    for(i=0; i<len; i++) {
        // Checks if the current character is a space or new line or tab character
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            words++; //increment word count if the above conditions are met
        }
    }
    printf("Total number of words in the given string: %d\n", words);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    printf("Entered string is: %s", str);
    wordCount(str);
    return 0;
}