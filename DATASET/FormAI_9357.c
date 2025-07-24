//FormAI DATASET v1.0 Category: Palindrome Checker ; Style: funny
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i,j;
    printf("Hey there! I can check if a word is a palindrome or not. Give me a word and I'll tell you if it's a palindrome or not. \n");
    scanf("%s", str);
    
    int n = strlen(str);
    for(i=0, j=n-1; i<n/2; i++, j--) {
        if(str[i] != str[j]) {
            printf("Oops, looks like \"%s\" is not a palindrome.\n", str);
            printf("Here's my coding trick to make it a palindrome:\n");

            for(int i=0; i<n; i++) {
                printf("%c", str[i]);
            }
            printf("%c", str[n-2]);
            for(int i=n-3; i>=0; i--) {
                printf("%c", str[i]);
            }
            printf("\n");
            return 0;
        }
    }
    printf("Yay! \"%s\" is a palindrome! I knew it all along :)\n", str);
    return 0;
}