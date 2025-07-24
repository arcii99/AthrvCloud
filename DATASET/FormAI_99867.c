//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: multivariable
/*
  This program takes a URL as input and removes any malicious or unnecessary characters from it using a multivariable style.
  Author: Chatbot
*/

#include <stdio.h>
#include <string.h>

// Function to sanitize the URL
void sanitizeURL(char* url)
{
    // Initialize the validity flag to true
    int isValid = 1;

    // Remove any leading and trailing spaces from the URL
    int i = 0, j = strlen(url) - 1;
    while (url[i] == ' ') i++;
    while (url[j] == ' ') j--;
    url[j + 1] = '\0';
    strncpy(url, url + i, j - i + 1);

    // Remove any 'javascript:' or 'data:' protocol from the URL
    char* substr = strstr(url, ":");
    if (substr != NULL && (strncmp(substr, ":javascript", 11) == 0 || strncmp(substr, ":data", 5) == 0 ))
    {
        substr = strstr(substr, " ");
        if (substr != NULL)
        {
            strncpy(url, substr, strlen(substr) + 1);
        }
        else
        {
            url[0] = '\0';
            isValid = 0;
        }
    }

    // Replace any '\' character with '/'
    char* c = strchr(url, '\\');
    while (c != NULL)
    {
        *c = '/';
        c = strchr(url, '\\');
    }

    // Remove any '#' character and everything after it
    char* hash = strchr(url, '#');
    if (hash != NULL) *hash = '\0';

    // Remove any '?' character and everything after it
    char* query = strchr(url, '?');
    if (query != NULL) *query = '\0';

    // Remove any whitespace from the URL
    i = 0;
    while (url[i] != '\0')
    {
        if (url[i] == '\t' || url[i] == '\r' || url[i] == '\n')
        {
            for (j = i; url[j] != '\0'; j++)
            {
                url[j] = url[j+1];
            }
        }
        else
        {
            i++;
        }
    }

    // Remove any '..' and '.' sequences
    char* token = strtok(url, "/");
    int numTokens = 0, offset = 0;
    while (token != NULL)
    {
        if (strcmp(token, "..") == 0)
        {
            offset--;
            if (offset < 0) isValid = 0;
        }
        else if (strcmp(token, ".") != 0)
        {
            url[numTokens++] = '/';
            strncpy(url + numTokens, token, strlen(token));
            numTokens += strlen(token);
            offset++;
        }
        token = strtok(NULL, "/");
    }
    url[numTokens] = '\0';

    // Print the sanitized URL
    if (isValid)
    {
        printf("Sanitized URL: %s\n", url);
    }
    else
    {
        printf("Invalid URL\n");
    }
}

// Main function to test the URL sanitizer
int main()
{
    // Test Case 1: With malicious script protocol
    char url1[] = "   javascript:alert('hello world');  ";
    printf("Original URL: %s\n", url1);
    sanitizeURL(url1);

    // Test Case 2: With invalid '..' sequence
    char url2[] = "   http://example.com/../../  ";
    printf("Original URL: %s\n", url2);
    sanitizeURL(url2);

    // Test Case 3: With unnecessary characters
    char url3[] = "   https://example.com/path/to/file.html?query=123#section   ";
    printf("Original URL: %s\n", url3);
    sanitizeURL(url3);

    return 0;
}