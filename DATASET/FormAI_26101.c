//FormAI DATASET v1.0 Category: Spell checking ; Style: automated
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    char word[100];
    int i, j;
    int error_count = 0;
    
    printf("Enter a word: ");
    scanf("%s", word);
    
    for(i=0; word[i]!='\0'; i++) {
        // convert all characters to lowercase to simplify checking
        word[i] = tolower(word[i]);
        // check for non-alphabetic characters
        if(!isalpha(word[i])) {
            printf("Error: Non-alphabetic character '%c'\n", word[i]);
            error_count++;
        }
    }
    
    // check for common spelling errors
    if(strcmp(word, "definitely") == 0) {
        printf("Did you mean 'definitely'?\n");
        error_count++;
    }
    
    if(strstr(word, "alot")) {
        printf("Did you mean 'a lot'?\n");
        error_count++;
    }
    
    // check for repeated letters
    for(i=0; word[i]!='\0'; i++) {
        for(j=i+1; word[j]!='\0'; j++) {
            if(word[i] == word[j]) {
                printf("Did you mean to type '%c' instead of '%c'?\n", tolower(word[i]), tolower(word[j]));
                error_count++;
            }
        }
    }
    
    if(error_count == 0) {
        printf("No errors found.\n");
    }
    
    return 0;
}