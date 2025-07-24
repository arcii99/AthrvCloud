//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define URL "https://www.example.com" // URL of website to monitor
#define MAX_TIMEOUT 10L // Max time allowed for connection in seconds

int main() {
  CURL *curl;
  CURLcode res;

  while(1) { // Loop to monitor website continuously
    curl = curl_easy_init();
    if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, URL); // Set the URL to monitor
      curl_easy_setopt(curl, CURLOPT_TIMEOUT, MAX_TIMEOUT);
      res = curl_easy_perform(curl); // Perform the request
      
      if(res != CURLE_OK) { // If connection not successful
        printf("Website is down! Trying to reconnect...\n");
      }
      
      curl_easy_cleanup(curl);
    }
    sleep(60); // Wait for 1 minute before monitoring again
  }
  
  return 0;
}