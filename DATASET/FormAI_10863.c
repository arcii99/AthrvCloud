//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: satisfied
#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int main()
{
    char str[SIZE];
    int i, len, freq[SIZE];
    
    printf("Enter a string: ");
    fgets(str, SIZE, stdin);
    
    len = strlen(str);
    
    for(i = 0; i < len; i++) 
    {
        freq[i] = 1;
        for(int j = i+1; j < len; j++) 
        {
            if(str[i] == str[j]) 
            {
                freq[i]++;
                str[j] = '0';
            }
        }
    }
    
    printf("\nCharacter Count\n");
    for(i = 0; i < len; i++) 
    {
        if(str[i] != ' ' && str[i] != '0')
            printf("%c - %d\n", str[i], freq[i]);
    }
    
    return 0;
}