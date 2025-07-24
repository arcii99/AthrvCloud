//FormAI DATASET v1.0 Category: URL Sanitizer ; Style: Claude Shannon
/* 
 * C URL Sanitizer Example Program
 * By: Claude Shannon
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_URL_LEN 256
#define MAX_HOSTNAME_LEN 64
#define MAX_PORT_NUM_LEN 5

/* Function to sanitize URL */
void sanitize_url(char* url) {
    char hostname[MAX_HOSTNAME_LEN];
    char port[MAX_PORT_NUM_LEN];
    int i, j, len = strlen(url);
    int start, end, port_start, port_end;
    int found_colon = 0, found_slashes = 0;
    
    /* Find start and end of hostname */
    for (i = 0; i < len; i++) {
        if (url[i] == '/' && i < len-1 && url[i+1] == '/') {  // Found beginning of hostname
            found_slashes = 1;
            start = i+2;  // Beginning of hostname
            break;
        }
    }
    if (!found_slashes) {  // No forward slashes after protocol, no hostname
        printf("Error: Invalid URL format\n");
        exit(1);
    }
    for (i = start; i < len; i++) {
        if (url[i] == ':') {  // Found a colon, which may indicate a port specification
            found_colon = 1;
            end = i;
            break;
        }
        if (url[i] == '/') {  // Found end of hostname
            end = i;
            break;
        }
    }
    if (!found_colon) {  // No port specified
        end = i;
    }
    
    /* Copy hostname */
    memset(hostname, 0, MAX_HOSTNAME_LEN*sizeof(char));
    j = 0;
    for (i = start; i < end; i++) {
        hostname[j] = url[i];
        j++;
    }
    
    /* Sanitize port */
    if (found_colon) {  // Port specified
        port_start = i+1;
        port_end = len;
        memset(port, 0, MAX_PORT_NUM_LEN*sizeof(char));
        j = 0;
        for (i = port_start; i < port_end; i++) {
            if (url[i] < '0' || url[i] > '9') {  // Non-numeric character in port specification
                printf("Error: Invalid port specification\n");
                exit(1);
            }
            port[j] = url[i];
            j++;
        }
    }
    
    /* Construct sanitized URL */
    memset(url, 0, MAX_URL_LEN*sizeof(char));
    sprintf(url, "http://%s", hostname);
    if (found_colon) {  // Port specified
        sprintf(url+strlen(url), ":%s", port);
    }
}

int main() {
    char url[MAX_URL_LEN] = "http://www.example.com:8080/index.html";
    sanitize_url(url);
    printf("Sanitized URL: %s\n", url);  // Expected output: http://www.example.com:8080
    return 0;
}