//FormAI DATASET v1.0 Category: HTML beautifier ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 5000

// function to check if a character is a white space
bool isWhiteSpace(char ch)
{
    if(ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
        return true;
    return false;
}

// function to beautify a given HTML code
void beautifyHTML(char* code)
{
    int level = 0;
    bool isInTag = false;
    char tag[MAX_SIZE] = "";
    int tagIndex = 0;
    char indentedCode[MAX_SIZE] = "";
    int indentedCodeIndex = 0;

    for(int i=0; i<strlen(code); i++)
    {
        if(code[i] == '<')
        {
            isInTag = true;
            if(i > 0 && !isWhiteSpace(code[i-1]))
            {
                printf("\n");
            }
        }
        else if(code[i] == '>')
        {
            if(tag[0] == '/')
            {
                level--;
            }
            if(!isWhiteSpace(code[i-1]) && code[i-1] != '/')
            {
                printf("\n");
                for(int j=0; j<(level*4); j++)
                {
                    printf(" ");
                }
            }
            printf("%s", tag);
            if(tag[0] != '/')
            {
                level++;
            }
            memset(tag, 0, sizeof(tag));
            tagIndex = 0;
            isInTag = false;
        }
        if(isInTag)
        {
            if(i > 0 && isWhiteSpace(code[i-1]) && !isWhiteSpace(code[i]) && code[i] != '>')
            {
                for(int j=0; j<(level*4); j++)
                {
                    tag[tagIndex] = ' ';
                    tagIndex++;
                }
            }
            tag[tagIndex] = code[i];
            tagIndex++;
        }
        else
        {
            printf("%c", code[i]);
        }
    }
}

int main()
{
    char* code = "<html><head><title>My Website</title></head>\n\n<body>\n<h1>Welcome to my website!</h1>\n<p>Here you can find a lot of information about me and my hobbies.</p>\n\n<ul>\n<li>Hiking</li>\n<li>Photography</li>\n<li>Traveling</li>\n</ul>\n\n<p>Feel free to contact me if you have any questions. Enjoy!</p>\n</body></html>";
    beautifyHTML(code);
    return 0;
}