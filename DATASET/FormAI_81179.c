//FormAI DATASET v1.0 Category: Syntax parsing ; Style: beginner-friendly
#include<stdio.h>
#include<string.h>

int main(){
    char input[100];
    int i,len;
    printf("Enter a C Syntax code snippet:\n");
    gets(input);
    len=strlen(input);
    int flag=0;

    for(i=0;i<len;i++){
        if(input[i]=='{')
            flag++;
        else if(input[i]=='}')
            flag--;
    }

    if(flag==0)
        printf("Syntax is correct!\n");
    else
        printf("Syntax is incorrect!\n");

    return 0;
}