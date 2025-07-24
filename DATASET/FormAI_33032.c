//FormAI DATASET v1.0 Category: Word Count Tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *str);

int main()
{
    char str[1000];
    
    printf("Enter a string: ");
    fgets(str, 1000, stdin);
    
    printf("The word count is: %d", countWords(str));
    
    return 0;
}

int countWords(char *str)
{
    int count = 0;
    int flag = 0;
    
    for(int i = 0; i < strlen(str); i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            flag = 1; // flag indicates word has started
        }
        else if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            if(flag == 1)
            {
                count++;
                flag = 0; // flag indicates word has ended
            }
        }
    }
    
    if(flag == 1) // case where last character is not followed by space or newline
    {
        count++;
    }
    
    return count;
}