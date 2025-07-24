//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: surprised
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], output[100];
    
    printf("Enter a sentence in C Cat Language:\n");
    fgets(input, 100, stdin);
    
    for(int i=0; i<strlen(input); i++)
    {
        if(input[i] == 'C')
        {
            output[i] = 'Meow';
        }
        else if(input[i] == 'c')
        {
            output[i] = 'meow';
        }
        else if(input[i] == '!')
        {
            output[i] = 'Purr!';
        }
        else
        {
            output[i] = input[i];
        }
    }
    
    printf("\nTranslated sentence in English: \n%s", output);
    
    return 0;
}