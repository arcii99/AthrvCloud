//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main() {
  // Enter the URL to monitor
  char url[] = "http://www.example.com";

  // Set the curl object properties 
  CURL *curl;
  curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

  // Set the timeout period and perform the request
  curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
  CURLcode res = curl_easy_perform(curl);

  // Handle the response
  if(res == CURLE_OK) {
    printf("Website %s is UP!\n", url);
  } else {
    printf("SOMETHING'S WRONG! Website %s is DOWN!\n", url);
  }

  // Clean up and exit
  curl_easy_cleanup(curl);
  curl_global_cleanup();
  return 0;
}