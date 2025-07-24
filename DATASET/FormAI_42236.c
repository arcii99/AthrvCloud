//FormAI DATASET v1.0 Category: Syntax parsing ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char str[100]; 
    int keywords = 0, i, j, flag;
 
    printf("Enter a C Program:\n");
    fgets(str, 100, stdin);

    // split the program by spaces to parse each token
    char *token = strtok(str, " ");

    while(token != NULL){
        // check if token is a keyword
        char *list_of_keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double",
        "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", 
        "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

        for(i=0; i<32; i++){
            flag = 0;
            if(strcmp(token, list_of_keywords[i]) == 0){
                keywords++;
                flag = 1;
                break;
            }
        }

        if(!flag){
            // check if token is a variable
            if((token[0] >= 'a' && token[0] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z') || token[0] == '_'){
                int len = strlen(token);

                for(i=1; i<len; i++){
                    if((token[i] >= 'a' && token[i] <= 'z') || (token[0] >= 'A' && token[0] <= 'Z') || (token[i] >= '0' && token[i] <= '9') || token[i] == '_'){
                        continue;
                    }
                    else{
                        printf("Syntax Error: Invalid Identifier \"%s\"\n", token);
                        exit(0);
                    }
                }
                printf("Variable Name: %s\n", token);
            }
            // check if token is a constant
            else if(token[0] >= '0' && token[0] <= '9'){
                int len = strlen(token);

                for(i=1; i<len; i++){
                    if(token[i] >= '0' && token[i] <= '9'){
                        continue;
                    }
                    else{
                        printf("Syntax Error: Invalid Constant \"%s\"\n", token);
                        exit(0);
                    }
                }
                printf("Constant: %s\n", token);
            }
            else{
                printf("Syntax Error: Invalid Token \"%s\"\n", token);
                exit(0);
            }
        }

        token = strtok(NULL, " ");
    }

    printf("Total Number of Keywords: %d\n", keywords);
    
    return 0;
}