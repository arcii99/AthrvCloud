//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

static size_t WriteCallbackFunc(char *buffer, size_t size, size_t nmemb, void *userp){
  //writing data to a file
  //for example, the response of the website
  FILE *fp;

  if(!(fp = fopen((char*) userp, "a"))){
    perror("fopen error");
    return 0;
  }

  fwrite(buffer, size, nmemb, fp);
  fclose(fp);

  return size * nmemb;
}

void checkWebsite(char *url){
  CURLcode res;
  CURL *curl_handle;

  curl_global_init(CURL_GLOBAL_ALL);

  curl_handle = curl_easy_init();
  if(curl_handle){
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteCallbackFunc);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, "response.txt");

    res = curl_easy_perform(curl_handle);
    if(res != CURLE_OK){
      fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    curl_easy_cleanup(curl_handle);
  }
  curl_global_cleanup();
}

int main(){
  while(1){
    //check the website every 10 seconds
    sleep(10);
    checkWebsite("https://www.example.com");
  }

  return 0;
}