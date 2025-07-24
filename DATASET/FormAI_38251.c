//FormAI DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void indent(char* html, int len, int spaceNum)
{
    int indentLevel = 0;
    for(int i = 0; i < len; i++)
    {
        if(html[i] == '<')
        {
            if(html[i+1] == '/')
            {   
                indentLevel--;
                printf("\n");
                for(int j = 0; j < indentLevel*spaceNum; j++)
                {
                    printf(" ");
                }
            }
            else
            {
                printf("\n");
                for(int j = 0; j < indentLevel*spaceNum; j++)
                {
                    printf(" ");
                }
                indentLevel++;
            }
        }
        printf("%c", html[i]);
    }
}

int main()
{
    char* html = "<html>\n<head>\n<title>Example</title>\n</head>\n<body>\n<p>Hello World</p>\n</body>\n</html>";
    
    int len = strlen(html);
    indent(html, len, 4);
    
    return 0;
}