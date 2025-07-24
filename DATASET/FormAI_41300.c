//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_LEN 80

void print_char(char c, int num)
{
    int i;
    for(i = 0; i < num; i++)
    {
        putchar(c);
    }
}

void print_text_art(char *text)
{
    int len = strlen(text);
    int row_len = (len <= MAX_ROW_LEN) ? len : MAX_ROW_LEN;
    int num_rows = len / row_len + (len % row_len != 0);
    int i, j, k;
    for(i = 0; i < num_rows; i++)
    {
        for(j = 0; j < row_len; j++)
        {
            int index = i * row_len + j;
            if(index >= len)
            {
                break;
            }
            char c = text[index];
            int ascii_char = (int) c;
            for(k = 0; k < 8; k++)
            {
                if(ascii_char & (1 << k))
                {
                    print_char('*', 2);
                }
                else
                {
                    print_char(' ', 2);
                }
            }
            print_char(' ', 1);
        }
        putchar('\n');
    }
}

int main()
{
    char text[100];
    printf("Enter some text to generate ASCII art:\n");
    scanf("%[^\n]s", text);
    printf("\nGenerated text art:\n");
    print_text_art(text);
    return 0;
}