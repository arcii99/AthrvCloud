//FormAI DATASET v1.0 Category: Text Summarizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_SUMMARY_LENGTH 50

int main(void)
{
    char input[MAX_INPUT_LENGTH]; // holds inputted text
    char summary[MAX_SUMMARY_LENGTH]; // holds summarized text
    char *start = NULL; // pointer to start of sentence
    int sentenceLength = 0; // length of sentence
    int summaryLength = 0; // length of summarized text

    // prompt user for input
    printf("Enter text to summarize: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    // loop through input string
    for (int i = 0; i < strlen(input); i++)
    {
        if (start == NULL) // if not currently in a sentence
        {
            if (isalpha(input[i])) // if start of new sentence found
            {
                start = &input[i]; // set start pointer to current index
                sentenceLength = 1; // set sentence length to 1
            }
        }
        else // if currently in a sentence
        {
            if (input[i] == '.') // if end of sentence found
            {
                char sentence[sentenceLength+1]; // create new char array for the sentence
                strncpy(sentence, start, sentenceLength); // copy the sentence from input array to new array
                sentence[sentenceLength] = '\0'; // add null terminator to end of new array
                start = NULL; // reset start pointer
                sentenceLength = 0; // reset sentence length

                if (summaryLength + strlen(sentence) < MAX_SUMMARY_LENGTH) // if there is room in the summary
                {
                    strcat(summary, sentence); // add sentence to summary
                    strcat(summary, ". "); // add period and space after sentence
                    summaryLength += strlen(sentence) + 2; // update summary length
                }
                else // if summary is full
                {
                    break; // exit loop
                }
            }
            else // if not end of sentence yet
            {
                sentenceLength++; // increment sentence length
            }
        }
    }

    // output summarized text
    printf("Summary: %s\n", summary);

    return 0;
}