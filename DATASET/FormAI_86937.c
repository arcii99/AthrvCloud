//FormAI DATASET v1.0 Category: Browser Plugin ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char input[MAX_LEN];
    printf("Enter a URL: ");
    fgets(input, MAX_LEN, stdin);

    // Check for suspicious keywords
    if (strstr(input, "facebook") || strstr(input, "google") || strstr(input, "amazon")) {
        printf("Access denied. URL contains suspicious keywords.\n");
        return 1;
    }

    // Check for potential XSS attacks
    if (strstr(input, "<script>") || strstr(input, "<html>") || strstr(input, "<body>")) {
        printf("Access denied. Potential XSS attack detected.\n");
        return 1;
    }

    // Encode the URL for added security
    char encoded[MAX_LEN];
    int i, j;
    for (i = 0, j = 0; input[i] != '\n'; i++, j++) {
        if (input[i] == ' ') {
            encoded[j] = '%';
            encoded[j+1] = '2';
            encoded[j+2] = '0';
            j += 2;
        } else {
            encoded[j] = input[i];
        }
    }
    encoded[j] = '\0';

    // Print the encoded URL and exit
    printf("Encoded URL: %s\n", encoded);
    return 0;
}