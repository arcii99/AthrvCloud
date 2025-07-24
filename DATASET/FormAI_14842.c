//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

#define URL "http://www.example.com"

void check_website(const char *url) {
  CURL *curl = curl_easy_init();
  if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, url);
      CURLcode res = curl_easy_perform(curl);
      if(res == CURLE_OK) {
          printf("%s is up and running!\n", url);
      } else {
          printf("%s is down. Error: %s\n", url, curl_easy_strerror(res));
      }
      curl_easy_cleanup(curl);
  }
}

int main() {
  printf("Welcome to our Website Uptime Monitor!\n");

  while(true) {
      check_website(URL);
      time_t rawtime;
      struct tm *timeinfo;
      time(&rawtime);
      timeinfo = localtime(&rawtime);
      printf("Last checked at %s", asctime(timeinfo));
      sleep(60); // wait 60 seconds before checking again
  }

  return 0;
}