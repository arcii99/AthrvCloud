//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSpaces(int n) {
    for(int i=0;i<n;i++)
        printf(" ");
}

int main() {
    char input[50000], output[50000];
    int outputIndex=0,depth=0;
    
    printf("Enter the HTML code and press enter:\n");
    fgets(input, 50000, stdin);
    
    int n = strlen(input);
    for(int i=0;i<n;i++) {
        if(input[i]=='<') {
            output[outputIndex++]='\n';
            printSpaces(depth);
            depth+=4;
        }
        
        output[outputIndex++]=input[i];
        
        if(input[i]=='>') {
            depth-=4;
            if(i<n-1 && input[i+1]!='<') {
                output[outputIndex++]='\n';
                printSpaces(depth);
            }
        }
    }
    
    printf("\n\nBeautified HTML Code:\n\n%s\n", output);    
    return 0;
}