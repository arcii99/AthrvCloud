//FormAI DATASET v1.0 Category: Syntax parsing ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

int main() {
    char input[100];
    char words[20][20];
    int count = 0;

    // get input from user
    printf("Enter a sentence: ");
    fgets(input, 100, stdin);

    // split sentence into individual words
    char *token = strtok(input, " ");
    while(token != NULL) {
        strcpy(words[count], token);
        token = strtok(NULL, " ");
        count++;
    }

    // iterate through words and print
    printf("\nParsed words:\n");
    for(int i=0; i<count; i++) {
        printf("%d: %s\n", i+1, words[i]);
    }

    return 0;
}