//FormAI DATASET v1.0 Category: Text processing ; Style: unmistakable
#include <stdio.h>
#include <string.h>

int main() {
    char string[1000], word[100], replace[100];
    int wordpos = -1, len, repLen, i;

    printf("Enter a string: ");
    fgets(string, 1000, stdin);

    printf("\nEnter the word to replace: ");
    scanf("%s", word);

    printf("\nEnter the replacement word: ");
    scanf("%s", replace);

    len = strlen(word);
    repLen = strlen(replace);

    for(i = 0; i < strlen(string); i++) {
        if(string[i] == word[0]) {
            if(strncmp(&string[i], word, len) == 0) {
                wordpos = i;
                break;
            }
        }
    }

    if(wordpos != -1) {
        for(i = 0; i < len; i++) {
            string[wordpos+i] = replace[i];
        }
        printf("\nNew string: %s", string);
    } else {
        printf("\nThe word \"%s\" was not found in the string.", word);
    }

    return 0;
}