//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define MAX_LOG_LENGTH 1024

void log_event(char* event) {
    FILE* fp;
    time_t now;
    char timestamp[26];

    // Get current time
    time(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));

    // Write event to log file
    fp = fopen("log.txt", "a");
    fprintf(fp, "[%s] %s\n", timestamp, event);
    fclose(fp);
}

void check_url(char* url) {
    CURL* curl = curl_easy_init();
    CURLcode result;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // Only check response header
        result = curl_easy_perform(curl);

        if (result != CURLE_OK) { // Error occurred
            log_event(curl_easy_strerror(result));
            printf("%s : ERROR\n", url);
        }
        else { // Success
            printf("%s : OK\n", url);
        }

        curl_easy_cleanup(curl);
    }
}

int main() {
    char url[MAX_URL_LENGTH];
    FILE* fp;
    int num_urls = 0;

    // Read list of URLs from file
    fp = fopen("urls.txt", "r");
    if (!fp) {
        printf("Unable to open file 'urls.txt'\n");
        return 1;
    }

    while (fgets(url, MAX_URL_LENGTH, fp)) {
        // Remove newline character if present
        size_t len = strlen(url);
        if (len > 0 && url[len-1] == '\n') {
            url[len-1] = '\0';
        }

        // Check if URL is valid
        if (strlen(url) > 0) {
            num_urls++;
            check_url(url);
        }
    }

    fclose(fp);

    // Write summary to log file
    char log_message[MAX_LOG_LENGTH];
    sprintf(log_message, "Checked %d URLs", num_urls);
    log_event(log_message);

    return 0;
}