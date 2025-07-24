//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Romeo and Juliet
#include<stdio.h>

int main()
{
    char text[500];
    int positive_words = 0, negative_words = 0, neutral_words = 0;

    printf("Romeo: Good day, my fair program. What text shall we analyze today?\n");
    printf("Juliet: Ah, sweet Romeo, let us input the text and see its sentiment.\n");
    printf("Romeo: Very well, my love. Enter the text within 500 characters:\n");

    fgets(text, 500, stdin);

    for(int i=0;text[i]!='\0';i++)
    {
        if (text[i] == 'g' && text[i+1] == 'o' && text[i+2] == 'o' && text[i+3] == 'd')
            positive_words ++;
        else if (text[i] == 'b' && text[i+1] == 'a' && text[i+2] == 'd')
            negative_words ++;
        else if (text[i] == 'o' && text[i+1] == 'k' && text[i+2] == 'a' && text[i+3] == 'y')
            neutral_words ++;
    }

    printf("Juliet: My dear Romeo, the sentiment analysis of the text is as follows:\n");
    printf("Positive words: %d\nNegative words: %d\nNeutral words: %d\n", positive_words, negative_words, neutral_words);

    printf("Romeo: Wonderful work, my love. This program has truly brought us closer together, like two code snippets intertwined.\n");
    printf("Juliet: Oh Romeo, how you doth speak so sweetly of our code.\n");

    return 0;
}