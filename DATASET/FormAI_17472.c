//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>

int main() {
    char word[100];
    int i, j, len, flag;

    printf("Enter a word to check if it is a palindrome: ");
    scanf("%s", word);

    len = strlen(word);

    flag = 0;
    for(i = 0, j = len - 1; i < len/2; i++, j--) {
        if(word[i] != word[j]) {
            flag = 1;
            break;
        }
    }

    if(flag == 1)
        printf("%s is not a palindrome.", word);
    else
        printf("%s is a palindrome.", word);

    return 0;
}