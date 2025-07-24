//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: romantic
#include <stdio.h>
#include <curl/curl.h>
 
int main(void) {
  CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_USERNAME, "your_username");
    curl_easy_setopt(curl, CURLOPT_PASSWORD, "your_password");
    curl_easy_setopt(curl, CURLOPT_URL, "imap://your_mail_server");
    
    /* additional options */
    curl_easy_setopt(curl, CURLOPT_TCP_KEEPALIVE, 1L);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
 
    res = curl_easy_perform(curl);
 
    /* always cleanup */
    curl_easy_cleanup(curl);
  
    return res;
  }
  
  printf("Failed to initialize CURL\n");
  return 1;
}