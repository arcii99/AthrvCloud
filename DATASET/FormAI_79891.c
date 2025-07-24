//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define URL "https://www.example.com"
#define TIMEOUT 10L
#define MAX_SIZE 256

int main(void) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

    res = curl_easy_perform(curl);
    if (res == CURLE_OK) {
      long http_code = 0;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
      if (http_code == 200) {
        printf("Website is up!\n");
      } else {
        printf("Website returned HTTP error code %ld\n", http_code);
      }
    } else {
      printf("Error: %s\n", curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);
  } else {
    printf("Error: Could not initialize libcurl.\n");
  }

  return 0;
}