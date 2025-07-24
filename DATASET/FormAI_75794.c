//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
 
int main(int argc, char *argv[])
{
  CURL *curl;
  CURLcode res;
 
  char url[100];
 
  if(argc < 2){
    printf("Please provide a URL to check.\n");
    return 1;
  }
 
  strcpy(url, argv[1]);
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
 
    res = curl_easy_perform(curl);
    if(res != CURLE_OK){
      printf("Error - %s\n", curl_easy_strerror(res));
    }
    else{
      printf("Success!\n");
    }
 
    curl_easy_cleanup(curl);
  }
 
  return 0;
}