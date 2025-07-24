//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: scalable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// Function to clean the input string
void clean_string(char *string)
{
    int len=strlen(string);
    for(int i=0;i<len;i++)
    {
        if(ispunct(string[i]))
        {
            string[i]=' ';
        }
        else if(isupper(string[i]))
        {
            string[i]=tolower(string[i]);
        }
    }
}

// Function to count the number of words in a string
int word_count(char *string)
{
    int count=0;
    char *token=strtok(string," ");
    while(token!=NULL)
    {
        count++;
        token=strtok(NULL," ");
    }
    return count;
}

// Function to calculate the positivity of a string
float positivity(char *string)
{
    int positive_words=0,total_words=0;
    char current_word[50];
    char *token=strtok(string," ");
    while(token!=NULL)
    {
        total_words++;
        strcpy(current_word,token);
        clean_string(current_word);
        if(strcmp(current_word,"good")==0 || strcmp(current_word,"great")==0 || strcmp(current_word,"awesome")==0)
        {
            positive_words++;
        }
        token=strtok(NULL," ");
    }
    return (float)positive_words/total_words;
}

// Function to calculate the negativity of a string
float negativity(char *string)
{
    int negative_words=0,total_words=0;
    char current_word[50];
    char *token=strtok(string," ");
    while(token!=NULL)
    {
        total_words++;
        strcpy(current_word,token);
        clean_string(current_word);
        if(strcmp(current_word,"bad")==0 || strcmp(current_word,"terrible")==0 || strcmp(current_word,"horrible")==0)
        {
            negative_words++;
        }
        token=strtok(NULL," ");
    }
    return (float)negative_words/total_words;
}

int main()
{
    char input_string[1000];
    printf("Enter the input string: ");
    fgets(input_string,1000,stdin);
    input_string[strcspn(input_string,"\n")]=0; // Removing the newline character from input
    int n=word_count(input_string);
    float pos=positivity(input_string);
    float neg=negativity(input_string);
    if(n==0)
    {
        printf("No words found!\n");
        exit(0);
    }
    printf("Number of words: %d\n",n);
    printf("Positivity of the string: %.2f\n",pos*100);
    printf("Negativity of the string: %.2f\n",neg*100);
    if(pos>neg)
    {
        printf("Overall sentiment: Positive\n");
    }
    else if(pos<neg)
    {
        printf("Overall sentiment: Negative\n");
    }
    else
    {
        printf("Overall sentiment: Neutral\n");
    }
    return 0;
}