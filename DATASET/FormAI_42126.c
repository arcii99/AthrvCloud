//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char input_string[100];
    char sanitized_string[100];
    int i, j;
    printf("Enter a string to sanitize:\n");
    fgets(input_string, sizeof(input_string), stdin);
    if (strlen(input_string) > 0 && input_string[strlen(input_string)-1] == '\n')
        input_string[strlen(input_string)-1] = '\0';
    for(i=0, j=0; i<strlen(input_string); i++){
        if(input_string[i]>='a' && input_string[i]<='z')
            sanitized_string[j++]=input_string[i];
        else if(input_string[i]>='A' && input_string[i]<='Z')
            sanitized_string[j++]=input_string[i];
        else if(input_string[i]>='0' && input_string[i]<='9')
            sanitized_string[j++]=input_string[i];
        else if(input_string[i]==' ' || input_string[i]=='\t')
            sanitized_string[j++]=' ';
        else{
            sanitized_string[j++]='\\';
            sanitized_string[j++]=input_string[i];
        }
    }
    sanitized_string[j]='\0';
    printf("Sanitized string is: %s\n", sanitized_string);
    return 0;
}