//FormAI DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* beautify(char* html){
    char* beautified;
    int indentation = 0;
    int i, j;
    int length = strlen(html);
    beautified = (char*) malloc(sizeof(char) * (length * 2));
    for(i = 0, j = 0; i < length; i++){
        if(html[i] == '<'){
            beautified[j++] = html[i];
            if(html[i + 1] == '/'){
                indentation--;
            }
            else {
                indentation++;
            }
            while(html[i] != '>'){
                if(html[i] == '"' || html[i] == '\''){
                    beautified[j++] = html[i++];
                    while(html[i] != beautified[j - 1]){
                        beautified[j++] = html[i++];
                    }
                }
                beautified[j++] = html[i++];
            }
            beautified[j++] = html[i];
            beautified[j++] = '\n';
            while(indentation--){
                beautified[j++] = '\t';
            }
        }
        else {
            beautified[j++] = html[i];
        }
    }
    beautified[j++] = '\0';
    return beautified;
}

int main(){
    char* html = "<html><head><title>Hello World</title></head><body><h1>Welcome to my page</h1></body></html>";
    char* beautified = beautify(html);
    printf("%s", beautified);
    free(beautified);
    return 0;
}