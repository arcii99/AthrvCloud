//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * This program takes a URL in the form of a string
 * and sanitize it by making sure it is a valid URL
 * and removing any malicious characters that can cause
 * security issues.
 */

// function prototypes
bool is_valid_url(char* url);
char* sanitize_url(char* url);

int main()
{
    char url[100];

    // get input from user
    printf("Enter a URL to sanitize: ");
    fgets(url, sizeof(url), stdin);

    // remove newline character from input
    url[strcspn(url, "\n")] = '\0';

    // check if URL is valid
    if(!is_valid_url(url))
    {
        printf("Invalid URL.\n");
        exit(1);
    }

    // sanitize URL
    char* sanitized_url = sanitize_url(url);

    // print sanitized URL
    printf("Sanitized URL: %s\n", sanitized_url);

    // free dynamically allocated memory
    free(sanitized_url);

    return 0;
}

/**
 * Check if URL is valid
 * @param url pointer to string representing a URL
 * @return true if URL is valid, false otherwise
 */
bool is_valid_url(char* url)
{
    // check that URL starts with 'http://' or 'https://'
    if(strncmp(url, "http://", 7) != 0 && strncmp(url, "https://", 8) != 0)
        return false;

    // check that URL is less than 100 characters
    if(strlen(url) > 99)
        return false;

    // check that URL contains only alphanumeric characters, underscores, and periods
    for(int i = 0; i < strlen(url); i++)
        if(!(url[i] >= 'a' && url[i] <= 'z') &&
           !(url[i] >= 'A' && url[i] <= 'Z') &&
           !(url[i] >= '0' && url[i] <= '9') &&
           url[i] != '.' && url[i] != '_')
            return false;

    return true;
}

/**
 * Sanitize URL by removing any malicious characters 
 * @param url pointer to string representing a URL
 * @return pointer to string containing sanitized URL
 */
char* sanitize_url(char* url)
{
    // allocate memory for sanitized URL
    char* sanitized_url = (char*)malloc(sizeof(char) * (strlen(url) + 1));
    int j = 0; // index for sanitized_url

    // iterate through original URL and copy only valid characters to sanitized URL
    for(int i = 0; i < strlen(url); i++)
    {
        if((url[i] >= 'a' && url[i] <= 'z') ||
           (url[i] >= 'A' && url[i] <= 'Z') ||
           (url[i] >= '0' && url[i] <= '9') ||
           url[i] == '.' || url[i] == '_')
        {
            sanitized_url[j] = url[i];
            j++;
        }
    }

    sanitized_url[j] = '\0'; // add null terminator to end of sanitized URL

    return sanitized_url;
}