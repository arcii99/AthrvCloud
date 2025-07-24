//FormAI DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to beautify the HTML code recursively
void beautify(char *code, int depth){
    int i=0,j=0;

    if(code[i] == '\0')
        return;

    while(code[i] != '\0'){
        if(code[i] == '<'){
            if(code[i+1] == '/'){
                depth--;
                for(j=0;j<depth;j++)
                    printf("--");
                printf("   ");
            }
            else{
                for(j=0;j<depth;j++)
                    printf("--");
                printf("+--");
                depth++;
            }
            printf("%s\n", &code[i+1]);
            beautify(&code[i+1], depth);
        }
        i++;
    }
}

int main(){
    char code[] = "<html><body><h1>Hello World</h1><p>This is a paragraph</p></body></html>";
    int depth = 0;

    printf("Original Code:\n%s\n", code);
    printf("\nBeautified Code:\n");
    beautify(code, depth);

    return 0;
}