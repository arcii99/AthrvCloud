//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
 
int main(void)
{
  CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://www.example.com/");
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); /* don't download the body */
 
    res = curl_easy_perform(curl);
 
    if(res == CURLE_OK) {
      double time;
      curl_easy_getinfo(curl, CURLINFO_TOTAL_TIME, &time);
      printf("Website response time: %.2f seconds\n", time);
    }
 
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}