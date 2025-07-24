//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

void check_website(char* url) {
  CURL *curl;
  CURLcode res;
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
      printf("%s is UP!\n", url);
    } else {
      printf("%s is DOWN!\n", url);
    }
    curl_easy_cleanup(curl);
  }
}

int main() {
  char* websites_to_monitor[] = {"https://www.google.com", "https://www.facebook.com", "https://www.youtube.com", "https://www.instagram.com"};

  int num_websites = sizeof(websites_to_monitor)/sizeof(websites_to_monitor[0]);

  printf("Welcome to the Website Uptime Monitor! Let's get started.\n");

  while(1) {
    printf("Checking the status of %d websites...\n", num_websites);

    for(int i=0; i<num_websites; i++) {
      check_website(websites_to_monitor[i]);
    }

    printf("All websites checked. Sleeping for 10 seconds before checking again.\n");

    sleep(10); // wait 10 seconds before checking again
  }

  return 0;
}