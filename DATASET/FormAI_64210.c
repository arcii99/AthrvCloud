//FormAI DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Beautifier function
char* htmlBeautifier(const char* htmlStr) {
    char *beautyStr, *returnStr;
    int indentation = 0, length = strlen(htmlStr);
    beautyStr = (char*) malloc(length * sizeof(char)); //Creating a dynamic memory allocation of required size
    returnStr = beautyStr;

    for(int i = 0; i < length; i++) {
        char current = htmlStr[i];
        if(current == '<') {
            beautyStr[indentation] = current;
            beautyStr[++indentation] = '\n';
            for(int j = 0; j < indentation; j++) {
                beautyStr[++indentation] = '\t';
            }
        } else if(current == '>') {
            beautyStr[indentation] = current;
            beautyStr[++indentation] = '\n';
        } else {
            beautyStr[indentation] = current;
        }
        indentation++;
    }
    beautyStr[indentation] = '\0';
    return returnStr;
}

int main() {
    char htmlStr[1000];
    printf("Enter the HTML code:\n"); 
    fgets(htmlStr, 1000, stdin); // User input of HTML code
    char *beautyStr = htmlBeautifier(htmlStr); // Function call to beautify current HTML code
    printf("\nYour beautified HTML code is:\n");
    printf("%s", beautyStr);
    free(beautyStr); // Freeing the memory used by the beautified string
    return 0;
}