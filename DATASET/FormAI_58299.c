//FormAI DATASET v1.0 Category: Text Summarizer ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 500

char* summarizer(char* input, int output_size);

int main() {
    char input[MAX_INPUT_SIZE];
    fgets(input, MAX_INPUT_SIZE, stdin);

    int output_size;
    printf("Enter the desired output size: ");
    scanf("%d", &output_size);

    char* summary = summarizer(input, output_size);

    printf("Summary: %s", summary);

    free(summary);
    return 0;
}

char* summarizer(char* input, int output_size) {
    /* Your text summarization algorithm goes here
        ...
       You should return a null-terminated string
    */

    /* Example algorithm: simply return the first output_size characters of the input */
    int input_length = strlen(input);
    int summary_length = (output_size < input_length) ? output_size : input_length;

    char* summary = malloc((summary_length + 1) * sizeof(char));
    strncpy(summary, input, summary_length);
    summary[summary_length] = '\0';

    return summary;
}