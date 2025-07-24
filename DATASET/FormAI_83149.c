//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: medieval
#include<stdio.h>
#include<string.h>

int main()
{
    char document[5000];
    char word[50][100];
    int count[50], i, j, k, n;
    int len_doc, len_word;

    printf("Good Sir/Madam, please provide us with thine document: ");
    fgets(document, 5000, stdin);
    len_doc = strlen(document);

    printf("\nVerily, we shall tally the word frequencies in this document:\n");
    for(i=0, j=0, k=0; i<=(len_doc-1); i++)
    {
        if(document[i]==' ' || document[i]=='\n' || document[i]=='\t')
        {
            word[j][k]='\0';
            j++;
            k=0;
        }
        else
        {
            word[j][k]=document[i];
            k++;
        }
    }
    n=j;

    for(i=0; i<n; i++)
    {
        count[i]=1;
        for(j=i+1; j<=n; j++)
        {
            if(strcmp(word[i], word[j])==0)
            {
                count[i]++;
                for(k=j; k<=n; k++)
                {
                    strcpy(word[k], word[k+1]);
                }
                n--;
                j--;
            }
        }
    }

    printf("\nBehold, the word frequencies in order of appearance in the document:\n");
    printf("\n| Word | Frequency |\n");
    printf("--------------------\n");
    for(i=0; i<n; i++)
    {
        len_word=strlen(word[i]);
        if(len_word<7) { printf("| %s\t|   %d\t  |\n", word[i], count[i]); }
        else { printf("| %s\t|   %d\t  |\n", word[i], count[i]); }
    }

    return 0;
}