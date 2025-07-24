//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sentimentAnalysis //creating a structure to store the analysis results
{
    int positiveWords; //positive word count
    int negativeWords; //negative word count
    int neutralWords; //neutral word count
} analysisResult; //name of the structure object

void sentimentAnalysisEngine(char comment[]) //code for performing the analysis of a given comment
{
    char words[100][100]; //2D array to store the words in the comment
    int i, j = 0, k = 0; //loop variables
    analysisResult.positiveWords = 0; //initializing all word counts to zero
    analysisResult.negativeWords = 0;
    analysisResult.neutralWords = 0;

    for (i = 0; i < strlen(comment); i++)
    {
        if (comment[i] == ' ' || comment[i] == '.' || comment[i] == '\n') //if a space, dot or line break is detected
        {
            words[j][k] = '\0'; //inserting null terminator at end of each word
            j++; //incrementing row index
            k = 0; //resetting column index
        }
        else
        {
            words[j][k] = comment[i]; //if a letter is detected, store in the array
            k++;
        }
    }
    words[j][k] = '\0'; //ending with null terminator

    for (i = 0; i <= j; i++) //looping through all words in the array
    {
        if (strcmp(words[i], "good") == 0 || strcmp(words[i], "excellent") == 0 || strcmp(words[i], "fantastic") == 0)
        //if the word matches any of these, increment positive count
        {
            analysisResult.positiveWords++;
        }
        else if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "terrible") == 0 || strcmp(words[i], "horrible") == 0)
        //if the word matches any of these, increment negative count
        {
            analysisResult.negativeWords++;
        }
        else //if not a positive or negative word, increment neutral count
        {
            analysisResult.neutralWords++;
        }
    }
    printf("Positive Words: %d\nNegative Words: %d\nNeutral Words: %d\n", analysisResult.positiveWords, analysisResult.negativeWords, analysisResult.neutralWords);
}

int main() //main function for driver code
{
    char comment[1000]; //array to store user input comment
    printf("Enter your comment:\n"); //prompt
    fgets(comment, 1000, stdin); //accepting user input
    comment[strcspn(comment, "\n")] = 0; //removing the newline character from the string

    sentimentAnalysisEngine(comment); //calling the function with the comment as argument

    return 0; //returning 0 to indicate program ran smoothly
}