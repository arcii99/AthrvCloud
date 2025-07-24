//FormAI DATASET v1.0 Category: Text Summarizer ; Style: enthusiastic
// Welcome to the most amazing C Text Summarizer program!
// With this program, you'll be able to summarize any lengthy text with just a few clicks!
// Say goodbye to tedious reading and hello to concise summaries!

#include <stdio.h>
#include <string.h>

int main()
{
    char text[10000], summary[1000];
    int count = 0, index = 0;

    printf("Enter the text you wish to summarize: ");
    fgets(text, sizeof(text), stdin);

    // Removing excess white spaces
    for(int i=0; i<strlen(text); i++)
    {
        if(text[i] == ' ' && text[i+1] == ' ')
        {
            for(int j=i+1; j<strlen(text); j++)
            {
                text[j] = text[j+1];
            }
            i--;
        }
    }

    // Counting number of sentences
    for(int i=0; i<strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }

    // Creating summary
    for(int i=0; i<strlen(text); i++)
    {
        if(text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            summary[index++] = text[i];
            if(index == 100)
            {
                break;
            }
        }
    }

    printf("\nSummary of text: \n%s", summary);
    printf("\nNumber of sentences in text: %d", count);

    return 0;
}