//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Cyberpunk
//Cyber Text Summarizer Program v1.0

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to summarize the given text
char* summarize_text(char* text)
{
    char* summary = calloc(200, sizeof(char)); //Allocate memory to store summarised text
    int i, j = 0, count = 0, len = strlen(text); //Initialise variables

    for(i = 0; i < len; i++) //Loop through each character of the text
    {
        if(text[i] == '.') //If a period is found, increment count and move to next sentence
        {
            count++;
            if(count == 4) //If 4 sentences are processed, break the loop
                break;
        }
        summary[j] = text[i]; //Copy the character to summary
        j++;
    }

    strcat(summary, "..."); //Append ellipsis to the end of summary
    return summary; //Return the summarised text
}

int main()
{
    printf("=======================================\n");
    printf("Cyber Text Summarizer Program v1.0\n");
    printf("=======================================\n");

    char* text = "The city was a frenzy of neon lights, pulsating beats, and constant stimuli. Everything was in a constant state of motion, as if the very air was alive. I had to get out, to find a moment of peace amidst the chaos. I stumbled upon a small alleyway, tucked away from the madness of the city. It was an oasis of calm, a sanctuary in the midst of madness.";

    printf("\nOriginal Text:\n");
    printf("%s\n", text);

    char* summary = summarize_text(text); //Summarize the text

    printf("\nSummary:\n");
    printf("%s\n", summary);

    free(summary); //Free the memory allocated to summary
    return 0;
}