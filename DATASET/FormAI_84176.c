//FormAI DATASET v1.0 Category: Text processing ; Style: creative
#include<stdio.h>
#include<string.h>

int main()
{
    char sentence[100];
    int length, vowels=0, consonants=0, digits=0, spaces=0, i;
    
    printf("Enter a sentence: ");
    gets(sentence);
    
    length = strlen(sentence);
    
    for(i=0; i<length; i++)
    {
        if(sentence[i]=='a' || sentence[i]=='e' || sentence[i]=='i' || sentence[i]=='o' || sentence[i]=='u' || sentence[i]=='A' || sentence[i]=='E' || sentence[i]=='I' || sentence[i]=='O' || sentence[i]=='U')
            vowels++;
        else if((sentence[i]>='a' && sentence[i]<='z') || (sentence[i]>='A' && sentence[i]<='Z'))
            consonants++;
        else if(sentence[i]>='0' && sentence[i]<='9')
            digits++;
        else if(sentence[i]==' ')
            spaces++;
    }
    
    printf("\nNumber of vowels: %d", vowels);
    printf("\nNumber of consonants: %d", consonants);
    printf("\nNumber of digits: %d", digits);
    printf("\nNumber of spaces: %d", spaces);
    
    return 0;
}