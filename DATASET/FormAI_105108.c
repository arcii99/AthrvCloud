//FormAI DATASET v1.0 Category: Data validation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool is_valid_integer(char* str){
    if(isdigit(str[0]) || str[0] == '-' || str[0] == '+') {
        for(int i = 1; i < strlen(str); i++) {
            if(!isdigit(str[i]))
                return false;
        }
        return true;
    }
    return false;
}

bool is_valid_float(char* str){
    int dot_count = 0;
    if(isdigit(str[0]) || str[0] == '-' || str[0] == '+'){
        for(int i = 1; i < strlen(str); i++){
            if(str[i] == '.'){
                dot_count++;
                if(dot_count > 1)
                    return false;
            }
            else if(!isdigit(str[i]))
                return false;
        }
        return true;
    }
    return false;
}

bool is_valid_email(char* str){
    bool at_symbol = false, period = false;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '@'){
            at_symbol = true;
        }
        if(str[i] == '.'){
            period = true;
        }
    }
    if(at_symbol && period){
        return true;
    }
    else{
        return false;
    }
}

bool is_valid_phone_number(char* str){
    if(strlen(str) != 10){
        return false;
    }
    for(int i = 0;i < strlen(str); i++){
        if(!isdigit(str[i])){
            return false;
        }
    }
    return true;
}

int main(){
    char input_str[100];
    printf("Enter an integer: ");
    fgets(input_str, 100, stdin);
    input_str[strcspn(input_str, "\n")] = '\0'; //Remove trailing newline character
    if(is_valid_integer(input_str)){
        printf("Valid integer!\n");
    }
    else{
        printf("Invalid integer!\n");
    }

    printf("Enter a float: ");
    fgets(input_str, 100, stdin);
    input_str[strcspn(input_str, "\n")] = '\0'; //Remove trailing newline character
    if(is_valid_float(input_str)){
        printf("Valid float!\n");
    }
    else{
        printf("Invalid float!\n");
    }

    printf("Enter an email address: ");
    fgets(input_str, 100, stdin);
    input_str[strcspn(input_str, "\n")] = '\0'; //Remove trailing newline character
    if(is_valid_email(input_str)){
        printf("Valid email address!\n");
    }
    else{
        printf("Invalid email address!\n");
    }

    printf("Enter a valid 10 digit phone number: ");
    fgets(input_str, 100, stdin);
    input_str[strcspn(input_str, "\n")] = '\0'; //Remove trailing newline character
    if(is_valid_phone_number(input_str)){
        printf("Valid phone number!\n");
    }
    else{
        printf("Invalid phone number!\n");
    }

    return 0;
}