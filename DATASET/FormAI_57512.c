//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>

#define MAX_URL_LENGTH 200
#define MAX_TIME_LENGTH 50

typedef struct {
   char url[MAX_URL_LENGTH];
   int timeout;
} MonitorURL;

void monitorURLs(MonitorURL *urls, int count) {
   CURL *curl_handle;
   CURLcode res;
   int i;

   curl_global_init(CURL_GLOBAL_ALL);

   for (i = 0; i < count; i++) {
      curl_handle = curl_easy_init();
      if (curl_handle) {
         curl_easy_setopt(curl_handle, CURLOPT_URL, urls[i].url);
         curl_easy_setopt(curl_handle, CURLOPT_CONNECTTIMEOUT, urls[i].timeout);
         res = curl_easy_perform(curl_handle);

         if(res != CURLE_OK) {
            printf("%s: DOWN\n", urls[i].url);
         } else {
            printf("%s: UP\n", urls[i].url);
         }
         curl_easy_cleanup(curl_handle);
      }
   }
   curl_global_cleanup();
}

int main() {
   MonitorURL urls[] = {
      {"https://www.google.com", 3},
      {"https://www.facebook.com", 3},
      {"https://www.twitter.com", 3},
      {"https://stackoverflow.com", 3}
   };

   int url_count = sizeof(urls) / sizeof(MonitorURL);

   while (1) {
      monitorURLs(urls, url_count);
      sleep(60);
   }

   return 0;
}