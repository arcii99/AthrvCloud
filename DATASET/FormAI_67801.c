//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: interoperable
#include<stdio.h>
#include<curl/curl.h>

static int write_data(void *ptr, size_t size, size_t nmemb, void *stream){
  int written = fwrite(ptr, size, nmemb, (FILE *)stream);
  return written;
}

int main(){
  CURL *curl;
  FILE *fp;
  CURLcode res;
  const char *url = "http://speedtest.tele2.net/100MB.zip"; // URL to download a 100MB test file
  
  curl = curl_easy_init();
  if(curl) {
    fp = fopen("testfile.zip","wb"); // Download test file will be saved as testfile.zip
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // Follow redirect
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    res = curl_easy_perform(curl);

    if(res != CURLE_OK){
      printf("Download failed: %s\n", curl_easy_strerror(res));
    }else{
      printf("Download complete!\n");
    }
    fclose(fp);
    curl_easy_cleanup(curl);
  }
  return 0;
}