//FormAI DATASET v1.0 Category: Word Count Tool ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1000], word[50];
    int i, j, count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("\nEnter a word to count: ");
    scanf("%s", word);

    // convert all characters to lowercase for case insensitivity
    for(i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    for(i = 0; i < strlen(str); i++) {
        // if current character is not a whitespace, add it to word
        if(!isspace(str[i])) {
            word[j] = tolower(str[i]);
            j++;
        } else {
            // if current character is a whitespace, compare word with given word
            word[j] = '\0'; // terminate word
            if(strcmp(word, str) == 0) {
                count++;
            }
            j = 0; // reset index for next word
        }
    }

    printf("\nWord count of the word '%s' is: %d", word, count);

    return 0;
}