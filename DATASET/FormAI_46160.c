//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: energetic
#include <stdio.h>
#include <unistd.h>
#include <curl/curl.h>

/* Global variables */
char* url = "https://www.example.com";      // website to monitor
int interval = 10;                          // time interval between checks in seconds

/* Function declarations */
void checkWebsite();

/* Main function */
int main() {
  // Create infinite loop to keep checking the website every X seconds
  while(1) {
    checkWebsite();
    sleep(interval);
  }
  return 0;
}

/* Function to check website uptime */
void checkWebsite() {
  CURL *curl;
  CURLcode res;
  long response_code;
  
  // Initialize curl 
  curl = curl_easy_init();

  // Set URL to monitor
  curl_easy_setopt(curl, CURLOPT_URL, url);

  // Set request type (HEAD) to only get headers and not the entire content
  curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

  // Execute request and check response code
  res = curl_easy_perform(curl);
  if(res == CURLE_OK) {
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
    if(response_code == 200) {
      printf("Website is up and running!\n");
    } else {
      printf("Website is down! HTTP error code %ld\n", response_code);
    }
  } else {
    printf("Error: Unable to check website status.\n");
  }

  // Cleanup
  curl_easy_cleanup(curl);
}