//FormAI DATASET v1.0 Category: String manipulation ; Style: medieval
#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[256];
    char reverse[256];
    int i=0,j=0,length,word_length=0,start=0,end=0;
    printf("Welcome to Medieval String Manipulation Program!\n\n");
    printf("Please enter a sentence(max 255 characters): \n");
    fgets(sentence, 256, stdin);
    length=strlen(sentence);
    for(i=0;i<length;i++)
    {
        if(sentence[i] == ' ' || sentence[i] == '\n')
        {
            end=i-1;
            for(j=end;j>=start;j--)
            {
                reverse[word_length]=sentence[j];
                word_length++;
            }
            reverse[word_length]=' ';
            word_length++;
            start=i+1;
        }
    }
    end=length-1;
    for(j=end;j>=start;j--)
    {
        reverse[word_length]=sentence[j];
        word_length++;
    }
    reverse[word_length]='\0';
    printf("\nIn a medieval style, your sentence is: \n");
    printf("%s\n\n", reverse);
    return 0;
}