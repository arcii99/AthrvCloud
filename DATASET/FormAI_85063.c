//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char input[MAX_BUFFER_SIZE];
    int input_len = 0;
    int score = 0;

    printf("Enter a sentence to be analyzed: ");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    input_len = strlen(input);

    for(int i = 0; i < input_len; i++)
    {
        if(input[i] == ' ')
            continue;
        if(input[i] == '!')
            score += 2;
        else if(input[i] == '?' || input[i] == '.')
            score += 1;
        else
            score -= 1;
    }

    if(score > 0)
        printf("The given sentence has a positive sentiment.\n");
    else if(score < 0)
        printf("The given sentence has a negative sentiment.\n");
    else
        printf("The given sentence has a neutral sentiment.\n");

    return 0;
}