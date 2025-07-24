//FormAI DATASET v1.0 Category: Text processing ; Style: paranoid
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_LINE_LENGTH 80
#define PARANOID_SYNTAX_CHECK "printf"

int main(){
    char input[MAX_INPUT_LENGTH];
    char line[MAX_LINE_LENGTH];
    int line_num = 1;
    int paranoid_syntax_error = 0;
    
    printf("Enter your text (max length is %d):\n", MAX_INPUT_LENGTH);
    fgets(input, MAX_INPUT_LENGTH, stdin);
    
    memset(line, 0, MAX_LINE_LENGTH);
    
    for(int i = 0; i < strlen(input); i++){
        if(input[i] != '\n'){
            line[strlen(line)] = input[i];
        }
        
        if(strlen(line) == MAX_LINE_LENGTH - 1 || input[i] == '\n'){
            if(strstr(line, PARANOID_SYNTAX_CHECK)){
                paranoid_syntax_error = 1;
                printf("\n\nParanoid syntax error found:\nLine %d: %s\n\n", line_num, line);
            }
            
            memset(line, 0, MAX_LINE_LENGTH);
            line_num++;
        }
    }
    
    if(!paranoid_syntax_error){
        printf("\nNo paranoid syntax errors found.\n");
    }
    
    return 0;
}