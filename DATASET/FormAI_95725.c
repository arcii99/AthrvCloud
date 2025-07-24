//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<curl/curl.h>

int main(int argc, char *argv[]) {

  char *url = argv[1];

  while(1) {
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, url);
      curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
      res = curl_easy_perform(curl);

      if(res != CURLE_OK) {
        printf("Website is down!\n");
      }
      else {
        printf("Website is up!\n");
      }

      curl_easy_cleanup(curl);
    }

    sleep(300); // Check website every 5 minutes
  }

  return 0;
}