//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URLS 50
#define MAX_URL_LENGTH 100

// Initialize mutex variables
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t url_count_mutex = PTHREAD_MUTEX_INITIALIZER;

// Global variables for thread communication
char urls[MAX_URLS][MAX_URL_LENGTH];
int url_count;

// Function to check a single URL's uptime
void check_url(char *url) {
    CURL *curl = curl_easy_init();
    if (curl) {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            pthread_mutex_lock(&print_mutex);
            printf("%s - Response code: %ld\n", url, response_code);
            pthread_mutex_unlock(&print_mutex);
        } else {
            pthread_mutex_lock(&print_mutex);
            printf("%s - Error: %s\n", url, curl_easy_strerror(res));
            pthread_mutex_unlock(&print_mutex);
        }
        curl_easy_cleanup(curl);
    }
}

// Function for worker threads to execute
void *worker(void *arg) {
    char url[MAX_URL_LENGTH];
    while (1) {
        // Get a URL to check from the queue
        pthread_mutex_lock(&url_count_mutex);
        if (url_count == 0) {
            pthread_mutex_unlock(&url_count_mutex);
            break;
        }
        url_count--;
        strcpy(url, urls[url_count]);
        pthread_mutex_unlock(&url_count_mutex);

        // Check the URL's uptime
        check_url(url);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    // Initialize array of example URLs to monitor
    const char *example_urls[] = {
        "https://www.google.com",
        "https://www.example.com",
        "https://www.github.com",
        "https://www.facebook.com"
    };
    int example_url_count = sizeof(example_urls) / sizeof(char *);

    // Copy example URLs into queue of URLs to monitor
    for (int i = 0; i < example_url_count; i++) {
        strcpy(urls[i], example_urls[i]);
    }
    url_count = example_url_count;

    // Initialize worker threads
    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }

    // Wait for worker threads to finish
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}