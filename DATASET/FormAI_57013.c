//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char sentence[200];
    int loveCount = 0, happyCount = 0, sadCount = 0, totalWords = 0;

    printf("My Sweetheart, how are you feeling today?\n");
    fgets(sentence, 200, stdin);
    
    char *temp = strtok(sentence, " ");
    while(temp != NULL)
    {
        if(strstr(temp, "love") != NULL || strstr(temp, "romantic") != NULL || strstr(temp, "passionate") != NULL)
            loveCount++;
        else if(strstr(temp, "happy") != NULL || strstr(temp, "excited") != NULL || strstr(temp, "joyful") != NULL)
            happyCount++;
        else if(strstr(temp, "sad") != NULL || strstr(temp, "unhappy") != NULL || strstr(temp, "lonely") != NULL)
            sadCount++;
        totalWords++;
        temp = strtok(NULL, " ");
    }
    
    int sentimentScore = (loveCount*3 + happyCount*2 - sadCount*2) / totalWords;
    
    if(sentimentScore > 0)
        printf("My love for you just grows stronger, with each and every word you say!\n");
    else if(sentimentScore < 0)
        printf("Though my heart is heavy, I'll stick around and make it alright!\n");
    else
        printf("My dearest, may this day keep you feeling great forever and always!\n");
    
    return 0;
}