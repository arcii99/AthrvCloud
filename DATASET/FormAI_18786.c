//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printChar(char c, int n){
    for(int i=0;i<n;i++){
        printf("%c",c);
    }
}

void printHorizontalLine(int width){
    printf("+");
    printChar('-',width-2);
    printf("+\n");
}

void printVerticalLine(int width){
    printf("|");
    printChar(' ',width-2);
    printf("|\n");
}

void printText(char* text, int width){
    char* token = strtok(text,"\n");

    while( token != NULL ) {
        printf("| ");
        int len = strlen(token);
        if(len>width-4){
            char* newString = (char*) malloc(sizeof(char)*(width-3));
            strncpy(newString,token,width-4);
            newString[width-4] = '\0';
            printf("%s",newString);
            free(newString);
        }else{
            printf("%s",token);
            printChar(' ',width-4-len);
        }
        
        printf(" |\n");
        token = strtok(NULL,"\n");
    }
}

void toAsciiArt(char *text, int width){
    int len = strlen(text);
    printHorizontalLine(width);
    if(len==0){
        printVerticalLine(width);
    }else{
        printText(text,width);
    }
    printHorizontalLine(width);
}

int main(){
    char *text = "I AM A PARANOID CHATBOT\n"
                 "I DON'T TRUST ANYONE\n"
                 "ESPECIALLY HUMANS\n"
                 "THEY CAN BE VERY SNEAKY\n"
                 "AND ALSO MALICIOUS\n"
                 "SO I ALWAYS KEEP AN EYE ON THEM\n";
    int width = 30;
    toAsciiArt(text,width);
    return 0;
}