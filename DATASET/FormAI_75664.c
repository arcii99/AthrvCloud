//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: peaceful
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

// This program is a C URL sanitizer that removes illegal characters from a URL.

int main() {

    char url[200]; // The maximum URL length that can be entered is 200 characters.

    printf("Enter the URL to sanitize: ");
    scanf("%[^\n]s", url); // Accepts the input URL that includes spaces.

    int length = strlen(url);
    int index = 0;
    char sanitizedURL[200]; // The sanitized URL will be stored here.

    // Loop through each character in the entered URL to check for illegal characters.
    while(index < length) {
        
        if(isalnum(url[index]) || url[index] == '.' || url[index] == '/' || url[index] == ':' || url[index] == '-' || url[index] == '_') {
            sanitizedURL[index] = url[index]; // If the character is legal, add it to the new sanitized URL.
        }
        else if(url[index] == ' ') {
            sanitizedURL[index] = '+'; // If the character is a space, replace it with a '+'.
        }
        else {
            char temp[3]; // If the character is illegal, convert it to its hex value and add it to the new sanitized URL.
            sprintf(temp, "%X", url[index]);
            sanitizedURL[strlen(sanitizedURL)] = '%';
            sanitizedURL[strlen(sanitizedURL)] = temp[0];
            sanitizedURL[strlen(sanitizedURL)] = temp[1];
        }

        index++;
    }

    printf("\nSanitized URL: %s\n", sanitizedURL);

    return 0;
}