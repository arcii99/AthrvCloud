//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// function to beautify the given HTML code
char *beautifyHtml(char *html, int len)
{
    // create the required variables for the function
    char *result = malloc(len * sizeof(char) * 2);
    int indentLevel = 0;
    int index = 0;
    int openTag = 0;
    int closeTag = 0;

    // loop over the HTML code to process each character
    for (int i = 0; i < len; i++)
    {
        // handle opening tag
        if (html[i] == '<' && html[i+1] != '/')
        {
            openTag = 1;
            closeTag = 0;
        }
        // handle closing tag
        else if (html[i] == '<' && html[i+1] == '/')
        {
            indentLevel--;
            openTag = 0;
            closeTag = 1;
        }

        // add indentation before the opening tag
        if (openTag && !closeTag)
        {
            for (int j = 0; j < indentLevel; j++)
            {
                result[index++] = ' ';
            }
            indentLevel += 2;
        }

        // add the current character to the result string
        result[index++] = html[i];

        // add a new line after the closing tag
        if (closeTag)
        {
            result[index++] = '\n';
            for (int j = 0; j < indentLevel; j++)
            {
                result[index++] = ' ';
            }
            closeTag = 0;
        }
    }

    // terminate the result string with a null character
    result[index++] = '\0';

    // return the beautified HTML code
    return result;
}

// main function to test the HTML beautifier
int main()
{
    // create a sample HTML code
    char html[200] = "<html><head><title>My Website</title></head><body><h1>Welcome to my website!</h1><p>This is a paragraph.</p></body></html>";

    // beautify the HTML code
    char *beautifiedHtml = beautifyHtml(html, strlen(html));

    // print the beautified HTML code
    printf("%s", beautifiedHtml);

    // free the dynamically allocated memory
    free(beautifiedHtml);

    return 0;
}