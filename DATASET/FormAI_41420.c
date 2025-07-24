//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 100

int main(){
    
    char player1_input[MAX_LEN], player2_input[MAX_LEN];   
    int i, j, flag1, flag2, len1, len2;
    char *ptr;
    
    printf("*** Welcome to Sanitizer Game ***\n");
    printf("Player 1, please enter your input:\n");
    fgets(player1_input, MAX_LEN, stdin);
    
    printf("Player 2, please enter your input:\n");
    fgets(player2_input, MAX_LEN, stdin);
    
    // sanitizing player 1 input
    ptr = player1_input;
    len1 = strlen(player1_input);
    flag1 = 0;
    for(i = 0; i < len1; i++){
        if(*ptr >= '0' && *ptr <= '9'){
            ptr++;
            continue;
        } else if(*ptr >= 'a' && *ptr <= 'z'){
            ptr++;
            continue;
        } else if(*ptr >= 'A' && *ptr <= 'Z'){
            ptr++;
            continue;
        } else if(*ptr == ' '){
            ptr++;
            continue;
        } else{
            flag1 = 1;
            break;
        }
    }
    if(flag1 == 1){
        printf("Player 1, your input was not sanitized properly\n");
    } else{
        printf("Player 1, your input was sanitized perfectly\n");
    }
    
    // sanitizing player 2 input
    ptr = player2_input;
    len2 = strlen(player2_input);
    flag2 = 0;
    for(i = 0; i < len2; i++){
        if(*ptr >= '0' && *ptr <= '9'){
            ptr++;
            continue;
        } else if(*ptr >= 'a' && *ptr <= 'z'){
            ptr++;
            continue;
        } else if(*ptr >= 'A' && *ptr <= 'Z'){
            ptr++;
            continue;
        } else if(*ptr == ' '){
            ptr++;
            continue;
        } else{
            flag2 = 1;
            break;
        }
    }
    if(flag2 == 1){
        printf("Player 2, your input was not sanitized properly\n");
    } else{
        printf("Player 2, your input was sanitized perfectly\n");
    }

    return 0;
}