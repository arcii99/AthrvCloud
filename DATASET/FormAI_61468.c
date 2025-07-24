//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <string.h>

#define URL_MAX_LENGTH 1000 // max URL length

// main function to sanitize a URL string in C
void sanitizeUrl(char *url)
{
    int i, j, n;
    char temp[URL_MAX_LENGTH];
    n = strlen(url); // find length of the URL string
    
    // check for valid URL characters
    for(i=0, j=0; i<n; i++)
    {
        if(url[i]==' ' || url[i]=='<' || url[i]=='>' || url[i]=='#' || url[i]=='%' 
           || url[i]=='{' || url[i]=='}' || url[i]=='|' || url[i]=='\\' || url[i]=='^' 
           || url[i]=='~' || url[i]=='[' || url[i]==']' || url[i]=='`') // invalid characters
        {
           continue; // skip the invalid character 
        }
        else if(url[i]=='/') // check if the current character is a forward slash
        {
           if(i+1<n && url[i+1]=='/') // check if the next character is also a forward slash
           {
               continue; // skip the double forward slash
           }
           else
           {
               temp[j++] = url[i]; // copy the forward slash to the sanitized URL string
           }
        }
        else 
        {
           temp[j++] = url[i]; // copy the valid character to the sanitized URL string
        }
    }
    temp[j] = '\0'; // set the null character to mark end of the sanitized URL string
    strcpy(url, temp); // copy the sanitized URL string back to the original URL string
}

int main()
{
    char url[URL_MAX_LENGTH];
    
    // take input URL from the user
    printf("Enter URL to sanitize:\n");
    fgets(url, URL_MAX_LENGTH, stdin);
    
    // sanitize the URL
    sanitizeUrl(url);
    
    // print the sanitized URL
    printf("\nSanitized URL:\n%s\n", url);
    
    return 0;
}