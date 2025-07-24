//FormAI DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* beautify_html(char* html){
    char* beautified_html = (char*)malloc(sizeof(char)*strlen(html)*2); // double the memory allocation
    int indent_level = 0;
    int len = strlen(html);
    int i, j, k;
    for(i=0, j=0; i<len; i++){
        if(html[i] == '<'){
            if(html[i+1] == '/'){ // closing tag
                indent_level--;
                for(k=0; k<indent_level; k++){
                    beautified_html[j++] = '\t';
                }
            }
            else{ // opening tag
                for(k=0; k<indent_level; k++){
                    beautified_html[j++] = '\t';
                }
                indent_level++;
            }
        }
        beautified_html[j++] = html[i];
        if(html[i] == '>'){
            beautified_html[j++] = '\n';
        }
    }
    beautified_html[j] = '\0';
    return beautified_html;
}

int main(){
    char* html = "<html><head><title>My Website</title></head><body><h1>Welcome!</h1><p>This is my website.</p></body></html>";
    char* beautified_html = beautify_html(html);
    printf("%s\n", beautified_html);
    return 0;
}