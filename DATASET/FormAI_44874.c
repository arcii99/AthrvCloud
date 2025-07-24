//FormAI DATASET v1.0 Category: Text processing ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Welcome to the Intelligent Text Processing Program!\n");
    char input[1000];
    char keyword[100];
    printf("Please enter a sentence or a text: ");
    fgets(input, 1000, stdin);
    printf("Please enter a keyword to search for: ");
    fgets(keyword, 100, stdin);
    keyword[strcspn(keyword, "\n")] = 0; // remove newline character from keyword
    printf("\nProcessing the text...\n\n");
    int keyword_count = 0;
    char *word = strtok(input, " \n"); // tokenize input string by space and newline characters
    while (word != NULL) {
        if (strstr(word, keyword) != NULL) { // check if keyword exists in the word
            keyword_count++;
            printf("\033[1;31m%s\033[0m ", word); // highlight keyword in red
        }
        else {
            printf("%s ", word);
        }
        word = strtok(NULL, " \n");
    }
    printf("\n\n");
    printf("Total occurrences of the keyword \"%s\": %d\n", keyword, keyword_count);
    return 0;
}