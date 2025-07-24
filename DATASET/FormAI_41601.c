//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// function to check website status
int check_website(char *url) {
  CURL *curl;
  CURLcode res;

  // initialize curl object
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url); // set URL to check
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // use HEAD request instead of GET request
    res = curl_easy_perform(curl); // perform the request

    // check if request was successful and return status code
    if(res == CURLE_OK) {
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      return (int) response_code;
    }

    curl_easy_cleanup(curl); // cleanup curl object
  }

  return -1; // return -1 if request fails
}

int main() {
  char *url = "https://www.example.com"; // website URL
  int status;

  // loop to check website status every 10 seconds
  while(1) {
    status = check_website(url);

    // check status code and print message accordingly
    if(status == 200) {
      printf("%s is up and running!\n", url);
    }
    else {
      printf("%s is down! (Status code: %d)\n", url, status);
    }

    sleep(10); // wait for 10 seconds
  }

  return 0;
}