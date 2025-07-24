//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

int main(void) {
  CURL *curl;
  CURLcode res;
  int romantic_mes = 0;
  char site_url[256];

  printf("My love, enter the URL of the website that you want to monitor: ");
  scanf("%s", site_url);

  curl_global_init(CURL_GLOBAL_DEFAULT);

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, site_url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); 
    res = curl_easy_perform(curl);

    if(res == CURLE_OK) {
      long http_code = 0;
      curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);

      if(http_code == 200) {
        romantic_mes = 1; // Website is up
      } else {
        romantic_mes = -1; // Website is down
      }
    } else {
      romantic_mes = -1; // Website is down
    }

    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();

  if(romantic_mes == 1) {
    printf("My love, the website is up and running. I will always be here when you need me.\n");
  } else {
    printf("My love, unfortunately the website is currently down. But don't worry, I am here to comfort you.\n");
  }

  return 0;
}