//FormAI DATASET v1.0 Category: String manipulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100]; //declare a character array to hold the string
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin); //read the input string from user
    
    //loop through each character of the sentence and perform some operations
    int len = strlen(str);
    int vowels = 0, consonants = 0, digits = 0, whitespaces = 0;
    for(int i=0; i<len; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32; //convert uppercase to lowercase
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') vowels++; //count vowels
        else if(str[i] >= 'b' && str[i] <= 'z') consonants++; //count consonants
        else if(str[i] >= '0' && str[i] <= '9') digits++; //count digits
        else if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n') whitespaces++; //count whitespaces
    }
    
    //print the statistics of the string
    printf("\nStatistics of the sentence:\n");
    printf("Length of the sentence: %d\n", len-1);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);
    printf("Number of digits: %d\n", digits);
    printf("Number of whitespaces: %d\n", whitespaces);
    
    //reverse the string using pointer and array notation
    char *p = str;
    char temp;
    int i=0, j=strlen(str)-1;
    while(i<j)
    {
        temp = *(p+i);
        *(p+i) = *(p+j);
        *(p+j) = temp;
        i++;
        j--;
    }
    printf("\nReversed sentence: %s", str);
    
    //remove vowels from the string
    for(int i=0; str[i]!='\0'; i++)
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || 
           str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            for(int j=i; str[j]!='\0'; j++)
            {
                str[j] = str[j+1];
            }
            i--;
        }
    }
    printf("\nSentence without vowels: %s",str);
    
    return 0;
}