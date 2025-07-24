//FormAI DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAB_SIZE 4

void print_tabs(int tabs)
{
    for (int i = 0; i < tabs; i++)
        putchar(' ');
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file)
    {
        printf("Could not open file: %s\n", argv[1]);
        exit(1);
    }
    
    int c;
    int tabs = 0;
    printf("<html>\n");
    while ((c = fgetc(file)) != EOF)
    {
        switch (c)
        {
            case '<':
                putchar(c);
                if (fgetc(file) == '/')
                {
                    tabs -= TAB_SIZE;
                    print_tabs(tabs);
                }
                else tabs += TAB_SIZE;
                break;
            case '>':
                putchar(c);
                putchar('\n');
                if (fgetc(file) != '<')
                {
                    tabs += TAB_SIZE;
                    print_tabs(tabs);
                }
                break;
            case '\n':
                putchar(c);
                print_tabs(tabs);
                break;
            default:
                putchar(c);
                break;
        }
    }
    
    printf("</html>\n");
    fclose(file);
    
    return 0;
}