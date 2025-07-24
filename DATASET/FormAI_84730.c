//FormAI DATASET v1.0 Category: HTML beautifier ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void beautify(char* source)
{
    int i,j,idx=0,indent=0;
    char buffer[1000];
    for(i = 0; i < strlen(source); i++)
    {
        if(source[i] == '<')
        {
            if(source[i+1] == '/')
            {
                indent--;
                for(j=0;j<indent;j++)
                {
                    buffer[idx++] = '\t';
                }
            }
            else
            {
                for(j=0;j<indent;j++)
                {
                    buffer[idx++] = '\t';
                }
                indent++;
            }
        }
        buffer[idx++] = source[i];
        if(source[i] == '>')
        {
            buffer[idx++] = '\n';
        }
    }
    buffer[idx] = '\0';
    strcpy(source, buffer);
}

int main()
{
    char source[1000];
    printf("Enter the HTML code to be beautified:\n");
    fgets(source, 1000, stdin);
    beautify(source);
    printf("\nBeautified Code:\n%s", source);
    return 0;
}