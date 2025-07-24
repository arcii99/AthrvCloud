//FormAI DATASET v1.0 Category: Text processing ; Style: happy
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int happy_count = 0;
    printf("Please enter a string: ");
    fgets(str, 100, stdin); //Reading input string from user

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'h' || str[i] == 'H')
        {
            if (str[i + 1] == 'a' || str[i + 1] == 'A')
            {
                if (str[i + 2] == 'p' || str[i + 2] == 'P')
                {
                    if (str[i + 3] == 'p' || str[i + 3] == 'P')
                    {
                        if (str[i + 4] == 'y' || str[i + 4] == 'y')
                        {
                            happy_count++; //increasing happy_count if match found
                        }
                    }
                }
            }
        }
    }

    if (happy_count == 1)
    {
        printf("There is %d happy found in the string: %s", happy_count, str);
    }
    else if (happy_count > 1)
    {
        printf("There are %d happies found in the string: %s", happy_count, str);
    }
    else
    {
        printf("Oh no, there are no happies found in the string: %s", str);
    }

    return 0;
}