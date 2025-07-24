//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Alan Touring
// Alan Turing-style unique C URL Sanitizer example

#include <stdio.h>
#include <string.h>

int main() {

    // Define input URL and maximum length
    char input_url[1000];
    int max_length = 1000;

    // Get input URL from user
    printf("Please enter a URL: ");
    fgets(input_url, max_length, stdin);

    // Define output URL array and length
    char output_url[1000];
    int url_length = 0;

    // Remove white space from input URL
    for (int i = 0; i < strlen(input_url); i++) {
        if (input_url[i] != ' ') {
            output_url[url_length] = input_url[i];
            url_length++;
        }
    }

    // Check if output URL starts with "http://" or "https://"
    if (strncmp(output_url, "http://", 7) != 0 && strncmp(output_url, "https://", 8) != 0) {
        // Add "http://" to output URL if it does not start with it
        char temp_url[1000] = "http://";
        strcat(temp_url, output_url);
        strcpy(output_url, temp_url);
    }

    // Check for and remove any trailing '/'
    if (output_url[url_length-1] == '/') {
        output_url[url_length-1] = '\0';
        url_length--;
    }

    // Print output URL
    printf("Sanitized URL: %s\n", output_url);
    
    return 0;
}