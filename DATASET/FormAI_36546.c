//FormAI DATASET v1.0 Category: HTML beautifier ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* beautify_html(char* unformatted_html){
    char* formatted_html = malloc(strlen(unformatted_html) * sizeof(char));
    int indent_level = 0;
    int token_start = 0;
    int token_end = 0;

    for(int i = 0; i < strlen(unformatted_html); i++){
        if(unformatted_html[i] == '<') { // Opening tag
            if(unformatted_html[i+1] == '/') indent_level--; // Closing tag
            if(token_start != token_end){ // If content exists before opening tag
                formatted_html = realloc(formatted_html, (strlen(formatted_html)+1) * sizeof(char));
                formatted_html[strlen(formatted_html)] = '\n';
                for(int j = 0; j < indent_level; j++) strcat(formatted_html, "  ");
                strncat(formatted_html, &unformatted_html[token_start], token_end - token_start);
            }
            formatted_html = realloc(formatted_html, (strlen(formatted_html)+1) * sizeof(char));
            formatted_html[strlen(formatted_html)] = '\n';
            for(int j = 0; j < indent_level; j++) strcat(formatted_html, "  ");
            strncat(formatted_html, &unformatted_html[i], 1);
            token_start = i+1;
            token_end = token_start;
            if(unformatted_html[i+1] != '/') indent_level++; // Opening tag
        }
        else if(unformatted_html[i] == '>') { // Closing tag
            token_end = i;
        }
    }
    if(token_start != token_end){ // Check if there is still content at the end of the input
        formatted_html = realloc(formatted_html, (strlen(formatted_html)+1) * sizeof(char));
        formatted_html[strlen(formatted_html)] = '\n';
        for(int j = 0; j < indent_level; j++) strcat(formatted_html, "  ");
        strncat(formatted_html, &unformatted_html[token_start], token_end - token_start);
    }
    return formatted_html;
}

int main(){
    char input_html[500] = "<html><head><title>Example HTML Document</title></head><body><h1>Welcome!</h1><p>This is an example HTML document.</p></body></html>";
    char* formatted_html = beautify_html(input_html);
    printf("%s", formatted_html);
    return 0;
}