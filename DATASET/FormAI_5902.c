//FormAI DATASET v1.0 Category: Syntax parsing ; Style: immersive
#include <stdio.h>

int main() 
{
    printf("Welcome to my C Syntax parsing program. \n");
    printf("Please input a valid C code statement to be parsed: \n");
    
    char input[100];
    fgets(input, 100, stdin); //getting user input
    
    int length = sizeof(input)/sizeof(input[0]); //determining length of input
    
    //checking for semicolon at end of statement
    if(input[length-2] != ';') {
        printf("ERROR: Statement does not end with semicolon. \n");
        return 0;
    }
    
    //counting number of variables in statement
    int var_count = 0;
    for(int i=0; i<length; i++) {
        if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
            var_count++;
        }
    }
    
    //checking for correct variable declaration
    if(input[0] == 'i' && input[1] == 'n' && input[2] == 't') {
        if(var_count > 1) {
            printf("ERROR: Too many variables declared. \n");
            return 0;
        }
        printf("Variable declared successfully. \n");
        
        //checking for variable name length
        if(var_count > 0 && var_count <= 10) {
            printf("Variable name length is acceptable. \n");
        } else {
            printf("ERROR: Variable name length is too long. \n");
            return 0;
        }
    } else {
        printf("ERROR: Incorrect variable declaration. \n");
        return 0;
    }
    
    //checking for assignment operator
    int assign_op_present = 0;
    for(int i=0; i<length; i++) {
        if(input[i] == '=') {
            assign_op_present = 1;
            break;
        }
    }
    if(assign_op_present) {
        printf("Assignment operator present. \n");
    } else {
        printf("ERROR: Assignment operator missing. \n");
        return 0;
    }
    
    //checking for valid expression on RHS of assignment operator
    int rhs_start_index = 0;
    for(int i=0; i<length; i++) {
        if(input[i] == '=') {
            rhs_start_index = i+1;
            break;
        }
    }
    int rhs_length = length - rhs_start_index - 2; //excluding semicolon and null terminator
    char rhs_expression[rhs_length];
    for(int i=0; i<rhs_length; i++) {
        rhs_expression[i] = input[rhs_start_index+i];
    }
    if(rhs_expression[0] >= '0' && rhs_expression[0] <= '9') {
        printf("Valid expression detected. \n");
    } else {
        printf("ERROR: Invalid expression detected. \n");
        return 0;
    }
    
    printf("Code statement parsed successfully. \n");
    return 0;
}