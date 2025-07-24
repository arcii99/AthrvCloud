//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

// Configuration Variables
#define SLEEP_TIME 10 // Seconds between health checks
#define MAX_RETRY_ATTEMPTS 3 // Maximum number of retry attempts before declaring the site as offline
#define HEALTH_CHECK_TIMEOUT 5 // Timeout in seconds for health check
#define ALERT_MESSAGE "Website is offline!" // Message to be sent in case of site down

// Function that performs a HTTP HEAD request to get the status code of the website
int check_website_status(char *url) {
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, HEALTH_CHECK_TIMEOUT);

    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
      return 0;

    long response_code;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

    curl_easy_cleanup(curl);

    return (response_code == 200);
  }

  return 0;
}

int main(int argc, char *argv[]) {
  char *url = "https://www.example.com"; // URL of the website to monitor
  int retries = 0;
  int site_down = 0;
  
  // Main loop that checks the status of the website in a configurable interval
  while(1) {
    int status = check_website_status(url);

    if(!status && !site_down) {
      retries++;
      if(retries > MAX_RETRY_ATTEMPTS) {
        // Website is down, send alert message
        printf("%s\n", ALERT_MESSAGE);
        site_down = 1;
      }
    }
    else if(status && site_down) {
      // Website is back online
      site_down = 0;
    }
    else {
      retries = 0;
    }

    sleep(SLEEP_TIME);
  }

  return 0;
}