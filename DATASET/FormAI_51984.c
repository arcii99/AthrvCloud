//FormAI DATASET v1.0 Category: HTML beautifier ; Style: satisfied
#include <stdio.h>

int is_letter(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int is_digit(char c)
{
    return c >= '0' && c <= '9';
}

void beautify_html(char *source, char *dest)
{
    int i = 0;
    int j = 0;
    int indentation_level = 0;

    while (source[i] != '\0')
    {
        if (source[i] == '<')
        {
            if (source[i+1] == '/')
            {
                indentation_level--;
            }

            for (int k = 0; k < indentation_level; k++)
            {
                dest[j] = '\t';
                j++;
            }
            
            indentation_level++;

            dest[j] = '<';
            j++;

            if (source[i+1] == '/')
            {
                indentation_level++;
            }
        }
        else if (source[i] == '>')
        {
            dest[j] = '>';
            j++;

            if (source[i-1] != '/')
            {
                dest[j] = '\n';
                j++;
            }
        }
        else if (is_letter(source[i]) || is_digit(source[i]) || source[i] == '-')
        {
            dest[j] = source[i];
            j++;
        }

        i++;
    }

    dest[j] = '\0';
}

int main()
{
    char source[] = "<html><head><title>My page<title></head><body><h1>Welcome</h1><p>Here is some text</p></body></html>";
    char dest[1024];

    beautify_html(source, dest);

    printf("%s\n", dest);

    return 0;
}