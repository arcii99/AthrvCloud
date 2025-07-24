//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char input[1000];
    printf("Enter a sentence:\n");
    scanf("%[^\n]", input);
    
    int freq[26] = {0};
    int i, j, index;
    char current;

    for(i=0; i<strlen(input); i++) {
        current = input[i];
        if(isalpha(current)) {
            index = tolower(current) - 'a';
            freq[index]++;
        }
    }

    printf("\nFREQUENCY OF WORDS:\n\n");

    for(i=0; i<26; i++) {
        current = 'a' + i;
        printf("%c: ", current);
        for(j=0; j<freq[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}