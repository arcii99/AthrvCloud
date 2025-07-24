//FormAI DATASET v1.0 Category: Word Count Tool ; Style: cheerful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {

    printf("Welcome to the Cheerful Word Count Tool!\n");
    printf("Enter a sentence below to find out how many words it contains:\n");

    char sentence[1000];
    fgets(sentence, 1000, stdin);

    int wordCount = 0;
    for (int i = 0; i < strlen(sentence); i++) {

        if (isalpha(sentence[i]) && (i == 0 || isspace(sentence[i - 1]))) {
            wordCount++;
        }
        
    }

    printf("Your sentence contains %d words! Hooray!\n", wordCount);

    return 0;
}