//FormAI DATASET v1.0 Category: Binary Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char binary[100];
    int decimal = 0, i, j, len;

    printf("Greetings my lord, I am your binary converter!\n");
    printf("Enter the binary number you desire to convert to decimal: ");
    scanf("%s", binary);

    // Check if the input contains only 0's and 1's
    len = strlen(binary);
    for (i = 0; i < len; i++)
    {
        if (binary[i] != '0' && binary[i] != '1')
        {
            printf("Forgive me my lord, but that is not a binary number...\n");
            return 0;
        }
    }

    // Convert binary to decimal
    for (i = 0, j = len - 1; i < len; i++, j--)
    {
        if (binary[j] == '1')
        {
            decimal += 1<<i;
        }
    }

    printf("Your binary number: %s \n", binary);
    printf("Converted to decimal: %d\n", decimal);

    printf("Thank you for using my services. Until next time, my lord!\n");

    return 0;
}