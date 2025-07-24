//FormAI DATASET v1.0 Category: Text processing ; Style: intelligent
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    printf("Enter a string of words: ");
    fgets(input, 100, stdin); // get input from user

    // remove all non-alphabet characters and convert to lowercase
    int i;
    for(i = 0; input[i] != '\0'; i++) {
        if(!isalpha(input[i])) { // check if non-alphabet
            memmove(&input[i], &input[i+1], strlen(input) - i); // remove non-alphabet character
            i--; // adjust index to account for removed character
        } else {
            input[i] = tolower(input[i]); // convert to lowercase
        }
    }

    // count the occurrences of each word
    char *word = strtok(input, " ");
    int count = 0;
    while(word != NULL) {
        count++;
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }
    printf("Total words: %d\n", count);

    return 0;
}