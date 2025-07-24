//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>
#include <curl/curl.h>

// Function to check website status
bool websiteIsUp(const char *url){
  CURL *curl = curl_easy_init();
  if(curl) {
    // Set URL to check
    curl_easy_setopt(curl, CURLOPT_URL, url);
    // Set timeout to 5 seconds
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);
    CURLcode res = curl_easy_perform(curl);
    // Error occurred
    if(res != CURLE_OK){
      curl_easy_cleanup(curl);
      return false;
    }
    curl_easy_cleanup(curl);
    return true;
  }
  // Error occurred
  return false;
}

int main(){
  // Introductory message
  printf("Welcome, dear Watson. Today we shall be conducting a website status check.\n"
         "Please enter the URL of the website you wish to check: \n");

  // User input URL to check
  char url[100];
  fgets(url, sizeof(url), stdin);

  // Remove newline character from input
  if(url[strlen(url)-1] == '\n'){
    url[strlen(url)-1] = '\0';
  }

  // Check website status
  if(websiteIsUp(url)){
    printf("Elementary, my dear Watson! The website '%s' is online.\n", url);
  }
  else{
    printf("Dear me, Watson. The website '%s' appears to be offline.\n", url);
  }

  return 0;
}