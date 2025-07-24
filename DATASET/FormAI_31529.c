//FormAI DATASET v1.0 Category: Text processing ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    char delimiter[2] = " ";
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin); //get user input

    //removing the newline character from input
    if(input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }

    char *word = strtok(input, delimiter); //splitting input string into words
    int count = 0;
    while (word != NULL) {
        count++;
        int length = strlen(word);

        //if the length of word is odd, capitalize the middle character
        if (length % 2 == 1) {
            int middle = length / 2;
            word[middle] = toupper(word[middle]);
            printf("%s ", word); //printing modified word
        } else {
            printf("%s ", word); //printing original word
        }

        word = strtok(NULL, delimiter); //get next word
    }

    printf("\nTotal words in the sentence: %d\n", count); //printing total words count
    return 0;
}