//FormAI DATASET v1.0 Category: Text Summarizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_OUTPUT_LENGTH 100

/**
 * Summarize an input string and return a truncated version
 * of it with a maximum length of MAX_OUTPUT_LENGTH
 */
char* summarize(char input[]) {
    char* output = malloc(sizeof(char) * (MAX_OUTPUT_LENGTH + 1)); //allocate memory for output string
    if (output == NULL) {
        printf("Error allocating memory for output summary");
        return NULL;
    }

    int input_length = strlen(input);
    if (input_length <= MAX_OUTPUT_LENGTH) { //if the input is shorter than the max output length, return it as is
        strcpy(output, input);
        return output;
    }

    //initialize word count, index, and output buffer
    int word_count = 0;
    int index = 0;
    char buffer[MAX_OUTPUT_LENGTH];
    memset(output, '\0', MAX_OUTPUT_LENGTH + 1);

    while (word_count < MAX_OUTPUT_LENGTH) { //loop through input string until enough words have been added to the output
        if (input[index] == ' ' || index == input_length - 1) { //if the current character is a space or the end of the string
            if (index == input_length - 1) { //if we're at the end of the string, add the current character to the buffer
                buffer[word_count] = input[index];
                word_count++;
            }
            buffer[word_count] = '\0'; //terminate the buffer with a null character
            strcat(output, buffer); //add the buffer to the output
            strcat(output, " "); //add a space to separate words
            memset(buffer, '\0', word_count); //clear the buffer
            word_count = 0; //reset the word count
        } else { //if the current character is not a space, add it to the buffer
            buffer[word_count] = input[index];
            word_count++;
        }

        index++; //increment index to move to the next character
    }

    strcat(output, "..."); //add ellipsis to the end of the summary

    return output;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter text to summarize (max %d characters): ", MAX_INPUT_LENGTH);
    fgets(input, MAX_INPUT_LENGTH, stdin); //get input from user

    char* summary = summarize(input);
    printf("Summary: %s", summary);

    free(summary); //free the memory allocated for the summary string

    return 0;
}