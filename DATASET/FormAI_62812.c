//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: enthusiastic
// Welcome to the C URL Sanitizer!
// This program takes a potentially unsafe URL input from the user
// and checks for any malicious code or script injections.
// If found, it removes them and outputs a safe URL for the user to use.
// Let's get started:

#include <stdio.h>
#include <string.h>

int main(void) {

    // Define the variables we will need
    char url[1000], new_url[1000];
    int i,j;

    // Get the URL input from the user
    printf("Enter a URL: \n");
    scanf("%s", url);

    // Start checking for potentially harmful scripts or code
    for (i = 0, j = 0; i<strlen(url); i++, j++) {
        // If the current character is a <, check the next characters for a script or code
        if (url[i] == '<') {
            if (url[i+1] == 's' && url[i+2] == 'c' && url[i+3] == 'r' && url[i+4] == 'i' && url[i+5] == 'p' && url[i+6] == 't') {
                i += 6;
                continue;
            }
            else if (url[i+1] == 'i' && url[i+2] == 'm' && url[i+3] == 'g' && url[i+4] == ' ') {
                i += 4;
                continue;
            }
        }

        // Copy the safe characters to the new URL string
        new_url[j] = url[i];
    }

    // Add a null terminator to the end of the new URL string
    new_url[j] = '\0';

    // Print the safe URL for the user to use
    printf("Here is your safe URL: %s\n", new_url);

    return 0;
}