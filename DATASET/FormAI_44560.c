//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char sentence[1000], word[100], ch;
    int count=0, flag=0, length, i, j;

    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);

    printf("\nEntered sentence: %s", sentence);

    length=strlen(sentence);
    for(i=0; i<length; i++)
    {
        ch=sentence[i];
        if(isalpha(ch))
        {
            word[count]=ch;
            count++;
            flag=1;
        }
        else if((ch==','||ch=='.'||ch==' '||ch=='\n')&&flag==1)
        {
            word[count]='\0';
            count=0;
            flag=0;
            length=strlen(word);
            for(j=0; j<length; j++)
            {
                word[j]=tolower(word[j]);
            }
            printf("\n%s - ", word);

            //calculate frequency of each letter in the given word
            int freq[26]={0};
            for(j=0; j<length; j++)
            {
                freq[word[j]-'a']++;
            }
            double mean=0, variance=0, standard_deviation=0;
            int sum=0;
            for(j=0; j<26; j++)
            {
                sum=sum+freq[j];
                mean=mean+freq[j]*(j+1);
            }
            mean=mean/sum;

            for(j=0; j<26; j++)
            {
                variance=variance+((freq[j]*(j+1)-mean)*(freq[j]*(j+1)-mean))/sum;
            }
            standard_deviation=sqrt(variance);
            printf("%.2f, %.2f, %.2f\n", mean, variance, standard_deviation);
        }
    }
    return 0;
}