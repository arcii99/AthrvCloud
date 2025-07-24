//FormAI DATASET v1.0 Category: Word Count Tool ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main () {

    printf("Enter the text to count words from:\n");

    //dynamically allocate memory for input string
    char* input_string = (char*) malloc(sizeof(char) * 1000);
    scanf("%[^\n]", input_string);

    int word_count = 0;

    printf("\nWords in the text entered:\n");

    //iterate over each character in the input string
    for (int i = 0; i < strlen(input_string); i++) {

        //if it's a space or a punctuation mark, increment word count
        if (isspace(input_string[i]) || ispunct(input_string[i])) {
            word_count++;
            printf("\n"); //print new line for each word
        }

        //if it's an alphabet, print it to screen
        if (isalpha(input_string[i])) {
            printf("%c", tolower(input_string[i])); //convert to lowercase
        }

    }

    //print final word count
    printf("\n\nTotal number of words in the text entered: %d\n", word_count);

    free(input_string); //free dynamically allocated memory

    return 0;
}