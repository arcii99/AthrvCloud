//FormAI DATASET v1.0 Category: Word Count Tool ; Style: puzzling
#include <stdio.h>

int main()
{
    char str[100];
    int count = 0, flag = 0;

    printf("Enter a string: ");
    gets(str);

    for(int i=0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
        {
            flag = 0;
        }
        else if(flag == 0)
        {
            count++;
            flag = 1;
        }
    }

    printf("Word count: %d\n", count);

    return 0;
}