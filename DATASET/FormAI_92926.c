//FormAI DATASET v1.0 Category: HTML beautifier ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to beautify the HTML code
void beautify_html(char* html_code)
{
    int i, j, k;
    int indent_level = 0;
    int num_tags = 0;
    int num_attributes = 0;
    char tag[50];
    char attribute[50];
    char value[100];

    // loop through the HTML code character by character
    for(i=0; i<strlen(html_code); i++)
    {
        // check if the current character is a tag start
        if(html_code[i] == '<' && html_code[i+1] != '/')
        {
            num_tags++;

            // extract the tag name
            j = i+1;
            k = 0;
            while(html_code[j] != ' ' && html_code[j] != '>')
            {
                tag[k] = html_code[j];
                j++;
                k++;
            }
            tag[k] = '\0';

            printf("\n");

            // indent the tag based on its level
            for(k=0; k<indent_level; k++)
            {
                printf("  ");
            }
            printf("<%s", tag);

            // extract the tag attributes
            while(html_code[j] != '>')
            {
                if(html_code[j] == ' ' && html_code[j+1] != '/')
                {
                    num_attributes++;

                    // extract the attribute name
                    j++;
                    k = 0;
                    while(html_code[j] != '=')
                    {
                        attribute[k] = html_code[j];
                        j++;
                        k++;
                    }
                    attribute[k] = '\0';

                    // extract the attribute value
                    j++;
                    k = 0;
                    while(html_code[j] != ' ' && html_code[j] != '>')
                    {
                        value[k] = html_code[j];
                        j++;
                        k++;
                    }
                    value[k] = '\0';

                    // print the attribute with proper spacing
                    printf(" %s=\"%s\"", attribute, value);
                }
                j++;
            }

            printf(">");

            indent_level++;

            // add a line break if the tag is a header or paragraph
            if(strcmp(tag, "h1") == 0 || strcmp(tag, "h2") == 0 || strcmp(tag, "p") == 0)
            {
                printf("\n");
            }
        }
        else if(html_code[i] == '<' && html_code[i+1] == '/')
        {
            // decrease the indent level if this is a closing tag
            indent_level--;

            // find the tag name and print it with proper indentation
            j = i+2;
            k = 0;
            while(html_code[j] != '>')
            {
                tag[k] = html_code[j];
                j++;
                k++;
            }
            tag[k] = '\0';

            printf("\n");

            for(k=0; k<indent_level; k++)
            {
                printf("  ");
            }

            printf("</%s>", tag);
        }
        else
        {
            // print the character if it is not part of a tag
            printf("%c", html_code[i]);
        }
    }

    printf("\n\nNumber of tags: %d", num_tags);
    printf("\nNumber of attributes: %d\n", num_attributes);
}

// main function
int main()
{
    char html_code[1000];

    printf("Enter the HTML code to beautify:\n");
    fgets(html_code, 1000, stdin);

    beautify_html(html_code);

    return 0;
}