//FormAI DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// A function to beautify HTML code
void beautify_html(char *html_code){

    // Variables to store indent level and length of code
    int indent = 0;
    int len = strlen(html_code);

    for(int i=0; i<len; i++){

        // Check if opening tag exists
        if (html_code[i] == '<' && html_code[i+1] != '/'){

            // Increase indent, insert newline and tabs
            indent++;
            printf("\n");

            for(int j=0; j<indent; j++){
                printf("\t");
            }

            // Printing opening tag
            printf("%c", html_code[i]);

            // Printing tag attributes
            while(html_code[i] != '>'){
                printf("%c", html_code[i]);
                i++;
            }

            printf("%c", html_code[i]);
        }

        // Handle closing tags
        else if (html_code[i] == '<' && html_code[i+1] == '/'){

            // Decrease indent, insert newline and tabs
            indent--;
            printf("\n");

            for(int j=0; j<indent; j++){
                printf("\t");
            }

            // Printing closing tag
            printf("%c", html_code[i]);

            // Printing tag name
            while(html_code[i] != '>'){
                printf("%c", html_code[i]);
                i++;
            }

            printf("%c", html_code[i]);
        }

        // Handle text content
        else{
            // If there is a newline before text content, insert tabs
            if(html_code[i-1] == '\n'){
                printf("\n");

                for(int j=0; j<indent; j++){
                    printf("\t");
                }
            }

            printf("%c", html_code[i]);
        }
    }
}

int main(){

    // HTML code to beautify
    char code[] = "<html>\n\t<head>\n\t\t<title>My Website</title>\n\t</head>\n\t<body>\n\t\t<h1>Welcome to my Website</h1>\n\t\t<p>This is a paragraph of text.</p>\n\t\t<p>This is another paragraph</p>\n\t</body>\n</html>";

    // Call the beautify_html function
    beautify_html(code);

    return 0;
}