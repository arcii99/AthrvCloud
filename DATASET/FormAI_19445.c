//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

// Function to determine sentiment score of a sentence
int sentiment_score(char sentence[])
{
    int positive_words = 0, negative_words = 0;
    int score = 0;

    // List of positive and negative words
    char positive_words_list[10][10] = {"happy", "love", "excited", "perfect", "wonderful", "great", "amazing", "excellent", "awesome", "fantastic"};
    char negative_words_list[10][10] = {"sad", "hate", "angry", "terrible", "awful", "horrible", "disgusting", "annoying", "frustrating", "boring"};

    // Split the sentence into words
    char *word = strtok(sentence, " ");

    // Loop through each word
    while (word != NULL)
    {
        // Check if the current word is in the positive words list
        for (int i = 0; i < 10; i++)
        {
            if (strcmp(word, positive_words_list[i]) == 0)
            {
                positive_words++;
            }
        }

        // Check if the current word is in the negative words list
        for (int i = 0; i < 10; i++)
        {
            if (strcmp(word, negative_words_list[i]) == 0)
            {
                negative_words++;
            }
        }

        // Move to the next word
        word = strtok(NULL, " ");
    }

    // Calculate the sentiment score
    score = positive_words - negative_words;

    return score;
}

int main()
{
    // Sample sentences
    char sentence1[100] = "I am happy and excited about my new job!";
    char sentence2[100] = "This terrible weather is making me sad and frustrated.";
    char sentence3[100] = "The movie was amazing, I loved every minute of it.";

    // Determine sentiment score of each sentence
    int score1 = sentiment_score(sentence1);
    int score2 = sentiment_score(sentence2);
    int score3 = sentiment_score(sentence3);

    // Display sentiment score of each sentence
    printf("Sentiment score of '%s' is: %d\n", sentence1, score1);
    printf("Sentiment score of '%s' is: %d\n", sentence2, score2);
    printf("Sentiment score of '%s' is: %d\n", sentence3, score3);

    return 0;
}