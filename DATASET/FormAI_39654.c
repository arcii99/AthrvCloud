//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main() {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.surrealist-http.com");
        
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "User-Agent: SurrealistClient/1.0");
        headers = curl_slist_append(headers, "Accept: text/vaporware");
        headers = curl_slist_append(headers, "X-Dream-Header: manifesting_spontaneous_chaos");

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}