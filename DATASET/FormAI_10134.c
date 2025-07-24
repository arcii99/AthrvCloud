//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TAB_SIZE 4

void insert_char(char *buf, char c, int *pos, int *length, int max_length)
{
    if(*pos >= max_length-1)
    {
        printf("Error: Input buffer overflow.\n");
        exit(1);
    }
    buf[*pos] = c;
    (*pos)++;
    (*length)++;
    return;
}

void beautify_html(char *input, char *output, int max_output_length, int tab_size, int indent_start, int indent_width)
{
    int input_pos = 0;
    int output_pos = 0;
    int tag_depth = 0;
    int line_length = 0;
    int indent_level = 0;
    char tag_name[64] = {'\0'};
    int tag_name_pos = 0;
    int tag_name_max_length = 64;

    while(input[input_pos] != '\0')
    {
        // If we encounter a tag name, store it in tag_name buffer
        if(input[input_pos] == '<')
        {
            tag_depth++;
            tag_name_pos = 0;
            // Skip over any leading whitespace
            while(input[input_pos] != '\0' && input[input_pos] != '>' && isspace(input[input_pos])) input_pos++;
            // Copy the tag name into tag_name buffer
            while(input[input_pos] != '\0' && input[input_pos] != '>' && !isspace(input[input_pos]) && tag_name_pos < tag_name_max_length-1)
            {
                tag_name[tag_name_pos] = input[input_pos];
                tag_name_pos++;
                input_pos++;
            }
            tag_name[tag_name_pos] = '\0';
            // If this tag is a closing tag, decrease the tag depth and indent level
            if(tag_name[0] == '/')
            {
                tag_depth--;
                indent_level--;
                // If this is the last tag on a line, insert a newline
                if(line_length > 0)
                {
                    insert_char(output, '\n', &output_pos, &max_output_length, max_output_length);
                    line_length = 0;
                }
            }
            else
            {
                // If this is the first tag on a line, insert indentation
                if(line_length == 0)
                    for(int i = 0; i < indent_width*indent_level; i++)
                        insert_char(output, ' ', &output_pos, &max_output_length, max_output_length);
                // Insert the tag name
                for(int i = 0; i < tag_name_pos; i++)
                    insert_char(output, tag_name[i], &output_pos, &max_output_length, max_output_length);
                // If this tag is self-closing, decrease the tag depth
                if(input[input_pos-1] == '/')
                    tag_depth--;
                // If this tag is not self-closing and not on the same line as its contents, insert a newline
                if(input[input_pos] != '/' && input[input_pos-1] != '/')
                {
                    insert_char(output, '\n', &output_pos, &max_output_length, max_output_length);
                    line_length = 0;
                }
                // Increase the indent level for the next line
                if(indent_start >= 0 && tag_depth == indent_start+1)
                    indent_level++;
            }
            // Skip over any trailing whitespace
            while(input[input_pos] != '\0' && input[input_pos] != '>') input_pos++;
        }
        else
        {
            // Copy over any non-tag characters
            insert_char(output, input[input_pos], &output_pos, &max_output_length, max_output_length);
            input_pos++;
            line_length++;
        }
        // If the line is longer than the maximum length, split it
        if(line_length >= 80)
        {
            insert_char(output, '\n', &output_pos, &max_output_length, max_output_length);
            for(int i = 0; i < indent_width*indent_level; i++)
                insert_char(output, ' ', &output_pos, &max_output_length, max_output_length);
            line_length = indent_width*indent_level;
        }
    }
    output[output_pos] = '\0';
}

int main()
{
    char input[] = "<html><head><title>My page</title></head><body><h1>Welcome to my page</h1><p>This is my first web page!</p></body></html>";
    char output[1024 * 1024] = {'\0'};
    beautify_html(input, output, 1024 * 1024, TAB_SIZE, 0, 0);
    printf("%s\n", output);
    return 0;
}