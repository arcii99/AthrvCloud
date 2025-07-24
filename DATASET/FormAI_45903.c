//FormAI DATASET v1.0 Category: Syntax parsing ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to check if a string is a number or not
int isNumber(char* str) {
    int i;
    for(i=0; i<strlen(str); i++) {
        if(str[i]<'0' || str[i]>'9') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char input[1000];
    int i=0, j=0, flag=0, num_count=0, op_count=0;
    printf("Enter a valid C expression: ");
    fgets(input, 1000, stdin);
    //Removing extra spaces from input string
    for(i=0; input[i]!='\0'; i++) {
        if(input[i] != ' ') {
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0';
    i = 0;
    //Parsing each character of the input string
    while(input[i]!='\0') {
        if(input[i]>='0' && input[i]<='9') { //If current character is a digit
            if(flag==1) { //If previous character was an operator
                op_count++;
                flag=0;
            }
            num_count++;
            while(input[i]>='0' && input[i]<='9') { //Checking for multi-digit numbers
                i++;
            }
        }
        else if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/') { //If current character is an operator
            if(flag==0) { //If previous character was a number
                num_count++;
                flag=1;
            }
            op_count++;
            i++;
        }
        else { //If current character is neither a number nor an operator
            printf("Invalid Input!\n");
            exit(0);
        }
    }
    if(num_count-op_count!=1) { //Checking expression validity
        printf("Invalid Expression!\n");
        exit(0);
    }
    printf("Valid Expression!\n");
    return 0;
}