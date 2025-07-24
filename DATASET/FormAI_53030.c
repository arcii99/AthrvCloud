//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void) {

  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_DEFAULT);
  curl = curl_easy_init();
  
  if(curl) {
    // Set the URL we want to ping
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com/");
    // Set the timeout period in seconds
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    // Follow any redirects to the final location
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Perform the request and capture the response code
    res = curl_easy_perform(curl);

    if (res == CURLE_OK) { //If the response is ok
      printf("Website is up and running!\n");
    } else { //If the response isn't ok
      fprintf(stderr, "Website is down or unreachable. Error code: %d\n", res);
    }

    curl_easy_cleanup(curl); //Cleanup the curl object
  }

  curl_global_cleanup(); // Cleanup the global curl environment

  return 0;
}