//FormAI DATASET v1.0 Category: HTML beautifier ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to check for tags and replace them with pretty-looking html code
char *beautify(char *html)
{
    int i,j,cnt=0;
    char *temp = (char*)malloc(strlen(html) * sizeof(char));
    for(i=0; html[i]!='\0'; i++)
    {
        if(html[i]=='<')
        {
            while(html[i]!='>')
            {
                temp[j++]=html[i++];
            }
            temp[j++]=html[i];
            cnt++;
        }
        else
        {
            temp[j++]=html[i];
        }
    }
    temp[j]='\0';
    //allocate space for the new beautified code
    char *new_code = (char*)malloc((strlen(temp) + 2*cnt) * sizeof(char));
    i=0; 
    j=0;
    //loop to add new tags for indentation
    while(temp[i]!='\0')
    {
        if(temp[i]=='<')
        {
            new_code[j++]='\n';
            new_code[j++]='\t';
            while(temp[i]!='>')
            {
                new_code[j++]=temp[i++];
            }
            new_code[j++]=temp[i];
        }
        else
        {
            new_code[j++]=temp[i];
        }
        i++;
    }
    new_code[j]='\0';
    return new_code;
}

int main()
{
    char html_code[] = "<html><head><title>Page Title</title></head><body><h1>This is a heading</h1><p>This is a paragraph.</p></body></html>";

    printf("Original HTML code:\n%s\n\n", html_code);

    char *beautified_code = beautify(html_code);

    printf("Beautified HTML code:\n%s\n", beautified_code);

    free(beautified_code);

    return 0;
}