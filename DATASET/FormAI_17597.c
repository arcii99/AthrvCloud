//FormAI DATASET v1.0 Category: HTML beautifier ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* beautify(char *code){
    char *beautified_code = malloc(1024);
    int indent = 0, i = 0;
    int len = strlen(code);

    while(i < len){
        char curr_char = code[i];

        // If we find tag, we will add the current indent and increment the indent.
        if(curr_char == '<'){
            strcat(beautified_code, "<br>\n");
            for(int j = 0; j < indent; j++){
                strcat(beautified_code, "   ");
            }   
            indent++;
        }

        // If we find closing tag, we will decrement the indent and add current indent.
        else if(curr_char == '>'){
            strcat(beautified_code, ">");
            strcat(beautified_code, "\n");
            if(i+1 < len && code[i+1] != '<'){
                for(int j = 0; j < indent; j++){
                    strcat(beautified_code, "   ");
                }                   
            }
        }

        // If we find comment, we will add the current indent and print the comment line by line.
        else if(curr_char == '<' && code[i+1] == '!' && code[i+2] == '-' && code[i+3] == '-'){
            strcat(beautified_code, "<!--");
            strcat(beautified_code, "\n");
            for(int j = 0; j < indent; j++){
                strcat(beautified_code, "   ");
            }               
            while(curr_char != '>'){
                i++;
                curr_char = code[i];
                strncat(beautified_code, &curr_char, 1);
            }
            strcat(beautified_code, "\n");
            for(int j = 0; j < indent; j++){
                strcat(beautified_code, "   ");
            }               
            strcat(beautified_code, "-->");
        }
        
        // If we find a space, we just continue with the next character.
        else if(curr_char == ' ' && i+1 < len && code[i+1] == '<'){
            continue;
        }

        // We add the current character.
        else{
            strncat(beautified_code, &curr_char, 1);
        }
        i++;
    }
    return beautified_code;
}

int main(){
    char code[1024] = "<html><head><title>My title</title></head><body><div class=\"myClass\" id=\"myId\"><p>My paragraph1</p><p>My paragraph2</p></div><!-- My comment --><h1>My header</h1></body></html>";
    char *beautified_code = beautify(code);
    printf("%s", beautified_code);
    free(beautified_code);
    return 0;
}