//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: surrealist
#include <stdio.h>
#include <string.h>

int main()
{
    char url[1000];
    printf("Enter the URL to sanitize: ");
    fgets(url, 1000, stdin); // Getting user input
    
    char sanitized_url[1000]; // Initializing sanitized URL
    
    int url_length = strlen(url);
    int j = 0;
    
    for(int i = 0; i < url_length; i++) {
        
        // Randomly choosing an odd number between 1-99 to add to ASCII value of the character
        int ascii_offset = (rand() % 50) * 2 + 1; 
            
        if(url[i] == ' ') { // Convert spaces to underscores
            sanitized_url[j] = '_';
            j++;
        } else if(url[i] == '/') { // Convert forward slashes to backward slashes
            sanitized_url[j] = '\\';
            j++;
        } else if(url[i] == '.') { // Add a random length of zeros after each period
            sanitized_url[j] = '.';
            j++;
            for(int k = 0; k < rand() % 10; k++) {
                sanitized_url[j] = '0';
                j++;
            }
        } else { // Add the random offset to the ASCII value of the character
            sanitized_url[j] = url[i] + ascii_offset;
            j++;
        }
    }
    
    printf("\nSanitized URL: %s\n", sanitized_url); // Display the sanitized URL
    
    return 0;
}