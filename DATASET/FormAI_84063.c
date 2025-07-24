//FormAI DATASET v1.0 Category: Text processing ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LEN 256
#define MAX_WORDS 1000

int main() {
    char input[MAX_LINE_LEN];
    char *words[MAX_WORDS];
    int word_count = 0, i;

    printf("Welcome to the Text Processing Program!\n");
    printf("Enter some text (maximum 255 characters):\n");

    fgets(input, MAX_LINE_LEN, stdin);
    input[strlen(input)-1] = '\0';

    for(i=0; i<strlen(input); i++) {
        if(isspace(input[i])) {
            input[i] = '\0';
        }
    }

    words[word_count++] = input;

    for(i=0; i<strlen(input); i++) {
        if(input[i] == '\0') {
            words[word_count++] = &input[i+1];
        }
    }

    printf("You entered %d words.\n\n", word_count);

    printf("Here are the words you entered in reverse order:\n");
    for(i=word_count-1; i>=0; i--) {
        printf("%s\n", words[i]);
    }

    printf("\nThank you for using the Text Processing Program!\n");

    return 0;
}