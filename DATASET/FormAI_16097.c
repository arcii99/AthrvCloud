//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void beautify(char* html){
    int indent_level = 0;
    int i = 0;
    int j = 0;

    while(html[i] != '\0'){
        if(html[i] == '<'){
            if(html[i+1] == '/'){
                indent_level--;
            }
            for(int k = 0; k < indent_level; k++){
                printf("    ");
            }
            if(html[i+1] != '/'){
                indent_level++;
            }
        }
        putchar(html[i]);
        if(html[i] == '>'){
            putchar('\n');
        }
        i++;
    }
}

int main(){
    char* html = "<html><head><title>Page Title</title></head><body><h1>My First Heading</h1><p>My first paragraph.</p></body></html>";
    beautify(html);
    return 0;
}