//FormAI DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <string.h>

int main() {

    char text[100];
    printf("Enter some text: ");
    fgets(text, 100, stdin);

    printf("\nOriginal text: %s", text);

    // Remove trailing whitespace
    int length = strlen(text)-1;
    while(text[length] == '\n' || text[length] == '\r') {
        text[length] = '\0';
        length--;
    }

    // Count number of words
    int word_count = 0;
    char* token = strtok(text, " ");
    while(token != NULL) {
        word_count++;
        token = strtok(NULL, " ");
    }
    printf("\nNumber of words: %d\n", word_count);

    // Replace all vowels with x
    int i;
    for(i = 0; i < strlen(text); i++) {
        if(text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' ||
           text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
            text[i] = 'x';
        }
    }
    printf("Text with vowels replaced by x: %s\n", text);

    // Capitalize first letter of each word
    token = strtok(text, " ");
    while(token != NULL) {
        if(token[0] >= 'a' && token[0] <= 'z') {
            token[0] = token[0] - 32;
        }
        printf("%s ", token);
        token = strtok(NULL, " ");
    }
    printf("\n");

    return 0;
}