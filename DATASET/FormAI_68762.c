//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>

int main()
{
    char input_string[100];
    int positive_count = 0, negative_count = 0, neutral_count = 0;
    
    printf("Welcome to the Grateful Sentiment Analysis Tool!\n");
    printf("Enter your text here: ");
    fgets(input_string, 100, stdin);
    
    // perform sentiment analysis
    for(int i=0; input_string[i]!='\0'; i++)
    {
        if(input_string[i] == 't' && input_string[i+1] == 'h' && input_string[i+2] == 'a' && input_string[i+3] == 'n' && input_string[i+4] == 'k')
        {
            positive_count++;
            i += 4; // skip the word "thank"
        }
        else if(input_string[i] == 'g' && input_string[i+1] == 'r' && input_string[i+2] == 'e' && input_string[i+3] == 'a' && input_string[i+4] == 't')
        {
            positive_count++;
            i += 4; // skip the word "great"
        }
        else if(input_string[i] == 'a' && input_string[i+1] == 'm' && input_string[i+2] == 'a' && input_string[i+3] == 'z' && input_string[i+4] == 'i' && input_string[i+5] == 'n' && input_string[i+6] == 'g')
        {
            positive_count++;
            i += 6; // skip the word "amazing"
        }
        else if(input_string[i] == 'b' && input_string[i+1] == 'a' && input_string[i+2] == 'd')
        {
            negative_count++;
            i += 2; // skip the word "bad"
        }
        else if(input_string[i] == 'w' && input_string[i+1] == 'o' && input_string[i+2] == 'r' && input_string[i+3] == 's' && input_string[i+4] == 't')
        {
            negative_count++;
            i += 4; // skip the word "worst"
        }
        else if(input_string[i] == 'h' && input_string[i+1] == 'a' && input_string[i+2] == 't' && input_string[i+3] == 'e')
        {
            negative_count++;
            i += 3; // skip the word "hate"
        }
        else if(input_string[i] == ' ')
        {
            neutral_count++;
        }
    }
    
    printf("\n\nSentiment Analysis Results:\n");
    printf("Positive words count: %d\n", positive_count);
    printf("Negative words count: %d\n", negative_count);
    printf("Neutral words count: %d\n", neutral_count);
    
    if(positive_count > negative_count)
    {
        printf("\nOverall sentiment is Positive. Thank you for using the Grateful Sentiment Analysis Tool!\n");
    }
    else if(negative_count > positive_count)
    {
        printf("\nOverall sentiment is Negative. We're sorry to hear that. Thank you for using the Grateful Sentiment Analysis Tool!\n");
    }
    else
    {
        printf("\nOverall sentiment is Neutral. Thank you for using the Grateful Sentiment Analysis Tool!\n");
    }

    return 0;
}