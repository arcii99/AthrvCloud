//FormAI DATASET v1.0 Category: HTML beautifier ; Style: immersive
#include<stdio.h>
#include<string.h>

int main() {
    printf("Welcome to HTML Beautifier!\n");
    printf("Please enter your HTML code:\n");
    
    char code[1000], indent[20]="\t";
    int i,j,indentLevel=0;

    while (fgets(code, sizeof(code), stdin)) {
        // Remove leading and trailing whitespace
        for(i=0;isspace(code[i]);i++);
        for(j=strlen(code)-1;isspace(code[j]);j--);
        code[j+1]='\0';
        strcpy(code, &code[i]);

        if (strstr(code, "</")) {
            indentLevel--;
        }

        for(i=0;i<indentLevel;i++) {
            printf("%s",indent);
        }

        printf("%s\n",code);

        if (strstr(code, "<")) {
            indentLevel++;
        }
    }

    return 0;
}