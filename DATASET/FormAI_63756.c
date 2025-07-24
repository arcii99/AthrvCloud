//FormAI DATASET v1.0 Category: Syntax parsing ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* parse_input(char* input){
    char* output = (char*) malloc(strlen(input) + 1);
    int output_index = 0;
    int nesting_level = 0;

    for(int i = 0; i < strlen(input); i++){
        if(input[i] == '('){
            nesting_level++;
        }
        else if(input[i] == ')'){
            nesting_level--;
        }
        else if(nesting_level > 0){
            continue;
        }
        else{
            output[output_index] = input[i];
            output_index++;
        }
    }

    output[output_index] = '\0';
    return output;
}

int main(){
    char* input = "(a + b) * (c - d)";
    char* output = parse_input(input);
    printf("The parsed input is: %s\n", output);
    free(output);

    return 0;
}