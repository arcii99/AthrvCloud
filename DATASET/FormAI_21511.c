//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
/* Are you ready to analyze sentiments in style? Let's do this! */

#include <stdio.h>
#include <string.h>

int main()
{
  char sentence[1000];   // The sentence to be analyzed
  int positive_count = 0, negative_count = 0, neutral_count = 0;   // Counters for each sentiment

  printf("Welcome to the Sentiment Analysis Tool! Let's analyze some sentences!\n\n");

  while(1)  // This allows for continuous analysis until the user stops the program
  {
    printf("Please enter a sentence (or type \"quit\" to exit):\n");
    fgets(sentence, 1000, stdin);

    if(strcmp(sentence, "quit\n") == 0)  // Exit the loop if user types "quit"
    {
      printf("Thanks for using the Sentiment Analysis Tool! Goodbye!\n");
      break;
    }

    int len = strlen(sentence);

    // Determine the sentiment of the sentence
    for(int i = 0; i < len; i++)
    {
      if(sentence[i] == 'good' || sentence[i] == 'great' || sentence[i] == 'love' || sentence[i] == 'like')
      {
        positive_count++;
      }
      else if(sentence[i] == 'bad' || sentence[i] == 'terrible' || sentence[i] == 'hate' || sentence[i] == 'dislike')
      {
        negative_count++;
      }
      else
      {
        neutral_count++;
      }
    }

    // Print the results
    printf("\nSentiment Analysis Results:\n");
    printf("Positive: %d\n", positive_count);
    printf("Negative: %d\n", negative_count);
    printf("Neutral: %d\n", neutral_count);

    // Reset the counters for the next sentence
    positive_count = 0;
    negative_count = 0;
    neutral_count = 0;

    printf("\n");
  }

  return 0;
}