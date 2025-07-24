//FormAI DATASET v1.0 Category: Text processing ; Style: bold
#include<stdio.h>
#include<string.h>

void printBold(char* str){
    printf("\033[1m%s\033[0m", str);   //using ANSI escape codes to print in bold font
}

int main(){
    char input[100];
    printf("\nEnter some text to print in bold: ");
    scanf("%[^\n]", input);     //using %[^n] to read till end of line including spaces

    char* token = strtok(input, " ");    //using strtok to split input string by space
    while(token != NULL){
        printBold(token);   //calling function to print each token in bold font
        printf(" ");   //adding space after each token
        token = strtok(NULL, " ");
    }
    return 0;
}