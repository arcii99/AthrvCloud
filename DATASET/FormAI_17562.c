//FormAI DATASET v1.0 Category: Word Count Tool ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int count=0;
    char str[1000];
    printf("Enter a sentence to count the number of words:\n");
    fgets(str,1000,stdin);
    char *token=strtok(str," \n");  // strip off the first word 

    while (token!=NULL)
    {
        count++;
        token=strtok(NULL," \n");   //strip off next word
    }

    printf("Total words in the given sentence = %d\n",count);
    return 0;
}