//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: ephemeral
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char input[100], sanitized[100];
    int i,j;

    printf("Enter a string: ");
    fgets(input, 100, stdin);

    for(i=0, j=0; i<strlen(input); ++i){
        if(input[i]>='a' && input[i]<='z'){
            sanitized[j++] = input[i];  //retain lowercase letters
        }
        else if(input[i]>='A' && input[i]<='Z'){
            sanitized[j++] = input[i] + 32; //convert uppercase to lowercase and retain
        }
    }
    sanitized[j] = '\0';

    printf("\nSanitized Input: %s\n", sanitized);

    return 0;
}