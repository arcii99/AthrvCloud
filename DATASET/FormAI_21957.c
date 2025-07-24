//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

void main()
{
    char c[100], translated[100]; //Declare character arrays for input and translated output
    int i, n, j=0;
    
    printf("Enter the sentence to be translated:\n");
    scanf("%[^\n]", c); //Scanning input including space
    
    n = strlen(c); //Store length of input string in n
    
    for(i=0; i<n; i++)
    {
        if(c[i] == 'C' || c[i] == 'c') //Translate 'C' and 'c'
        {
            if(c[i+1] == 'a' && c[i+2] == 't')
            {
                translated[j++] = 'M'; //Replace 'Cat' with 'Meow'
                translated[j++] = 'e';
                translated[j++] = 'o';
                translated[j++] = 'w';
                i+=2;
            }
            else
            {
                translated[j++] = c[i]; //Copy 'C' or 'c' as is if not followed by 'at'
            }
        }
        else
        {
            translated[j++] = c[i]; //Copy all other characters as is
        }
    }
    
    printf("\nTranslated sentence:\n%s", translated); //Output translated sentence
}