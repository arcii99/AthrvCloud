//FormAI DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <string.h>

void beautify_html(char* input_html, char* output_html)
{
    int i, j, k;
    int indent = 0;
    int len = strlen(input_html);
    char ch, prev_ch;
    
    // iterate through input_html characters
    for(i = 0, j = 0; i < len; i++)
    {
        prev_ch = ch;
        ch = input_html[i];
        
        // skip whitespace after tag
        if(ch == '>' && prev_ch == '/')
        {
            indent--;
        }
        
        // add indentation before tag
        if(ch == '<' && prev_ch != '/')
        {
            for(k = 0; k < indent; k++)
            {
                output_html[j++] = '\t';
            }
            indent++;
        }
        
        // add current character to output
        output_html[j++] = ch;
        
        // add newline after closing tag
        if(ch == '>' && prev_ch == '/')
        {
            output_html[j++] = '\n';
        }
    }
    output_html[j] = '\0';
}

int main()
{
    char input_html[] = "<html><head><title>Example</title></head><body><p>This is an example</p></body></html>";
    char output_html[1000];
    beautify_html(input_html, output_html);
    printf("%s", output_html);

    return 0;
}