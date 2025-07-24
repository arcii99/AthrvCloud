//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: authentic
#include <stdio.h>
#include <string.h>

// Function to remove non-alphanumeric characters from the URL
void sanitize_url(char url[])
{
    int i, j;
    char temp[strlen(url)];
    
    // Loop through each character in the URL
    for(i = 0, j = 0; i < strlen(url); i++)
    {
        // If the character is alphanumeric, add it to the temp variable
        if((url[i] >= 'a' && url[i] <= 'z') || (url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= '0' && url[i] <= '9'))
        {
            temp[j++] = url[i];
        }
    }
    
    // Add a null character at the end of the temp variable to signify the end of the string
    temp[j] = '\0';
    
    // Copy the sanitized URL from the temp variable to the original URL variable
    strcpy(url, temp);
}

int main()
{
    char url[100];
    
    // Prompt the user to enter a URL
    printf("Enter a URL: ");
    scanf("%s", url);
    
    // Sanitize the URL
    sanitize_url(url);
    
    // Display the sanitized URL
    printf("Sanitized URL: %s", url);
    
    return 0;
}