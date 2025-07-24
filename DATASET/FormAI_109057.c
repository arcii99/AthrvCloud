//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char html[1000];
    printf("Oh, HTML fair, what wilt thy beauty be?\n");
    fgets(html, 1000, stdin);
    
    int indent_level = 0;
    char* token = strtok(html, "<>");
    while (token != NULL)
    {
        if (token[0] == '/')
        {
            indent_level--;
        }
        
        for (int i = 0; i < indent_level; i++)
        {
            printf("  ");
        }
        
        printf("<%s>\n", token);
        
        if (token[0] != '/' && token[strlen(token) - 1] != '/')
        {
            indent_level++;
        }
        
        token = strtok(NULL, "<>");
        
        if (token != NULL && token[0] == '/')
        {
            indent_level--;
        }
    }
    
    return 0;
}