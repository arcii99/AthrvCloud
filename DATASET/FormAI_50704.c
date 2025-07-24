//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

#define URL "http://www.google.com"
#define INTERVAL 5

int main() {
  // Declare variables
  CURL *curl;
  CURLcode res;
  bool is_website_up = false;
  
  // Initialize curl
  curl = curl_easy_init();
  
  // Check if curl was initialized successfully
  if(curl) {
    while(true) {
      // Make the request
      res = curl_easy_setopt(curl, CURLOPT_URL, URL);
      
      // Check if the request was successful
      if(res != CURLE_OK) {
        is_website_up = false;
        
        // Log the error
        fprintf(stderr, "Error while making request: %s\n", curl_easy_strerror(res));
      } else {
        is_website_up = true;
      }
      
      // Print whether the website is up or down
      if(is_website_up) {
        printf("Website is up!\n");
      } else {
        printf("Website is down!\n");
      }
      
      // Wait INTERVAL seconds before making the next request
      sleep(INTERVAL);
    }
    
    // Clean up curl
    curl_easy_cleanup(curl);
  }
  
  return 0;
}