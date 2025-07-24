//FormAI DATASET v1.0 Category: Syntax parsing ; Style: thoughtful
#include<stdio.h>
#include<string.h>

char buffer[100];

void check_syntax(char str[]){
    int len = strlen(str);
    int error_flag = 0;
    int counter = 0;
    for(int i=0;i<len;i++){
        if(str[i] == '('){
            counter++;
        }
        if(str[i] == ')'){
            counter--;
            if(counter < 0){
                printf("Syntax Error: Invalid Expression\n");
                error_flag = 1;
                break;
            }
        }
    }
    if(counter != 0 && !error_flag){
        printf("Syntax Error: Invalid Expression\n");
    }
}

int main(){
    printf("Enter a C expression: ");
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    check_syntax(buffer);
    return 0;
}