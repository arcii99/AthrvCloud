//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

#define WEB_ADDRESS "https://www.google.com"
#define INTERVAL_TIME 60 //In seconds

void check_website_availability() {
   CURL *curl;
   CURLcode response;
   
   curl = curl_easy_init();
   if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, WEB_ADDRESS);
      curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); //No need for body
      
      response = curl_easy_perform(curl);
      
      if(response != CURLE_OK) {
         printf("Error: %s\n", curl_easy_strerror(response));
      }
      else {
         printf("%s is UP!\n", WEB_ADDRESS);
      }
      
      curl_easy_cleanup(curl);
   }
}

int main() {
   int count = 0;
   
   while(1) {
      printf("\nChecking website availability in %d seconds...\n", INTERVAL_TIME);
      sleep(INTERVAL_TIME);
      
      check_website_availability();
      count++;
      
      if(count == 10) { //Check for 10 times
         break;
      }
   }
   
   return 0;
}