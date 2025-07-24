//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

/* This function will be called by curl for every received header */
static size_t header_callback(char *buffer, size_t size, size_t nitems, void *userdata) {
  printf("Received Header: %s", buffer);
  return size * nitems;  // Must return the size of the data passed to it
}

/* This function will be called by curl for every received chunk of data */
static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata) {
  printf("Received Data Chunk: %s", ptr);
  return size * nmemb;  // Must return the size of the data passed to it
}

int main() {
  CURL *curl_handle;
  CURLcode res;

  /* Initialize curl */
  curl_global_init(CURL_GLOBAL_ALL);

  /* Create curl handle */
  curl_handle = curl_easy_init();

  if(curl_handle) {
    /* Set URL to retrieve */
    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://api.example.com/users");

    /* Set user agent */
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    /* Set header callback */
    curl_easy_setopt(curl_handle, CURLOPT_HEADERFUNCTION, header_callback);

    /* Set data callback */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_callback);

    /* Perform HTTP request */
    res = curl_easy_perform(curl_handle);

    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

    /* Cleanup curl handle */
    curl_easy_cleanup(curl_handle);
  }

  /* Cleanup curl global */
  curl_global_cleanup();

  return 0;
}