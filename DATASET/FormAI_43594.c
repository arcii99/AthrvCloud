//FormAI DATASET v1.0 Category: HTML beautifier ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAB_SIZE 4

void indent(int level)
{
    for (int i = 0; i < level * TAB_SIZE; i++)
    {
        putchar(' ');
    }
}

int main()
{
    FILE *fp = fopen("input.html", "r");
    if (!fp)
    {
        printf("Error: cannot open file.\n");
        return 1;
    }
    
    int c, last_c = '\n', level = 0;
    bool in_tag = false, in_string = false;
    int string_delim = '\0';
    
    while ((c = fgetc(fp)) != EOF)
    {
        if (in_string)
        {
            if (c == string_delim)
            {
                in_string = false;
            }
            putchar(c);
            continue;
        }
        
        switch (c)
        {
            case '<':
                if (in_tag)
                {
                    // nested tag
                    putchar(c);
                }
                else
                {
                    in_tag = true;
                    indent(level);
                    putchar(c);
                    if (last_c != '\n')
                    {
                        putchar('\n');
                    }
                    level++;
                }
                break;
            
            case '>':
                if (in_tag)
                {
                    putchar(c);
                    if (last_c != '\n' && last_c != '>')
                    {
                        putchar('\n');
                    }
                    level--;
                    in_tag = false;
                }
                else
                {
                    putchar(c);
                }
                break;
            
            case '\'':
            case '\"':
                in_string = true;
                string_delim = c;
                putchar(c);
                break;
            
            case '/':
                if (in_tag)
                {
                    putchar(c);
                }
                else
                {
                    // probably a comment, just print it out
                    putchar(c);
                }
                break;
            
            case '\n':
                if (in_tag || last_c == '\n')
                {
                    // multiple newlines inside a tag or
                    // extra newline after a tag, ignore it
                    break;
                }
                putchar(c);
                break;
            
            default:
                putchar(c);
        }
        
        last_c = c;
    }
    
    fclose(fp);
    return 0;
}