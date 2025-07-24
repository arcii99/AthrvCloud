//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Function to check website status
int checkWebsite(char *url) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    res = curl_easy_perform(curl);

    if(res == CURLE_OK) {
      long response_code;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
      if(response_code == 200) {
        curl_easy_cleanup(curl);
        return 1;
      }
    }
    curl_easy_cleanup(curl);
  }
  return 0;
}

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("Usage: %s <website url>\n", argv[0]);
    return 1;
  }

  char *url = argv[1];

  while(1) {
    int status = checkWebsite(url);
    if(status == 0) {
      printf("%s is down!\n", url);
    } else {
      printf("%s is up.\n", url);
    }
    sleep(10); // Check website status every 10 seconds
  }

  return 0;
}