//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: futuristic
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void sanitizeInput(char *inputString, int length){
    for(int i=0;i<length;i++){
        if(!isalnum(inputString[i])){
            inputString[i]=' ';
        }
    }
}

int main(){
    char input[100];
    printf("Enter your input: ");
    fgets(input,100,stdin);
    int len=strlen(input);
    sanitizeInput(input,len);
    printf("Sanitized input: %s",input);
    return 0;
}