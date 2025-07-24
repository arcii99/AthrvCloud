//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 128

typedef struct {
    char url[MAX_URL_LENGTH];
    int timeout;
    int status;
} Website;

int checkStatus(char *url, int timeout) {
    CURL *curl;
    CURLcode res;
    int status = -1;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout);
        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            long code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &code);
            status = (int)code;
        }
        curl_easy_cleanup(curl);
    }
    return status;
}

void printStatus(int status) {
    if (status == 200) {
        printf("OK");
    } else if (status >= 400 && status <= 499) {
        printf("CLIENT ERROR");
    } else if (status >= 500 && status <= 599) {
        printf("SERVER ERROR");
    } else {
        printf("UNKNOWN");
    }
}

int main(int argc, char *argv[]) {
    Website websites[] = {
        {"https://www.google.com", 10, -1},
        {"https://www.facebook.com", 10, -1},
        {"https://www.twitter.com", 10, -1},
        {"https://www.medium.com", 10, -1},
        {"https://www.reddit.com", 10, -1},
        {"https://www.github.com", 10, -1}
    };
    int num_websites = sizeof(websites)/sizeof(Website);
    printf("Checking website status...\n");

    for (int i=0; i<num_websites; i++) {
        printf("%s - ", websites[i].url);
        websites[i].status = checkStatus(websites[i].url, websites[i].timeout);
        if (websites[i].status != -1) {
            printStatus(websites[i].status);
            printf("(%d)\n", websites[i].status);
        } else {
            printf("ERROR\n");
        }
    }
    return 0;
}