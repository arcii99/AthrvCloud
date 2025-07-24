//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(ptr, size, nmemb, stream);
}

int main(void) {
  CURL *curl;
  FILE *fp;
  CURLcode res;
  char *url = "https://www.example.com/";
  char outfilename[FILENAME_MAX] = "output.tmp";

  curl = curl_easy_init();
  if (curl) {
    fp = fopen(outfilename,"wb");
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      printf("Curl error: %s\n", curl_easy_strerror(res));
    }
    curl_easy_cleanup(curl);
    fclose(fp);
    printf("Successfully connected to website and downloaded content\n");
    return 0;
  }
  else {
    printf("Failed to create CURL connection to website\n");
    return 1;
  }
}