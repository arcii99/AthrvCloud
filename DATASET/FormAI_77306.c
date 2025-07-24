//FormAI DATASET v1.0 Category: Browser Plugin ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a given URL is safe
int isSafe(char *url) {
    // List of blacklisted words and phrases
    char blacklist[5][20] = {"gambling", "pornography", "malware", "phishing", "fraud"};
    int i, j, k, l, m, len;
    len = strlen(url);
    
    // Check each word in the blacklist
    for (i = 0; i < 5; i++) {
        l = strlen(blacklist[i]);
        if (len >= l) {
            for (j = 0; j <= len-l; j++) {
                for (k = 0; k < l; k++) {
                    if (url[j+k] != blacklist[i][k]) {
                        break;
                    }
                    if (k == l-1) {
                        printf("URL blocked: contains blacklisted word/phrase '%s'\n", blacklist[i]);
                        return 0;
                    }
                }
            }
        }
    }
    
    // Check if URL starts with "https://"
    if (strncmp(url, "https://", 8) != 0) {
        printf("URL blocked: must be accessed over HTTPS\n");
        return 0;
    }
    
    // Check if URL ends with a valid file extension
    char *extensions[5] = {".html", ".htm", ".php", ".jsp", ".asp"};
    for (i = 0; i < 5; i++) {
        l = strlen(extensions[i]);
        if (len >= l) {
            m = len - l;
            if (strncmp(url+m, extensions[i], l) == 0) {
                return 1; // URL is safe
            }
        }
    }
    
    // URL does not end with a valid file extension
    printf("URL blocked: invalid file extension\n");
    return 0;
}

// Function to display a message in the browser
void showMessage(char *message) {
    printf("Message from browser: %s\n", message);
}

// Function to handle incoming URL requests
void handleRequest(char *url) {
    if (isSafe(url)) {
        // Display the URL in the browser
        showMessage(url);
    }
}

// Example main function
int main() {
    // Simulate an incoming URL request
    char url[100] = "https://www.example.com/test.html";
    handleRequest(url);
    return 0;
}