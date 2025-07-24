//FormAI DATASET v1.0 Category: Word Count Tool ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[1000], temp[1000], *ptr;
    int i, j, len, count = 0;

    printf("Enter the string: ");
    gets(str);

    len = strlen(str);

    for(i = 0; i < len; i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
        {
            temp[j++] = str[i];
        }
        else
        {
            temp[j] = '\0';
            ptr = malloc(sizeof(temp));
            strcpy(ptr, temp);
            if(strlen(ptr) > 0)
                count++;
            j = 0;
            free(ptr);
        }
    }

    printf("\nThe total words in the string are: %d", count);

    return 0;
}