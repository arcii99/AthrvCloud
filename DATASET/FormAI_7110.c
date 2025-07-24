//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

// Function to check website uptime
int check_uptime(char *url) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK) {
      return 0;
    }
    curl_easy_cleanup(curl);
    return 1;
  }
  return 0;
}

int main() {
  // Specify website URL to monitor
  char *url = "https://www.example.com/";

  // Specify time interval for checking website uptime
  int interval = 60; // 1 minute

  // Check website uptime continuously
  while(1) {
    if(check_uptime(url)) {
      printf("%s is up and running!\n", url);
    } else {
      printf("%s is down!\n", url);
    }
    sleep(interval);
  }

  return 0;
}