//FormAI DATASET v1.0 Category: Text Summarizer ; Style: medieval
#include<stdio.h>
#include<string.h>

// A helper function to remove punctuations from the text
void remove_punctuations(char *text)
{
    int i,j;
    char temp[strlen(text)];

    for(i=0,j=0;text[i]!='\0';i++)
    {
        if((text[i]>='a' && text[i]<='z') || (text[i]>='A' && text[i]<='Z') || text[i]==' ' || text[i]=='\n')
            temp[j++]=text[i];
    }
    temp[j]='\0';

    strcpy(text,temp);
}

int main()
{
    char text[10000];
    char *keywords[]={"king","queen","prince","princess","castle","knight","armour","battle","war","\0"};
    char *sentences[1000];
    int freq[1000],i,j,count=0;

    printf("Enter the text to summarize in a medieval style: ");
    fgets(text,10000,stdin);

    // Removing the punctuations
    remove_punctuations(text);

    // Splitting the text into sentences
    for(i=0,j=0; text[i]!='\0'; i++)
    {
        if(text[i]=='.' || text[i]=='!' || text[i]=='?')
        {
            text[i]='.';
            sentences[j++]=&text[i-1];
            freq[count++]=0;
        }
    }

    // Counting the frequency of the keywords in each sentence
    for(i=0;i<count;i++)
    {
        for(j=0;keywords[j]!='\0';j++)
        {
            if(strstr(sentences[i],keywords[j])!=NULL)
                freq[i]++;
        }
    }

    // Printing the summary
    printf("\nIn the medieval times, it was said that:\n");
    for(i=0;i<count;i++)
    {
        if(freq[i]>=2)
        {
            if(sentences[i][0]==' ')
                printf("%s.\n",&sentences[i][1]);
            else
                printf("%s.\n",sentences[i]);
        }
    }

    return 0;
}