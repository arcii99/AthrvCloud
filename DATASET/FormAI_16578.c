//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
#include<stdio.h>
#include<string.h>

void removeWhitespace(char *str){
    int i = 0, j = 0;
    while(str[i] != '\0'){
        if(str[i] != ' ' && str[i] != '\t' && str[i] != '\n'){
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

int main(){
    char s1[100], s2[100];
    printf("Enter the first string: ");
    fgets(s1, sizeof(s1), stdin);
    printf("Enter the second string: ");
    fgets(s2, sizeof(s2), stdin);

    removeWhitespace(s1);
    removeWhitespace(s2);

    if(strcmp(s1, s2) == 0){
        printf("The two strings are equal.");
    }else{
        printf("The two strings are not equal.");
    }
    return 0;
}