//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all non-alphanumeric characters from a string
void sanitize_url(char *url) {
    int i, j = 0;
    char sanitized_url[strlen(url) + 1]; // create a new empty string to store sanitized URL

    // loop through each character of the original URL
    for (i = 0; i < strlen(url); i++) {
        // if the character is alphanumeric, add it to the sanitized URL
        if ((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9')) {
            sanitized_url[j] = url[i];
            j++;
        }
    }

    sanitized_url[j] = '\0'; // add null character to the end of the sanitized URL

    // copy the sanitized URL back into the original URL variable
    strcpy(url, sanitized_url);
}

int main() {
    char input_url[200]; // create a string to hold the user's input URL

    printf("My love, please give me the URL you want to sanitize:\n");
    scanf("%s", input_url); // get the user's input

    sanitize_url(input_url); // remove all non-alphanumeric characters from the URL

    printf("Here is your sanitized URL, my dear:\n");
    printf("%s\n", input_url); // display the sanitized URL to the user

    return 0; // return from the main function
}