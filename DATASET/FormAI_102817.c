//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100]; // create a string to store user input
    int score = 0; // initialize a variable to store sentiment score
    printf("Enter a sentence to analyze its sentiment:\n"); // ask for user input
    fgets(input, 100, stdin); // read user input
    
    // create a dictionary of positive and negative words
    char positive[10][20] = {"good", "great", "awesome", "excellent", "fantastic", "amazing", "superb", "wonderful", "happy", "love"};
    char negative[10][20] = {"bad", "terrible", "awful", "horrible", "poor", "sad", "unhappy", "depressed", "hate", "dislike"};
    
    // check if each word in the input matches with any word in the dictionary and add sentiment score accordingly
    char *word = strtok(input, " ");
    while (word != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            if (strcmp(word, positive[i]) == 0)
            {
                score++;
            }
            else if (strcmp(word, negative[i]) == 0)
            {
                score--;
            }
        }
        word = strtok(NULL, " ");
    }
    
    // print sentiment analysis result based on the total score
    if (score > 0)
    {
        printf("The input has a positive sentiment with a score of %d.\n", score);
    }
    else if (score < 0)
    {
        printf("The input has a negative sentiment with a score of %d.\n", -score);
    }
    else
    {
        printf("The input is neutral.\n");
    }
    
    return 0;
}