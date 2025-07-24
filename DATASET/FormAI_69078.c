//FormAI DATASET v1.0 Category: Word Count Tool ; Style: introspective
#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[1000];
    int count=0, i;

    printf("Enter the sentence to count words: ");
    fgets(sentence, sizeof(sentence), stdin);

    for(i=0; sentence[i]!='\0'; i++)
    {
        if((sentence[i]==' ' || sentence[i]=='\n' || sentence[i]=='\t') && (sentence[i-1]!=' ' && sentence[i-1]!='\n' && sentence[i-1]!='\t'))
            count++;
    }

    if(sentence[strlen(sentence)-1]!=' ' && sentence[strlen(sentence)-1]!='\n' && sentence[strlen(sentence)-1]!='\t')
        count++;

    printf("\nWord count of the given sentence is: %d", count);

    return(0);
}