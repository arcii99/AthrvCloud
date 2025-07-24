//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: active
#include <stdio.h>
#include <stdlib.h>

char ascii_chars[] = {'@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.'};

int main()
{
    char input[1024];
    int rows, cols;
    char *ptr;

    printf("Please enter some text to convert to ASCII art:\n");
    fgets(input, sizeof(input), stdin);

    printf("Please enter number of rows (max 40):\n");
    scanf("%d", &rows);

    printf("Please enter number of columns (max 100):\n");
    scanf("%d", &cols);

    ptr = input;
    int index;
    for (int i = 0; i < rows; i++)
    {
        printf("\n");
        for (int j = 0; j < cols; j++)
        {
            index = rand() % (sizeof(ascii_chars)/sizeof(char));
            if (*ptr == '\0')
            {
                ptr = input;
            }
            printf("%c", ascii_chars[index]);
            ptr++;
        }
    }

    return 0;
}