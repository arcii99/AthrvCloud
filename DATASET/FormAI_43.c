//FormAI DATASET v1.0 Category: Text processing ; Style: happy
#include <stdio.h>
#include <string.h>

int main() {
    char sentence[100];
    printf("Hello there! Let's create a happy sentence.\n");

    // get the sentence from user
    printf("Enter your sentence (less than 100 characters):\n");
    fgets(sentence, 100, stdin);

    // remove newline character from string
    sentence[strcspn(sentence, "\n")] = 0;

    // check for keywords
    if (strstr(sentence, "happy") != NULL || strstr(sentence, "smile") != NULL || strstr(sentence, "joy") != NULL) {
        printf("That sentence is already happy! Keep spreading the positivity!\n");
    } else {
        // add a happy word
        strcat(sentence, " makes me happy!");
        printf("Your new happy sentence is:\n%s\n", sentence);
    }

    return 0;
}