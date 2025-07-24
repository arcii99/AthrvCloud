//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curl/curl.h>

// function to initialize a CURL object
CURLcode init(CURL *curl) {
  curl = curl_easy_init();
  if(curl) {
    return CURLE_OK;
  } else {
    return CURLE_FAILED_INIT;
  }
}

// function to perform a CURL HTTP GET request
CURLcode perform_request(CURL *curl, char *url) {
  curl_easy_setopt(curl, CURLOPT_URL, url);
  return curl_easy_perform(curl);
}

// function to calculate the download speed of a given URL
double calculate_speed(CURL *curl, char *url) {
  double speed;
  CURLcode res;

  long size = 0;
  double duration = 0;

  // set the option to calculate the download size
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &size);
  curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);

  // perform the request to get the download size
  res = perform_request(curl, url);
  if(res != CURLE_OK) {
    printf("Error: %s\n", curl_easy_strerror(res));
    return -1.0;
  }

  // reset the CURL handle
  curl_easy_reset(curl);

  // set the option to discard the response body
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

  // set the option to calculate the response time
  curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, NULL);
  curl_easy_setopt(curl, CURLOPT_HEADERDATA, &duration);
  curl_easy_setopt(curl, CURLOPT_FILETIME, 1L);

  // perform the request to get the response time
  res = perform_request(curl, url);
  if(res != CURLE_OK) {
    printf("Error: %s\n", curl_easy_strerror(res));
    return -1.0;
  }

  // calculate the download speed in bytes/second
  if(duration > 0) {
    speed = (double)size / (duration / 1000);
  } else {
    speed = -1.0;
  }

  return speed;
}

int main() {
  CURL *curl;
  CURLcode res;

  // initialize the CURL library
  res = curl_global_init(CURL_GLOBAL_DEFAULT);
  if(res != CURLE_OK) {
    printf("Error: %s\n", curl_easy_strerror(res));
    return 1;
  }

  // initialize a CURL handle
  res = init(curl);
  if(res != CURLE_OK) {
    printf("Error: %s\n", curl_easy_strerror(res));
    curl_global_cleanup();
    return 1;
  }

  // test a few URLs and print their download speeds
  double speed;
  speed = calculate_speed(curl, "https://www.example.com");
  printf("www.example.com: %f bytes/second\n", speed);

  speed = calculate_speed(curl, "https://www.google.com");
  printf("www.google.com: %f bytes/second\n", speed);

  speed = calculate_speed(curl, "https://www.facebook.com");
  printf("www.facebook.com: %f bytes/second\n", speed);

  // cleanup the CURL handle and library
  curl_easy_cleanup(curl);
  curl_global_cleanup();

  return 0;
}