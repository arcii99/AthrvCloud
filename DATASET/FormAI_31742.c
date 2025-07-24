//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URLS 10
#define MAX_URL_LENGTH 100

int main()
{
  // Declare variables
  char urls[MAX_URLS][MAX_URL_LENGTH];
  int status[MAX_URLS];
  int num_urls = 0;
  int i = 0;
  CURL *curl;
  
  // Prompt user to enter URLs
  printf("Enter URLs to monitor (up to %d, enter a blank line to continue):\n", MAX_URLS);
  
  while (1) {
    fgets(urls[num_urls], MAX_URL_LENGTH, stdin);
    if (urls[num_urls][0] == '\n') {
      break;
    }
    num_urls++;
    if (num_urls == MAX_URLS) {
      break;
    }
  }
  
  printf("Monitoring %d URLs...\n", num_urls);
  
  // Begin monitoring URLs
  while (1) {
    sleep(10); // wait 10 seconds between checks
    
    for (i = 0; i < num_urls; i++) {
      curl = curl_easy_init();
      if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, urls[i]);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
          curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status[i]);
        }
        else {
          status[i] = res; // if there's a connection error, use the error code as the status
        }
        curl_easy_cleanup(curl);
      }
    }
    
    // Display status of URLs
    printf("Status of URLs:\n");
    for (i = 0; i < num_urls; i++) {
      if (status[i] == CURLE_OK) {
        printf("%s is up.\n", urls[i]);
      }
      else {
        printf("%s is down with error code %d.\n", urls[i], status[i]);
      }
    }
    
  }
  
  return 0;
}