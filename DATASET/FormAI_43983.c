//FormAI DATASET v1.0 Category: HTML beautifier ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_LENGTH 10000

// A function to beautify the C HTML code
void beautify(char *code){
    int i=0, j=0, indent=0, n=strlen(code);
    char prevc=' ';
    char *temp=(char*)malloc(MAX_LENGTH*sizeof(char));
    while(i<n){
        if(code[i]=='}') indent--;
        if(prevc=='\n'){
            for(int k=0;k<indent;k++){
                strcat(temp, "    ");
                j+=4;
            }
        }
        if(code[i]=='{') indent++;
        temp[j]=code[i];
        j++;
        if(code[i]=='>' && code[i+1]!='<'){
            temp[j]='\n';
            j++;
        }
        prevc=code[i];
        i++;
    }
    temp[j]='\0';
    strcpy(code, temp);
    free(temp);
}

int main(){
    char code[MAX_LENGTH];
    printf("Enter the C HTML code: \n");
    fgets(code, MAX_LENGTH, stdin);
    beautify(code);
    printf("\n************* The beautified code is: *************\n\n");
    printf("%s\n", code);
    printf("\n***************************************************\n");
    return 0;
}