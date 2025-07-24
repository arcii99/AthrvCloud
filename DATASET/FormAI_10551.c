//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <curl/curl.h>

bool check_website(const char *url) {
  CURL *curl;
  CURLcode res;
  
  curl = curl_easy_init();
  
  if(curl){
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    res = curl_easy_perform(curl);

    if (res == CURLE_OK){
      long response_code;

      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      curl_easy_cleanup(curl);

      if(response_code == 200) {
          return true;
      }
    }
  }
  
  return false;
}

int main() {
  const char *url = "https://www.mywebsite.com";
  int delay = 60; // seconds
  bool is_up = check_website(url);

  while (true) {
    if (!is_up) {
      printf("%s is down!\n", url);
      is_up = true;
    }

    if (check_website(url)) {
      printf("%s is up!\n", url);
      is_up = false;
    }

    sleep(delay);
  }

  return 0;
}