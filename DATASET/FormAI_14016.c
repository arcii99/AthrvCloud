//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: ephemeral
#include <stdio.h>
#include <string.h>

void main() {

    char word[100];
    int start, end, middle, length = 0;

    printf("Enter a word or phrase: ");
    scanf("%s", &word);

    length = strlen(word);
    end = length - 1;
    middle = length/2;

    for(start = 0; start < middle; start++) {
        if(word[start] != word[end]) {
            printf("'%s' is not a palindrome", word);
            break;
        }
        end--;
    }

    if(start == middle) {
        printf("'%s' is a palindrome", word);
    }
}