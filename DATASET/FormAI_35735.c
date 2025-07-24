//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <unistd.h>

#define URL "https://www.example.com"

int main(void) {
  CURL *curl;
  CURLcode res;
  int sleepTime = 10;

  curl = curl_easy_init();

  if (curl) {
    while (1) {
      curl_easy_setopt(curl, CURLOPT_URL, URL);
      res = curl_easy_perform(curl);
      if(res != CURLE_OK) {
        printf("Website is down!\n");
      } else {
        printf("Website is up and running!\n");
      }
      sleep(sleepTime);
    }

    curl_easy_cleanup(curl);
  }

  return 0;
}