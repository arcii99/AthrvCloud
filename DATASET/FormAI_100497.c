//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <curl/curl.h>
#include <pthread.h>

#define MAX_URLS 10
#define TIMEOUT 5

// Struct to hold url and status
typedef struct {
    char url[256];
    bool status;
} url_info;

// Array to hold url_info structs
url_info urls[MAX_URLS];
int num_urls = 0;

// Thread function to check status of url
void* check_url(void* arg) {
    CURL* curl;
    CURLcode res;
    url_info* url = (url_info*) arg;
    
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url->url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);
        
        res = curl_easy_perform(curl);
        
        if (res == CURLE_OK) {
            url->status = true;
        } else {
            url->status = false;
            fprintf(stderr, "Error retrieving %s: %s\n", url->url, curl_easy_strerror(res));
        }
        
        curl_easy_cleanup(curl);
    } else {
        url->status = false;
        fprintf(stderr, "Error initializing curl for %s\n", url->url);
    }
    
    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t threads[MAX_URLS];
    
    // Read in urls from file
    FILE* fp = fopen("urls.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening urls.txt\n");
        exit(EXIT_FAILURE);
    }
    
    char line[256];
    while (fgets(line, 256, fp) != NULL) {
        line[strcspn(line, "\n")] = 0; // Remove trailing newline
        strncpy(urls[num_urls].url, line, 256);
        urls[num_urls].status = false;
        num_urls++;
    }
    
    fclose(fp);
    
    // Start threads to check url status
    for (i=0; i<num_urls; i++) {
        pthread_create(&threads[i], NULL, check_url, &urls[i]);
    }
    
    // Wait for threads to complete
    for (i=0; i<num_urls; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print results
    printf("URL\t\tStatus\n");
    for (i=0; i<num_urls; i++) {
        printf("%s\t%s\n", urls[i].url, (urls[i].status) ? "UP" : "DOWN");
    }
    
    return 0;
}