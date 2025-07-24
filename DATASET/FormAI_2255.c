//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Helper function to check if a character is a hexadecimal digit
int is_hex_digit(char c) {
    return (isdigit(c) || (tolower(c) >= 'a' && tolower(c) <= 'f'));
}

// Helper function to convert a hexadecimal digit character to its integer value (ignores case)
int hex_digit_to_int(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else {
        return tolower(c) - 'a' + 10;
    }
}

// Function to sanitize a URL by encoding reserved characters as their hexadecimal representations
char *sanitize_url(const char *url) {
    // Define a lookup table for reserved characters and their substitutions
    const char *reserved_chars = "\"<>#%{}|\\^~[]`";
    const char *encoded_chars[] = {"%22", "%3C", "%3E", "%23", "%25", "%7B", "%7D", "%7C", "%5C", "%5E", "%7E", "%5B", "%5D", "%60"};

    // Determine the length of the sanitized URL
    size_t length = 0;
    for (const char *c = url; *c != '\0'; c++) {
        if (isspace(*c) || strchr(reserved_chars, *c) != NULL) {
            length += 3; // reserved character requires 3 characters (e.g. %22 for double quote)
        } else {
            length++; // normal character requires 1 character
        }
    }

    // Allocate memory for the sanitized URL and construct it
    char *sanitized_url = malloc(length + 1); // +1 for null terminator
    char *p = sanitized_url;
    for (const char *c = url; *c != '\0'; c++) {
        if (isspace(*c)) {
            *p = '+'; // space should be replaced with plus sign
            p++;
        } else if (strchr(reserved_chars, *c) != NULL) {
            // reserved character requires encoding as its hexadecimal representation
            sprintf(p, "%s", encoded_chars[strchr(reserved_chars, *c) - reserved_chars]);
            p += 3;
        } else if (*c == '%') {
            if (is_hex_digit(*(c + 1)) && is_hex_digit(*(c + 2))) {
                // hexadecimal representation of character is already present
                *p = *c;
                *(p + 1) = *(c + 1);
                *(p + 2) = *(c + 2);
                p += 3;
                c += 2;
            } else {
                // % sign is not followed by two hexadecimal digits, so it needs encoding as a literal %
                sprintf(p, "%%");
                p += 2;
            }
        } else {
            // normal character - copy it to the sanitized URL
            *p = *c;
            p++;
        }
    }

    // Null terminate the sanitized URL and return it
    *p = '\0';
    return sanitized_url;
}

int main() {
    // Test the sanitize_url function with some sample URLs
    const char *url1 = "https://www.google.com/search?q=url+sanitizer&oq=url+sanitizer&aqs=chrome..69i57j35i39j0i22i30j0i390l2.3246j1j7&sourceid=chrome&ie=UTF-8";
    printf("Original URL 1: %s\n", url1);
    char *sanitized_url1 = sanitize_url(url1);
    printf("Sanitized URL 1: %s\n", sanitized_url1);
    free(sanitized_url1);

    const char *url2 = "https://example.com/Some/File%20Name.html?param1=value1&param2=value2";
    printf("Original URL 2: %s\n", url2);
    char *sanitized_url2 = sanitize_url(url2);
    printf("Sanitized URL 2: %s\n", sanitized_url2);
    free(sanitized_url2);

    const char *url3 = "https://www.example.com/Some/File%2GName.html";
    printf("Original URL 3: %s\n", url3);
    char *sanitized_url3 = sanitize_url(url3);
    printf("Sanitized URL 3: %s\n", sanitized_url3);
    free(sanitized_url3);

    return 0;
}