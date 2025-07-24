//FormAI DATASET v1.0 Category: Syntax parsing ; Style: genious
//Genius Style C Syntax Parser
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char input[100];
    printf("Enter a C program to parse:\n");
    fgets(input, 100, stdin);

    char* single_space = (char*)malloc(sizeof(char) * strlen(input)); 
    int space_count = 0;
    int i;
    for(i = 0; i < strlen(input); i++){
        if(input[i] == '\n'){
            break;
        }
        else if(input[i] == ' ' && input[i-1] != ' '){ 
            single_space[space_count] = ' ';
            space_count++;
        }
        else if(input[i] != ' '){ 
            single_space[space_count] = input[i];
            space_count++;
        }
    }
    single_space[space_count] = '\0';
    printf("Single space string:\n%s\n", single_space);

    int curly_count = 0; 
    int rounded_count = 0;
    int square_count = 0;
    int if_count = 0;
    int for_count = 0;
    int while_count = 0;
    int do_count = 0;
    int switch_count = 0;
    int case_count = 0;
    int comment_count = 0;
    int operator_count = 0;
    int variable_count = 0;

    for(i = 0; i < strlen(single_space); i++){
        if(single_space[i] == '{'){
            curly_count++;
        }
        else if(single_space[i] == '}'){
            curly_count--;
        }
        else if(single_space[i] == '('){
            rounded_count++;
        }
        else if(single_space[i] == ')'){
            rounded_count--;
        }
        else if(single_space[i] == '['){
            square_count++;
        }
        else if(single_space[i] == ']'){
            square_count--;
        }
        else if(single_space[i] == 'i' && single_space[i+1] == 'f' && single_space[i+2] == ' '){
            if_count++;
        }
        else if(single_space[i] == 'f' && single_space[i+1] == 'o' && single_space[i+2] == 'r' && single_space[i+3] == ' '){
            for_count++;
        }
        else if(single_space[i] == 'w' && single_space[i+1] == 'h' && single_space[i+2] == 'i' && single_space[i+3] == 'l' && single_space[i+4] == 'e' && single_space[i+5] == ' '){
            while_count++;
        }
        else if(single_space[i] == 'd' && single_space[i+1] == 'o' && single_space[i+2] == ' '){
            do_count++;
        }
        else if(single_space[i] == 's' && single_space[i+1] == 'w' && single_space[i+2] == 'i' && single_space[i+3] == 't' && single_space[i+4] == 'c' && single_space[i+5] == 'h' && single_space[i+6] == ' '){
            switch_count++;
        }
        else if(single_space[i] == 'c' && single_space[i+1] == 'a' && single_space[i+2] == 's' && single_space[i+3] == 'e' && (single_space[i+4] == ' ' || single_space[i+4] == '\n')){
            case_count++;
        }
        else if(single_space[i] == '/' && single_space[i+1] == '/'){
            comment_count++;
            while(single_space[i] != '\n'){
                i++;
            }
        }
        else if(single_space[i] == '+' || single_space[i] == '-' || single_space[i] == '*' || single_space[i] == '/' || single_space[i] == '%' || single_space[i] == '>' || single_space[i] == '<' || single_space[i] == '=' || single_space[i] == '!' || (single_space[i] == '&' && single_space[i+1] == '&') || (single_space[i] == '|' && single_space[i+1] == '|')){
            operator_count++;
        }
        else if((single_space[i] >= 'a' && single_space[i] <= 'z') || (single_space[i] >= 'A' && single_space[i] <= 'Z')){
            variable_count++;
            while((single_space[i] >= 'a' && single_space[i] <= 'z') || (single_space[i] >= 'A' && single_space[i] <= 'Z') || (single_space[i] >= '0' && single_space[i] <= '9')){
                i++;
            }
        }
    }

    printf("\nParsing Summary:\n");
    printf("Curly braces: %d\n", curly_count);
    printf("Rounded brackets: %d\n", rounded_count);
    printf("Square brackets: %d\n", square_count);
    printf("If statements: %d\n", if_count);
    printf("For loops: %d\n", for_count);
    printf("While loops: %d\n", while_count);
    printf("Do-while loops: %d\n", do_count);
    printf("Switch statements: %d\n", switch_count);
    printf("Case statements: %d\n", case_count);
    printf("Comments: %d\n", comment_count);
    printf("Operators: %d\n", operator_count);
    printf("Variables: %d\n", variable_count);

    free(single_space);
    return 0;
}