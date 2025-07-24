//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: intelligent
#include <stdio.h>
#include <string.h>

#define MAX_URL_LENGTH 200

// This function removes any leading or trailing whitespace characters from a string
void trim(char* str) {

    int left = 0;
    int right = strlen(str) - 1;

    while (left <= right && (str[left] == ' ' || str[left] == '\t' || str[left] == '\n')) {
        left++;
    }

    while (right >= left && (str[right] == ' ' || str[right] == '\t' || str[right] == '\n')) {
        right--;
    }

    for (int i = left; i <= right; i++) {
        str[i - left] = str[i];
    }

    str[right - left + 1] = '\0';
}

// This function takes in a string representing a URL and returns a "sanitized" version of it
char* sanitize_url(char* url) {

    // Remove any leading or trailing whitespace characters
    trim(url);

    // Create a new string to hold the sanitized version of the URL
    char* sanitized = malloc(sizeof(char) * MAX_URL_LENGTH);
    sanitized[0] = '\0';

    // Loop through each character in the URL
    for (int i = 0; i < strlen(url); i++) {

        // If the character is a whitespace character, skip it
        if (url[i] == ' ' || url[i] == '\t' || url[i] == '\n') {
            continue;
        }

        // If the character is not an alphanumeric character or a period or a slash, skip it
        if (!isalnum(url[i]) && url[i] != '.' && url[i] != '/') {
            continue;
        }

        // If the character is a period or a slash, add it to the sanitized URL
        if (url[i] == '.' || url[i] == '/') {
            int len = strlen(sanitized);
            sanitized[len] = url[i];
            sanitized[len+1] = '\0';
            continue;
        }

        // If the character is an uppercase letter, convert it to lowercase
        if (url[i] >= 'A' && url[i] <= 'Z') {
            int len = strlen(sanitized);
            sanitized[len] = url[i] - 'A' + 'a';
            sanitized[len+1] = '\0';
            continue;
        }

        // Otherwise, add the character to the sanitized URL
        int len = strlen(sanitized);
        sanitized[len] = url[i];
        sanitized[len+1] = '\0';
    }

    // Return the sanitized URL
    return sanitized;
}

int main() {

    // Example URLs to sanitize
    char url1[] = "   Https://Www.Example.com/path/to/file.pdf?arg1=val1&arg2=val2#section1   ";
    char url2[] = "www.example.com/path/to/directory/";
    char url3[] = "https://example.com/path/to/#section2";

    // Sanitize the URLs
    char* sanitized_url1 = sanitize_url(url1);
    char* sanitized_url2 = sanitize_url(url2);
    char* sanitized_url3 = sanitize_url(url3);

    // Print the sanitized URLs
    printf("Sanitized URL 1: %s\n", sanitized_url1);
    printf("Sanitized URL 2: %s\n", sanitized_url2);
    printf("Sanitized URL 3: %s\n", sanitized_url3);

    // Free memory
    free(sanitized_url1);
    free(sanitized_url2);
    free(sanitized_url3);

    return 0;
}