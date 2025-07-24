//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: energetic
#include<stdio.h>
#include<string.h>

int main()
{
    char url[100];
    int i,j=0;
    char clean_url[100];

    printf("Enter the URL to sanitize: ");
    scanf("%s", url);

    for(i=0; i<strlen(url); i++)
    {
        if(url[i] != '<' && url[i] != '>' && url[i] != '"' && url[i] != '\'' && url[i] != '(' && url[i] != ')' && url[i] != '{' && url[i] != '}' && url[i] != '[' && url[i] != ']' && url[i] != '\\' && url[i] != '|' && url[i] != '^' && url[i] != ';' && url[i] != ',' && url[i] != '?' && url[i] != ':' && url[i] != '@' && url[i] != '=' && url[i] != '&' && url[i] != '+' && url[i] != '*' && url[i] != '%' && url[i] != '#' && url[i] != '!')
        {
            clean_url[j++] = url[i];
        }
    }
    clean_url[j] = '\0';

    printf("Sanitized URL: %s", clean_url);

    return 0;
}