//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: safe
#include <stdio.h>
#include <string.h>

int main() {
    // Define input and output strings
    char input[1000], output[1000];
    
    // Get user input
    printf("Enter URL: ");
    fgets(input, sizeof(input), stdin);
    
    // Calculate length of input string
    int length = strlen(input);
    
    // Loop through each character of input string
    for(int i=0; i<length; i++) {
        // If character is a space, replace with '%20'
        if(input[i] == ' ') {
            strcat(output, "%20");
        }
        // If character is an alphabetic or numeric character, add to output string
        else if((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9')) {
            char temp[2] = {input[i], '\0'};
            strcat(output, temp);
        }
        // If character is a valid URL character, add to output string
        else if (input[i] == ':' || input[i] == '/' || input[i] == '.' || input[i] == '-' || input[i] == '_' || input[i] == '~' || input[i] == '?' || input[i] == '=' || input[i] == '&') {
            char temp[2] = {input[i], '\0'};
            strcat(output, temp);
        }
        // Ignore all other characters
    }
    printf("Sanitized URL: %s", output);
    
    return 0;
}