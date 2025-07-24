//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <url>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  CURL *curl = curl_easy_init();
  if (!curl) {
    fprintf(stderr, "Failed to initialize curl.\n");
    exit(EXIT_FAILURE);
  }

  curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

  while (1) {
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "Failed to get %s: %s\n", argv[1], curl_easy_strerror(res));
    } else {
      printf("%s is up!\n", argv[1]);
    }
    sleep(10);
  }

  curl_easy_cleanup(curl);
  return EXIT_SUCCESS;
}