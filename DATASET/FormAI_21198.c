//FormAI DATASET v1.0 Category: HTML beautifier ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENTATION "    " //This is the indentation character

void beautify(char *html_string) {
    int i, j, k; //Counters for the loops
    int indentation_level = 0; //Tracks how deeply nested we are
    int html_length = strlen(html_string); //Find length of the HTML string
    char output[html_length * 2]; //Assuming each line might be twice as long

    //Loop through the string character by character
    for (i = 0, k = 0; i < html_length; i++) {
        if (html_string[i] == '<' && html_string[i + 1] != '/') {
            //If we encounter an opening tag, increase the indentation level and add appropriate indentation
            for (j = 0; j < indentation_level; j++) {
                output[k++] = INDENTATION[j % strlen(INDENTATION)];
            }
            indentation_level++;
        }
        if (html_string[i] == '<' && html_string[i + 1] == '/') {
            //If we encounter a closing tag, decrease the indentation level and add appropriate indentation
            indentation_level--;
            for (j = 0; j < indentation_level; j++) {
                output[k++] = INDENTATION[j % strlen(INDENTATION)];
            }
        }
        output[k++] = html_string[i]; //Add the character to our output string
        if (html_string[i] == '>') {
            //If we encounter a closing bracket, add a newline character and appropriate indentation
            output[k++] = '\n';
            for (j = 0; j < indentation_level; j++) {
                output[k++] = INDENTATION[j % strlen(INDENTATION)];
            }
        }
    }
    output[k] = '\0'; //Add string terminator

    //Print the beautified HTML string
    printf("%s", output);
}

int main() {
    char *html_string = "<html><head><title>My website</title></head><body><h1>Welcome!</h1><p>Thanks for visiting my website!</p></body></html>";
    beautify(html_string);
    return 0;
}