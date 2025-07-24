//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://www.example.com"
#define SECONDS_TO_WAIT 60 // Wait time between each check

bool check_website(char *url) {
  CURL *curl;
  CURLcode result;
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    result = curl_easy_perform(curl);
    if(result == CURLE_OK) {
      curl_easy_cleanup(curl);
      return true;
    } else {
      curl_easy_cleanup(curl);
      return false;
    }
  }
  return false;
}

int main() {
  time_t start, end;
  double time_taken;
  bool is_up;
  printf("Starting website uptime monitor\n");
  while(true) {
    start = clock(); // Start the timer
    is_up = check_website(URL);
    end = clock(); // Stop the timer
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    if(is_up) {
      printf("%s is UP! Response time: %f seconds\n", URL, time_taken);
    } else {
      printf("%s is DOWN!\n", URL);
    }
    sleep(SECONDS_TO_WAIT); // Wait for some time before checking again
  }
  return 0;
}