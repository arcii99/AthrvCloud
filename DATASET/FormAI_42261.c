//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {

    char word[100];
    printf("Hey! Give me a word and I'll tell you if it's a palindrome or not!\n");
    scanf("%s", word);
    int length = strlen(word);
    int i, j;

    for (i = 0, j = length - 1; i < length / 2; i++, j--) {
        if (word[i] != word[j]) {
            printf("Wow, I'm surprised! This word is NOT a palindrome :(\n");
            return 0;
        }
    }
    printf("Wow, I'm surprised! This word IS a palindrome! :)\n");
    return 0;
}