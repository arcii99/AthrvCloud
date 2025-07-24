//FormAI DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the size of the buffer
#define BUFFER_SIZE 1024

// Function to beautify the HTML code
void html_beautifier(char *html)
{
    // Initialize variables
    int i, j, k;
    int depth = 0;
    int is_inline = 0;
    int is_opening_tag = 0;
    int is_closing_tag = 0;
    int is_closed = 0;
    char buffer[BUFFER_SIZE];
    
    // Loop through the HTML code
    for (i = 0; i < strlen(html); i++)
    {
        // Check for opening tag
        if (html[i] == '<')
        {
            // Check for closing tag
            if (html[i+1] == '/')
            {
                is_closing_tag = 1;
                is_opening_tag = 0;
            }
            // Check for inline tag
            else if (html[i+1] == 'a' || html[i+1] == 'b' || html[i+1] == 'i' || html[i+1] == 's' || html[i+1] == 'u')
            {
                is_inline = 1;
            }
            else
            {
                is_opening_tag = 1;
                is_closing_tag = 0;
            }
        }
        // Check for closing tag
        else if (html[i] == '>')
        {
            // Check if inline tag ended
            if (is_inline == 1 && html[i-1] != '/')
            {
                depth--;
                printf("\n");
                for (k = 0; k < depth; k++)
                {
                    printf("  ");
                }
            }
            // Check for self-closing tag
            if (html[i-1] == '/')
            {
                is_closing_tag = 1;
                is_opening_tag = 0;
            }
            is_inline = 0;
            is_closed = 0;
            printf("%c\n", html[i]);
        }
        // Check for newline character
        else if (html[i] == '\n')
        {
            // Skip the newline character
            continue;
        }
        // Check for space character
        else if (html[i] == ' ')
        {
            // Skip the space character
            continue;
        }
        else
        {
            // Output the character
            printf("%c", html[i]);
        }
        
        // Check if this is a closing tag
        if (is_closing_tag == 1 && html[i] == '>')
        {
            depth--;
            printf("\n");
            for (j = 0; j < depth; j++)
            {
                printf("  ");
            }
        }
        // Check if this is an opening tag
        if (is_opening_tag == 1 && html[i] == '>')
        {
            depth++;
            printf("\n");
            for (k = 0; k < depth; k++)
            {
                printf("  ");
            }
        }
    }
}

// Main function
int main()
{
    // Sample HTML code
    char html[] = "<html><head><title>Test Page</title></head><body><div><p>Hello, World!</p></div></body></html>";
    
    // Beautify HTML code
    html_beautifier(html);
    
    return 0;
}