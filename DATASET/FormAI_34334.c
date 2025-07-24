//FormAI DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include<stdio.h>
#include<string.h>

/*Function to remove extra spaces in a string*/
void removeSpaces(char* str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ' || str[i+1] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
}

/*Function to beautify HTML code*/
void beautifyHTML(char* code)
{
    char* tag;
    int i = 0, j;
    while (code[i])
    {
        /*If opening tag found*/
        if (code[i] == '<' && code[i+1] != '/')
        {
            /*Print tag*/
            printf("%c", code[i]);
            tag = strtok(&code[i+1], ">");
            removeSpaces(tag);
            printf("%s>\n", tag);
            /*Find corresponding closing tag*/
            j = i + strlen(tag) + 2;
            while (code[j])
            {
                if (code[j] == '<' && code[j+1] == '/')
                {
                    tag = strtok(&code[j+2], ">");
                    removeSpaces(tag);
                    /*Print closing tag*/
                    for (int k = 0; k < i+2; k++)
                        printf(" ");
                    printf("</%s>\n", tag);
                    i = j+3+strlen(tag);
                    break;
                }
                j++;
            }
        }
        else
            printf("%c", code[i]);
        i++;
    }
}

int main()
{
    char code[1000] = "<html>  <head>  <title> Title </title>  </head>  <body>  <h1> Heading </h1>  <p> Paragraph 1 </p>  <p> Paragraph 2 </p>  </body>  </html>";
    beautifyHTML(code);
    return 0;
}