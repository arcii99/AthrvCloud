//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: futuristic
#include<stdio.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

int main()
{
    int count[MAX_WORDS]={0};
    char words[MAX_WORDS][MAX_WORD_LEN];

    printf("Enter your text:\n");

    int i=0,j=0,c;
    while((c=getchar())!=EOF)
    {
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        {
            words[i][j++]=c;
        }
        else
        {
            if(j)
            {
                words[i][j]='\0';
                ++count[i];
                ++i;
                j=0;
            }
        }
    }

    int n=i;

    for(i=0;i<n;++i)
    {
        for(j=0;j<n-i-1;++j)
        {
            if(strcmp(words[j],words[j+1])>0)
            {
                char temp[MAX_WORD_LEN];
                strcpy(temp,words[j]);
                strcpy(words[j],words[j+1]);
                strcpy(words[j+1],temp);

                int t=count[j];
                count[j]=count[j+1];
                count[j+1]=t;
            }
        }
    }

    printf("\nWord Frequency:\n\n");
    for(i=0;i<n;++i)
    {
        if(count[i])
        {
            printf("%s : %d\n",words[i],count[i]);
        }
    }

    return 0;
}