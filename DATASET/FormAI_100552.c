//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sanitize(char* str){
    int i = 0; // index to iterate the given string
    int j = 0; // index to select the characters that are safe
    while(str[i]) {
        if((str[i]>='A' && str[i]<='Z')||(str[i]>='a' && str[i]<='z')||(str[i]>='0' && str[i]<='9')) {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j]='\0';
}

int main() {
    char str[100];
    printf("Enter the text to sanitize: ");
    fgets(str, 100, stdin);
    
    sanitize(str);
    
    printf("The sanitized text is: %s", str);
    return 0;
}