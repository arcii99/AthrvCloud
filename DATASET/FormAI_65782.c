//FormAI DATASET v1.0 Category: Syntax parsing ; Style: introspective
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void parse_function(char* line){
    char function_name[50];
    int i;
    for(i=0; line[i]!='(' ;i++){
        function_name[i] = line[i];
    }
    function_name[i] = '\0';
    printf("Parsed function name: %s\n", function_name);
}

void parse_statement(char* line){
    if(strstr(line, "int") != NULL || strstr(line, "float") != NULL || strstr(line, "char") != NULL){
        //It is a variable declaration
        printf("Parsed statement: [Variable Declaration] %s\n", line);
    }else if(strstr(line, "(") != NULL){
        //It is a function call
        printf("Parsed statement: [Function Call] %s\n", line);
        parse_function(line);
    }else{
        //It is a plain statement
        printf("Parsed statement: [Plain Statement] %s\n", line);
    }
}

int main(){
    char code_snippet[500];
    printf("Enter a code snippet:\n");
    fgets(code_snippet, 500, stdin);
    printf("You entered: %s\n", code_snippet);

    char* line = strtok(code_snippet, ";"); //Separate the code snippet into lines
    while(line != NULL){
        parse_statement(line);
        line = strtok(NULL, ";");
    }

    return 0;
}