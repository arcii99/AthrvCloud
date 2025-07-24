//FormAI DATASET v1.0 Category: Syntax parsing ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char input[1000];          //Declare the string 'input'
    int i, j, temp=0, flag=0;  //Declare some variables
    printf("Enter the code snippet: ");
    fgets(input, 1000, stdin); //Read input

    for(i=0; i<strlen(input); i++){        //Parse through the input string
        if(input[i]=='/')               //Check if it's a comment
            if(input[i+1]=='/')               //If it's single-line, ignore rest of the line
                break;
            else if(input[i+1]=='*'){       //If it's multi-line, ignore till it ends
                flag=1;
                temp=i+2;
            }  
        if(flag==1 && input[i]=='*' && input[i+1]=='/'){  //If multi-line comment ends
            flag=0;
            i+=1;
        }
        if(flag==0 && input[i]=='{')        //Print opening parenthesis of block
            printf("%c\n", input[i]);
        if(flag==0 && input[i]=='}')        //Print closing parenthesis of block
            printf("\n%c", input[i]);
        if(flag==0 && input[i]==';'){   //Print semicolon at end of line
            for(j=temp; j<i; j++)       //Print the line between semicolon and previous comment
                printf("%c", input[j]);
            printf(";\n");
            temp=i+1;
        }
    }
    return 0;
}