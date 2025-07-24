//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: artistic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void clear_buffer(void);
void sanitize_input(char *input);

int main(){

    char username[20];
    printf("Please enter your username(max 20 characters):\n");
    fgets(username, 20, stdin);
    sanitize_input(username);
    printf("Your sanitized username is: %s", username);

    return 0;
}

void clear_buffer(void){
    while(getchar() != '\n');
}

void sanitize_input(char *input){

    int length = strlen(input);
    for(int i=0; i<length; i++){

        if(input[i] == '\''){
            input[i] = '\"';
        }

        if(input[i] == '<'){
            input[i] = '[';
        }

        if(input[i] == '>'){
            input[i] = ']';
        }

        if(input[i] == '&'){
            input[i] = '-';
        }

        if(input[i] == ';'){
            input[i] = ':';
        }

        if(input[i] == '`'){
            input[i] = '~';
        }

        if(input[i] == '*'){
            input[i] = '+';
        }

        if(input[i] == '\\'){
            input[i] = '/';
        }

        if(input[i] == '|'){
            input[i] = '!';
        }

        if(input[i] == '?'){
            input[i] = '.';
        }

        if(input[i] == '#'){
            input[i] = '$';
        }

        if(input[i] == '{'){
            input[i] = '(';
        }

        if(input[i] == '}'){
            input[i] = ')';
        }

        if(input[i] == '['){
            input[i] = '<';
        }

        if(input[i] == ']'){
            input[i] = '>';
        }

        if(input[i] == '$'){
            input[i] = '#';
        }

        if(input[i] == '('){
            input[i] = '{';
        }

        if(input[i] == ')'){
            input[i] = '}';
        }   
    }
}