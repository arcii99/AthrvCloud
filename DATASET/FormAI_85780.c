//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define URL "https://www.example.com/" // Change the URL as per your requirement

void check_website() {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, URL);

    // These 2 lines limit the response time to 10 seconds
    curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 10000L);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT_MS, 10000L);

    res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
      printf("Website is up and running!\n");
    } else {
      printf("Website is down!\n");
    }

    curl_easy_cleanup(curl);
  }
}

int main() {
  while(1) {
    check_website();
    sleep(60); // Check the website every minute
  }

  return 0;
}