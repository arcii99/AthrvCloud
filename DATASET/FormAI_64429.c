//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// function to beautify the HTML code
char* beautify(char* html, int indent_size, int max_char_per_line)
{
    int indent_level = 0;
    int line_len = 0;
    int len = strlen(html);
    
    char* beautified_html = (char*)malloc(sizeof(char)*(len+1));
    char* indent = (char*)malloc(sizeof(char)*(indent_size+1));
    char* line = (char*)malloc(sizeof(char)*(max_char_per_line+1));
    
    memset(beautified_html, 0, len+1);
    memset(indent, ' ', indent_size);
    memset(line, 0, max_char_per_line+1);
    
    for(int i=0; i<len; i++)
    {
        if(html[i] == '<')
        {
            if(html[i+1] == '/') indent_level--;
            
            for(int j=0; j<indent_level*indent_size; j++)
                strcat(beautified_html, " ");
            
            strcat(beautified_html, "<");
            if(html[i+1] != '/') indent_level++;
        }
        else if(html[i] == '>')
        {
            strcat(beautified_html, ">");
            strcat(beautified_html, "\n");

            for(int j=0; j<indent_level*indent_size; j++)
                strcat(beautified_html, " ");
        }
        else
        {
            if(line_len+1 > max_char_per_line)
            {
                strcat(beautified_html, line);
                strcat(beautified_html, "\n");
                memset(line, 0, max_char_per_line+1);
                line_len = 0;
                for(int j=0; j<indent_level*indent_size; j++)
                    strcat(beautified_html, " ");
            }

            char ch[2];
            ch[0] = html[i];
            ch[1] = '\0';

            strcat(line, ch);
            line_len++;
        }
    }

    strcat(beautified_html, line);
    strcat(beautified_html, "\n");

    free(indent);
    free(line);

    return beautified_html;
}

int main()
{
    char html[] = "<html><head><title>Page Title</title></head><body><h1>This is a Heading</h1><p>This is a paragraph.</p></body></html>";
    char* beautified_html = beautify(html, 4, 80);
    printf("%s", beautified_html);
    free(beautified_html);
    return 0;
}