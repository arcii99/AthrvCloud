//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define MAX_URLS 10 // maximum number of URLs to check
#define MAX_LEN 1024 // maximum length of URL 

// function that checks the status of a URL
int check_url(char* url) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init(); // initialize curl
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url); // set the URL to check
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // use HEAD request to get only status
    res = curl_easy_perform(curl);

    if(res != CURLE_OK) { // if curl_easy_perform() returns an error
      printf("Error: %s\n", curl_easy_strerror(res));
      curl_easy_cleanup(curl);
      return 0;
    }

    int http_code = 0; // status code of the URL
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    curl_easy_cleanup(curl);

    if(http_code >= 200 && http_code < 300) { // successful status codes
      printf("%s is UP\n", url);
      return 1;
    } else {
      printf("%s is DOWN (status code %d)\n", url, http_code);
      return 0;
    }
  }

  return 0;
}

int main() {
  char urls[MAX_URLS][MAX_LEN]; // array of URLs
  int num_urls = 0; // number of URLs to check

  // get URLs to check from user
  printf("Enter the URLs to check (one per line, up to %d URLs):\n", MAX_URLS);
  while(num_urls < MAX_URLS) {
    char url[MAX_LEN];
    fgets(url, MAX_LEN, stdin);
    // remove trailing newline character from input
    if(strchr(url, '\n')) {
      *strchr(url, '\n') = '\0';
    }

    // break out of loop if user enters an empty line
    if(strcmp(url, "") == 0) {
      break;
    }

    // add URL to array
    if(num_urls < MAX_URLS) {
      strcpy(urls[num_urls++], url);
    } else {
      printf("Maximum number of URLs (%d) reached\n", MAX_URLS);
      break;
    }
  }

  // check each URL in array
  for(int i = 0; i < num_urls; i++) {
    check_url(urls[i]);
  }

  return 0;
}