//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char *argv[])
{
   CURL *curl;
   CURLcode res;
   char *url;

   if(argc < 2) {
     printf("Usage: %s <url>\n",argv[0]);
     return 1;
   }

   url = argv[1];

   curl = curl_easy_init();
   if(curl) {
     curl_easy_setopt(curl, CURLOPT_URL, url);
     curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
     res = curl_easy_perform(curl);
     if(res != CURLE_OK)
       fprintf(stderr, "Error: %s\n", curl_easy_strerror(res));
     curl_easy_cleanup(curl);
   }

   return 0;
}