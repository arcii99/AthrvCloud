//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Dennis Ritchie
/******************************************************************************
* PROGRAM: C URL Sanitizer
* AUTHOR: -------------------------------------
* 
* DESCRIPTION: 
* This program takes an input URL string from the user and sanitizes it if it
* contains any invalid characters after the domain name. It replaces invalid
* characters with their hexadecimal codes so that the URL becomes valid and
* can be used safely.
******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char url[1000], domain[1000], *invalid_chars = "!#%&*+-/=?^_`{|}~"; // list of invalid characters
    int i, j, k, invalid_char_found = 0;

    // input the URL from the user
    printf("Enter a URL: ");
    fgets(url, sizeof(url), stdin);

    // extract the domain name from the URL
    for (i = 0, j = 0; url[i] != '\0'; i++)
    {
        if (url[i] == ':' && url[i+1] == '/' && url[i+2] == '/')
            i += 3;
        if (url[i] == '/')
            break;
        domain[j++] = url[i];
    }
    domain[j] = '\0';

    // check for invalid characters after the domain name and replace them
    for (k = i; url[k] != '\0'; k++)
    {
        invalid_char_found = 0;
        for (j = 0; invalid_chars[j] != '\0'; j++)
        {
            if (url[k] == invalid_chars[j])
            {
                invalid_char_found = 1;
                break;
            }
        }
        if (invalid_char_found)
        {
            // replace invalid character with its hexadecimal code
            char hex[3];
            sprintf(hex, "%02X", url[k]);
            memmove(&url[k+2], &url[k+1], strlen(&url[k+1])+1);
            url[k] = '%';
            url[k+1] = hex[0];
            url[k+2] = hex[1];
            k += 2;
        }
    }

    // output the sanitized URL
    printf("Sanitized URL: %s", url);

    return 0;
}