//FormAI DATASET v1.0 Category: Word Count Tool ; Style: interoperable
#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int count = 0, i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for(i=0; i<strlen(str); i++)
    {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            count++;
    }

    printf("Number of words in the string: %d\n", count+1);

    return 0;
}