//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define KB 1024

typedef enum {
    TEST_STARTED,
    TEST_IN_PROGRESS,
    TEST_COMPLETED
} test_state;

typedef struct {
    double download_speed;
    double upload_speed;
    test_state state;
} test_result;

static size_t write_callback(void *buffer, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

static size_t download_callback(void *buffer, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

static size_t upload_callback(void *buffer, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
}

int main(void) {
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize curl.\n");
        return EXIT_FAILURE;
    }

    CURLcode res = curl_easy_setopt(curl, CURLOPT_URL, "http://speedtest.tele2.net/10MB.zip");
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to set URL.\n");
        return EXIT_FAILURE;
    }

    test_result result = {0.0, 0.0, TEST_STARTED};
    res = curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to set write callback data.\n");
        return EXIT_FAILURE;
    }

    res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to set write callback function.\n");
        return EXIT_FAILURE;
    }

    res = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to set progress callback.\n");
        return EXIT_FAILURE;
    }

    res = curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, download_callback);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to set download progress callback.\n");
        return EXIT_FAILURE;
    }

    res = curl_easy_setopt(curl, CURLOPT_XFERINFOFUNCTION, upload_callback);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to set upload progress callback.\n");
        return EXIT_FAILURE;
    }

    res = curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to set timeout.\n");
        return EXIT_FAILURE;
    }

    res = curl_easy_setopt(curl, CURLOPT_LOW_SPEED_LIMIT, 5000L);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to set low transfer speed limit.\n");
        return EXIT_FAILURE;
    }

    res = curl_easy_setopt(curl, CURLOPT_LOW_SPEED_TIME, 5L);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to set low transfer speed time.\n");
        return EXIT_FAILURE;
    }

    res = curl_easy_perform(curl);

    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to perform the download/upload test.\n");
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }

    double speed;
    res = curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to retrieve download speed.\n");
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }
    result.download_speed = speed / KB;
    
    res = curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &speed);
    if (res != CURLE_OK) {
        fprintf(stderr, "Failed to retrieve upload speed.\n");
        curl_easy_cleanup(curl);
        return EXIT_FAILURE;
    }
    result.upload_speed = speed / KB;
    result.state = TEST_COMPLETED;

    printf("Download speed: %f KB/s\n", result.download_speed);
    printf("Upload speed: %f KB/s\n", result.upload_speed);

    curl_easy_cleanup(curl);

    return EXIT_SUCCESS;
}