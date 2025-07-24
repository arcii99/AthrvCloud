//FormAI DATASET v1.0 Category: Text Summarizer ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 1000
#define MAX_SENTENCES 100

//This function calculates the frequency of each word in the text
void wordFrequency(char *text, char *words[], int freq[], int num_words)
{
    int i,j;
    char *token;
    char delimiters[] = " \n\t";
    token = strtok(text, delimiters);

    while(token != NULL)
    {
        for(i=0;i<num_words;i++)
        {
            if(strcmp(words[i],token) == 0) //if word matches
            {
                freq[i]++; //increment the frequency of the word
                break;
            }
        }   
        token = strtok(NULL, delimiters); //get the next token
    }
}

//This function calculates the score of each sentence in the text based on the frequency of words
void sentenceScore(char *text, char *sentences[], int scores[], char *words[], int freq[], int num_sentences, int num_words)
{
    int i,j,k;
    char *token;
    char delimiters[] = " \n\t";
    char temp_text[MAX_SIZE];
    int temp_freq[MAX_SENTENCES][MAX_SIZE] = {{0}};
    int highest_freq = 0;

    for(i=0;i<num_sentences;i++)
    {
        strcpy(temp_text, sentences[i]); //copy the sentence to a temporary buffer
        token = strtok(temp_text, delimiters);
        while(token != NULL)
        {
            for(j=0;j<num_words;j++)
            {
                if(strcmp(words[j],token) == 0) //if word matches
                {
                    temp_freq[i][j]++; //increment the frequency of the word in the sentence
                    break;
                }
            }   
            token = strtok(NULL, delimiters); //get the next token
        }
    }

    //Calculate the sentence score
    for(i=0;i<num_sentences;i++)
    {
        scores[i] = 0;
        for(j=0;j<num_words;j++)
        {
            scores[i] += temp_freq[i][j]*freq[j]; //score is the sum of frequency of each word in the sentence multiplied by its frequency in the text
        }
        if(scores[i] > highest_freq)
            highest_freq = scores[i]; //find the highest score
    }

    //Normalize the scores
    for(i=0;i<num_sentences;i++)
    {
        scores[i] = (float)scores[i]/(float)highest_freq * 100.0;
    }

}

int main()
{
    char text[MAX_SIZE];
    char *sentences[MAX_SENTENCES];
    char *words[MAX_SENTENCES];
    int freq[MAX_SENTENCES] = {0};
    int scores[MAX_SENTENCES];
    int num_sentences = 0;
    int num_words = 0;
    int i,j;
    FILE *fptr;

    fptr = fopen("input.txt", "r");

    if(fptr == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }

    //Read the text from the file
    fgets(text, MAX_SIZE, fptr);

    //Tokenize the text into sentences
    char delimiters[] = ".?!";
    char *token = strtok(text, delimiters);
    while(token != NULL)
    {
        sentences[num_sentences++] = token;
        token = strtok(NULL, delimiters);
    }

    //Tokenize the text into words
    token = strtok(text, " \n\t");
    while(token != NULL)
    {
        for(i=0;i<num_words;i++)
        {
            if(strcmp(words[i],token) == 0) //if word already exists in the array
                break;
        }
        if(i == num_words) //if word does not exist in the array
        {
            words[num_words++] = token; //add the word to the array
        }   
        token = strtok(NULL, " \n\t"); //get the next token
    }

    wordFrequency(text, words, freq, num_words); //calculate the frequency of words
    sentenceScore(text, sentences, scores, words, freq, num_sentences, num_words); //calculate the score of each sentence

    //Print the sentences with score greater than or equal to the average score
    int sum=0;
    for(i=0;i<num_sentences;i++)
    {
        sum += scores[i];
    }
    float avg_score = (float)sum/(float)num_sentences;
    printf("The average score is: %.2f\n", avg_score);

    printf("The summary is:\n");
    for(i=0;i<num_sentences;i++)
    {
        if(scores[i] >= avg_score)
        {
            printf("%s\n", sentences[i]);
        }
    }
    fclose(fptr);
    return 0;
}