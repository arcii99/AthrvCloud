//FormAI DATASET v1.0 Category: Text Summarizer ; Style: retro
#include <stdio.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE 100

int main() {

    printf("RETRO-STYLE TEXT SUMMARIZER\n\n");

    // Get user input
    char input[MAX_INPUT_SIZE];
    printf("Enter the text you want to summarize:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Summarize the text
    char output[MAX_OUTPUT_SIZE];
    int i = 0;
    int j = 0;
    int sentence_count = 0;
    for (i = 0; input[i] != '\0' && i < MAX_INPUT_SIZE; i++) {
        if (input[i] == '.' || input[i] == '?' || input[i] == '!') {
            sentence_count++;
            if (sentence_count == 1) {
                output[j++] = input[i-1];
                output[j++] = input[i];
                output[j++] = ' ';
            }
            else if (sentence_count == 2) {
                output[j++] = input[i-1];
                output[j++] = input[i];
                output[j++] = ' ';
                break;
            }
        }
        else if (i == MAX_INPUT_SIZE - 1) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';

    // Output the summary
    printf("\n\nSUMMARY:\n");
    printf("%s\n", output);

    return 0;
}