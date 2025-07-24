//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <curl/curl.h>

#define URL  "http://examplewebsite.com" // replace it with your website
#define TIMEOUT 30L  // set timeout in seconds
#define CHECK_INTERVAL 60L // set check interval in seconds

bool isWebsiteUp(const char *url) {
  CURL *curl = curl_easy_init();

  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, TIMEOUT);
    curl_easy_setopt(curl, CURLOPT_NOBODY, true);

    CURLcode res = curl_easy_perform(curl);

    if (res == CURLE_OK || res == CURLE_HTTP_RETURNED_ERROR) {
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      if (response_code >= 200 && response_code < 400) {
        curl_easy_cleanup(curl);
        return true;
      }
    }
    curl_easy_cleanup(curl);
  }
  return false;
}

int main() {

  printf("\n    Welcome to the Website Uptime Monitor!    \n\n");

  while (true) {
    if (isWebsiteUp(URL)) {
      printf("    Your website is UP and Running!    \n\n");
    } else {
      printf("    Oh No! Your website is DOWN!    \n\n");
    }
    sleep(CHECK_INTERVAL);
  }

  return 0;
}