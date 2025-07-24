//FormAI DATASET v1.0 Category: String manipulation ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* removeChar(char* str, char c){
    int i,j=0;
    for(i=0; i<strlen(str); i++){
        if(str[i]!=c)
            str[j++]=str[i];
    }
    str[j]='\0';
    return str;
}

int main(){
    char input[100], c;
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    printf("Enter the character to remove from the string: ");
    scanf("%c", &c);

    char* output = removeChar(input, c);
    printf("New string after removing %c: %s\n", c, output);

    return 0;
}