//FormAI DATASET v1.0 Category: HTML beautifier ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char* inputHTML, char* outputHTML);

int main()
{
    char originalHTML[500];
    char beautifiedHTML[500];
    
    printf("Please enter the unformatted HTML:\n");
    fgets(originalHTML, 500, stdin); //take user input
    
    beautifyHTML(originalHTML, beautifiedHTML); //call the function
    
    printf("\nHere is the beautified HTML:\n%s", beautifiedHTML);
    
    return 0;
}

void beautifyHTML(char* inputHTML, char* outputHTML)
{
    char* tagStart = "<";
    char* tagEnd = ">";
    char* space = " ";
    char* slash = "/";
    
    int i;
    int indentLevel = 0;
    
    int len = strlen(inputHTML);
    
    for(i = 0; i < len; i++)
    {
        //if opening tag is detected, add newline and indent
        if(inputHTML[i] == *tagStart && inputHTML[i+1] != *slash)
        {
            outputHTML[i] = inputHTML[i];
            outputHTML[i+1] = '\n';
            
            int j;
            for(j = 0; j < indentLevel; j++)
            {
                strcat(outputHTML, space);
            }
            indentLevel++;
        }
        //if closing tag is detected, add newline and decrease indent
        else if(inputHTML[i] == *tagStart && inputHTML[i+1] == *slash)
        {
            indentLevel--;
            
            outputHTML[i] = '\n';
            int j;
            for(j = 0; j < indentLevel; j++)
            {
                strcat(outputHTML, space);
            }
            strcat(outputHTML, tagStart);
        }
        //add regular characters to the output
        else
        {
            outputHTML[i] = inputHTML[i];
        }
    }
}