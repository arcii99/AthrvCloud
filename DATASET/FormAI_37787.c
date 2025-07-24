//FormAI DATASET v1.0 Category: Syntax parsing ; Style: excited
#include<stdio.h>

int main(){
    printf("Hey there! I'm your C Syntax parser :) \n");
    printf("I can't wait to show off my skills to you! \n");
    printf("Enter the C syntax you'd like me to parse: \n");

    char input[200];
    fgets(input, 200, stdin);
    printf("Enter '0' to exit program. \n\n");
    while(strcmp("0\n", input)){
        char* code = input;
        char* ptr;
        ptr = strtok(input, "();, ");
        while(ptr != NULL){
            for(int i=0; i<strlen(ptr); i++){
                if(ptr[i]=='{'){
                    printf("\nOpening Curly Brace. \n");
                }
                else if(ptr[i]=='}'){
                    printf("\nClosing Curly Brace. \n");
                }
                else if(ptr[i]=='('){
                    printf("\nOpening Parenthesis. \n");
                }
                else if(ptr[i]==')'){
                    printf("\nClosing Parenthesis. \n");
                }
                else if(ptr[i]==';'){
                    printf("\nSemi-colon. \n");
                }
                else{
                    printf("%c", ptr[i]);
                }
            }
            printf(" ");
            ptr = strtok(NULL, "();, ");
        }
        printf("\n");
        fgets(input, 200, stdin);
        printf("Enter '0' to exit program. \n\n");
    }
    printf("Thanks for using my services! \n");
    return 0;
}