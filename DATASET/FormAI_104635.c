//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Cryptic
// C URL Sanitizer Example Program
// Cryptic Style
#include <stdio.h>
#include <string.h>
#define MAX_URL_LENGTH 200

// Function to sanitize the url
void sanitizeUrl(char *url) {
    char sanitizedUrl[MAX_URL_LENGTH] = "";
    int index = 0;
    for (int i = 0; i < strlen(url); i++) {
        if ((url[i] >= 'A' && url[i] <= 'Z') || (url[i] >= 'a' && url[i] <= 'z') || (url[i] >= '0' && url[i] <= '9') || url[i] == '.' || url[i] == '/' || url[i] == ':' || url[i] == '-') {
            // Keep allowed characters
            sanitizedUrl[index++] = url[i];
        } else {
            // Convert disallowed characters to hexadecimal representation
            char hex[3];
            sprintf(hex, "%02X", url[i]);
            sanitizedUrl[index++] = '%';
            sanitizedUrl[index++] = hex[0];
            sanitizedUrl[index++] = hex[1];
        }
    }
    strcpy(url, sanitizedUrl);
}

int main() {
    char url[MAX_URL_LENGTH] = "https://www.google.com/search?q=example&rlz=1C1GCEA_enUS832US832&oq=example&aqs=chrome.0.35i39l2j0l4j46j69i60.2311j1j7&sourceid=chrome&ie=UTF-8";
    printf("Original URL: %s\n", url);
    sanitizeUrl(url);
    printf("Sanitized URL: %s\n", url);
    return 0;
}