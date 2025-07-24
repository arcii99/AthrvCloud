//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

// Function to monitor website uptime
void checkWebsite(char* url) {
  CURL* curl;
  CURLcode res;
  // initialize curl
  curl = curl_easy_init();
  if(curl) {
    // Set the URL
    curl_easy_setopt(curl, CURLOPT_URL, url);
    // Perform the Request
    res = curl_easy_perform(curl);
    // Check for errors
    if(res != CURLE_OK) {
      printf("Website %s is down!\n", url);
    } else {
      printf("Website %s is up and running!\n", url);
    }
    // Cleanup
    curl_easy_cleanup(curl);
  } 
}

int main() {
  // Array of website URLs to monitor
  char* websites[3] = {"https://www.google.com", "https://www.facebook.com", "https://www.twitter.com"};
  
  while(true) {
    printf("Checking website uptime...\n");
    for(int i=0; i<3; i++) {
      checkWebsite(websites[i]);
    }
    // Sleep for 30 seconds
    sleep(30);
  }
  
  return 0;
}