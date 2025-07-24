//FormAI DATASET v1.0 Category: Word Count Tool ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000];
    int count = 0, i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i=0; str[i]!='\0'; i++)
    {
        if(str[i] == ' ')
            count++;    
    }
    printf("Total number of words = %d", count+1);

    return 0;
}