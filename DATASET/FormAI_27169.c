//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

#define URL "https://www.example.com"
#define INTERVAL 60 // in seconds

int main(void) {
  CURL *curl;
  CURLcode res;
  
  printf("Starting Website Uptime Monitor...\n");

  while (1) {
    curl = curl_easy_init();
    if (curl) {
      curl_easy_setopt(curl, CURLOPT_URL, URL);

      res = curl_easy_perform(curl);
      if (res != CURLE_OK) {
        printf("Error: failed to reach website - %s\n", curl_easy_strerror(res));
      } else {
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        if (http_code >= 200 && http_code < 300) {
          printf("Success: website is up with response code %ld!\n", http_code);
        } else {
          printf("Error: website returned invalid status code %ld\n", http_code);
        }
      }

      curl_easy_cleanup(curl);
    } else {
      printf("Error: failed to initialize curl.\n");
    }

    sleep(INTERVAL);
  }

  return 0;
}