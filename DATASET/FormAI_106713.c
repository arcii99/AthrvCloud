//FormAI DATASET v1.0 Category: Sorting ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main()
{
    char strings[MAX_LENGTH][MAX_LENGTH];
    char temp[MAX_LENGTH];
    int length, i, j;

    printf("Enter the number of strings to sort: ");
    scanf("%d", &length);

    printf("Enter %d strings:\n", length);
    for(i=0; i<length; i++)
    {
        scanf("%s", strings[i]);
    }

    // Sorting the strings alphabetically
    for(i=0; i<length-1; i++)
    {
        for(j=i+1; j<length; j++)
        {
            if(strcmp(strings[i], strings[j]) > 0)
            {
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }

    printf("\nSorted strings are:\n");
    for(i=0; i<length; i++)
    {
        printf("%s\n", strings[i]);
    }

    return 0;
}