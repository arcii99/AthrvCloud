//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Define target URL and expected response
#define TARGET_URL "http://example.com"
#define EXPECTED_RESPONSE "200 OK"

// Callback function for handling HTTP response headers
size_t handle_response_headers(void *ptr, size_t size, size_t nmemb, void *stream) {
    char *header = (char *)ptr;
    if (strncasecmp(header, "HTTP", 4) == 0) {
        // Extract the status code from the response
        strtok(header, " ");
        char *status_code = strtok(NULL, " ");
        int code = atoi(status_code);
        if (code == 200) {
            printf("Success: %s\n", header);
        } else {
            printf("Error: %s\n", header);
        }
    }
    return size * nmemb;
}

int main() {
    CURL *curl;
    CURLcode res;
    
    // Initialize curl library
    curl_global_init(CURL_GLOBAL_ALL);
    
    // Initialize curl handle
    curl = curl_easy_init();
    if (!curl) {
        printf("Error: Could not init curl\n");
        return 1;
    }
    
    // Set target URL
    curl_easy_setopt(curl, CURLOPT_URL, TARGET_URL);
    
    // Set HTTP header
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    
    // Use HEAD request method to only fetch headers (not body)
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    
    // Set callback function for handling response headers
    curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, handle_response_headers);
    
    // Execute the HTTP request
    res = curl_easy_perform(curl);
    
    // Cleanup
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    
    return 0;
}