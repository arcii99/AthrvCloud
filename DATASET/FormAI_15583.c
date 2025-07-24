//FormAI DATASET v1.0 Category: Text Summarizer ; Style: scientific
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_INPUT_SIZE 1000 //Maximum length of the input text
#define MAX_SUMMARY_SIZE 100 //Maximum length of the summarized text

char input_text[MAX_INPUT_SIZE]; //Stores the input text
char summarized_text[MAX_SUMMARY_SIZE]; //Stores the summarized text

bool is_sentence_ended(char c)
{
    //Returns true if `c` is an end-of-sentence character
    return (c == '.' || c == '?' || c == '!');
}

int main()
{
    //Get the input text
    printf("Enter the text to be summarized (max. %d characters):\n", MAX_INPUT_SIZE);
    fgets(input_text, MAX_INPUT_SIZE, stdin);

    //Remove the newline character at the end of the input
    input_text[strcspn(input_text, "\n")] = '\0';

    //Initialize the summarized text to an empty string
    summarized_text[0] = '\0';

    //Loop through the input text and summarize it
    int i = 0;
    while(input_text[i] != '\0')
    {
        //If the current character is an end-of-sentence character, add the sentence to the summarized text
        if(is_sentence_ended(input_text[i]))
        {
            //Copy the sentence to a temporary buffer
            char sentence[MAX_INPUT_SIZE];
            int j = 0;
            while(!is_sentence_ended(input_text[i]) && input_text[i] != '\0')
            {
                sentence[j] = input_text[i];
                i++;
                j++;
            }
            sentence[j] = input_text[i];
            sentence[j+1] = '\0';

            //Append the sentence to the summarized text
            if(strlen(summarized_text) + strlen(sentence) <= MAX_SUMMARY_SIZE)
            {
                strcat(summarized_text, sentence);
            }
            else
            {
                break;
            }
        }
        else
        {
            i++;
        }
    }

    //Print the summarized text
    printf("Summary:\n%s\n", summarized_text);

    return 0;
}