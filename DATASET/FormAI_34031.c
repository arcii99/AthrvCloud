//FormAI DATASET v1.0 Category: Syntax parsing ; Style: mind-bending
#include<stdio.h>
#include<string.h>

int main(){
    char code_snippet[1000];
    int count=0, flag=0;
    printf("Enter your unique C syntax parsing code snippet in a mind-bending style:\n");
    scanf("%[^\n]", code_snippet);
    for(int i=0;i<strlen(code_snippet);i++){
        if(code_snippet[i]=='{'){
            count++;
        }
        else if(code_snippet[i]=='}'){
            count--;
            if(count<0){
                printf("Syntax Error: Extra Closing brace.\n");
                flag=1;
                break;
            }
        }
    }
    if(count>0 && flag==0){
        printf("Syntax Error: Missing closing brace.\n");
        flag=1;
    }
    else if(count==0 && flag==0){
        printf("Syntax is correct. Parsing completed successfully.\n");
    }
    return 0;
}