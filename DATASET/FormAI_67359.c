//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* sanitize_url(char *url) {

    char *clean_url = malloc(strlen(url)+1); // Make a copy of input url
    char *safe_url = malloc(strlen(url)+1); // Final sanitized url

    // Replace '+' with ' '
    for (int i=0; i<strlen(url); i++) {
        if (url[i] == '+')
            clean_url[i] = ' ';
        else
            clean_url[i] = url[i];
    }

    // Get temporary working URL
    char *temp_url = strtok(clean_url, "&");
    while (temp_url != NULL) {
        int equals_pos = -1;

        // Look for Key-Value pair in URL
        for (int i=0; i<strlen(temp_url); i++) {
            if (temp_url[i] == '=') {
                equals_pos = i;
                break;
            }
        }

        if (equals_pos == -1) { // No KV pair found
            strcat(safe_url, temp_url); // Append as it is
        } else { // KV pair found
            char *key = malloc(equals_pos+1);
            strncpy(key, temp_url, equals_pos);
            key[equals_pos] = '\0'; // Terminate key
            strcat(safe_url, key); 
            strcat(safe_url, "="); 

            char *value = temp_url + equals_pos + 1;
            // Replace unsafe characters in value with ASCII codes
            for (int i=0; i<strlen(value); i++) {
                if (value[i] == '<') {
                    value[i] = ' '; // Remove
                } else if (value[i] == '>') {
                    value[i] = ' '; // Remove
                } else if (value[i] == '\'') {
                    value[i] = ' '; // Remove
                } else if (value[i] == '"') {
                    value[i] = ' '; // Remove
                } else if (value[i] == '&') {
                    value[i] = ' '; // Remove
                } else if (value[i] == '/') {
                    value[i] = ' '; // Remove
                } else if (value[i] == '\\') {
                    value[i] = ' '; // Remove
                } else if (value[i] == '(') {
                    value[i] = '%'; // Encode parenthesis
                    strcat(safe_url, "28"); // %28
                } else if (value[i] == ')') {
                    value[i] = '%'; // Encode parenthesis
                    strcat(safe_url, "29"); // %29
                } else if (value[i] == ';') {
                    value[i] = ' '; // Remove
                } else if (value[i] == ':') {
                    value[i] = ' '; // Remove
                } else if (value[i] == '?') {
                    value[i] = ' '; // Remove
                } else if (value[i] == '#') {
                    value[i] = ' '; // Remove
                }

                char hex_val[3] = ""; // Get Hex value of character
                snprintf(hex_val, 3, "%02X", value[i]);
                strcat(safe_url, hex_val); // Append hex value
            }
            free(key);
        }

        strcat(safe_url, "&"); // Add "&" for next pair
        temp_url = strtok(NULL, "&"); // Get next URL
    }

    safe_url[strlen(safe_url)-1] = '\0'; // Remove last "&"
    free(clean_url);
    return safe_url;
}

int main()
{
    char *unsafe_url = "https://example.com/test/?name=<script>alert('xss')</script>";

    char *safe_url = sanitize_url(unsafe_url);

    printf("Unsafe URL : %s\n" , unsafe_url);
    printf("Safe URL : %s\n" , safe_url);

    free(safe_url);
    return 0;
}