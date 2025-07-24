//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: Alan Touring
#include <stdio.h>
#include <string.h>

const char *charmap[] = {
    "     ________      \n",
    "    /_  __/ /_  ___\n",
    "     / / / __ \\/ _ \\\n",
    "    / / / / / /  __/\n",
    "   /_/ /_/ /_/\\___/ \n"
};

int main()
{
    char input[50];
    printf("Enter a string to convert to ASCII art: ");
    fgets(input, 50, stdin);

    int length = strlen(input);
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < length; j++)
        {
            int index = (int) input[j];
            if(index >= 97 && index <= 122) // lowercase letters
                index -= 32;
            else if(index < 32 || index > 122) // non-printable characters
                index = 63; // replace with '?'
            else
                index -= 31; // printable ascii characters

            printf("%s", charmap[i] + (index * 2));
        }
        printf("\n");
    }

    return 0;
}