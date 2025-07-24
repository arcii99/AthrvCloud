//FormAI DATASET v1.0 Category: Text processing ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char text[10000];
    int i;
    int upper_case_count = 0;
    int lower_case_count = 0;
    int digit_count = 0;
    int other_count = 0;
    char c;

    printf("Enter some text: ");
    fgets(text, sizeof(text), stdin);

    for (i = 0; i < strlen(text); i++)
    {
        c = text[i];

        if (isdigit(c))
        {
            digit_count++;
        }
        else if (isalpha(c))
        {
            if (isupper(c))
            {
                upper_case_count++;
            }
            else
            {
                lower_case_count++;
            }
        }
        else
        {
            other_count++;
        }
    }

    printf("Number of upper case characters: %d\n", upper_case_count);
    printf("Number of lower case characters: %d\n", lower_case_count);
    printf("Number of digits: %d\n", digit_count);
    printf("Number of other characters: %d\n", other_count);

    return 0;
}