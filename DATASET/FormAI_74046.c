//FormAI DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[1000], word[100];
    int count = 0, len, i, j, found;
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    printf("Enter the word to count: ");
    scanf("%s", word);
    
    len = strlen(str);
    
    if(word[strlen(word) - 1] == "\n") {
        word[strlen(word) - 1] = "\0";
    } //removes newline from word if present
    
    for(i=0; i<=len - strlen(word); i++) {
        found = 1;
        for(j=0; j<strlen(word); j++) {
            if(str[i+j] != word[j]) {
                found = 0;
                break;
            }
        }
        if(found == 1) {
            count++;
        }
    }
    
    printf("The word '%s' appears %d times in the given string.\n", word, count);
    
    return 0;
}