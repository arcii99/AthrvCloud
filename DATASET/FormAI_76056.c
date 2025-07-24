//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HTML_LEN 10000
#define MAX_TAB_SIZE 4

void beautify_html(char* html_code);

int main()
{
    char html_code[MAX_HTML_LEN];

    // get user input for HTML code
    printf("Enter HTML code:\n");
    fgets(html_code, MAX_HTML_LEN, stdin);

    // call HTML beautifier function
    beautify_html(html_code);

    return 0;
}

void beautify_html(char* html_code)
{
    int tab_count = 0; // number of tabs to add before each line
    int previous_char_was_tag = 0; // flag to determine if the previous character was an opening tag
    int html_code_len = strlen(html_code); // length of HTML code

    // loop through each character in the HTML code
    for (int i = 0; i < html_code_len; i++)
    {
        char current_char = html_code[i];

        // if the current character is an opening tag, add tabs before it
        if (current_char == '<')
        {
            // check if the previous character was also an opening tag
            if (previous_char_was_tag)
            {
                printf("\n"); // if so, start a new line
            }

            for (int j = 0; j < tab_count; j++)
            {
                printf(" "); // add tabs
            }

            previous_char_was_tag = 1; // set flag to true
        }

        // if the current character is a closing tag, decrement the tab count
        else if (current_char == '>')
        {
            tab_count -= MAX_TAB_SIZE;
            previous_char_was_tag = 0; // set flag to false
        }

        // print the current character
        printf("%c", current_char);

        // if the current character is a space after an equal sign, add a tab
        if (current_char == '=' && html_code[i+1] == ' ')
        {
            printf("\t");
        }

        // if the current character is a newline, increment the tab count
        else if (current_char == '\n')
        {
            tab_count += MAX_TAB_SIZE;
        }
    }
}