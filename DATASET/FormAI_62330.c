//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

#define MAX_URL_LEN 100
#define MAX_TIME_SEARCH 10

typedef struct website {
  char url[MAX_URL_LEN];
  int status;
  time_t last_checked;
} website_t;

void update_status(website_t *site) {
  CURL *curl;
  CURLcode res;
  long http_code;
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, site->url);
    curl_easy_setopt(curl, CURLOPT_NOBODY, 1L);
    res = curl_easy_perform(curl);
    if(res == CURLE_OK) {
      res = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
      if(res == CURLE_OK)
        site->status = http_code;
    }
    curl_easy_cleanup(curl);
  }
  site->last_checked = time(NULL);
}

void print_website_status(website_t site) {
  char* status_string;
  if (site.status >= 200 && site.status < 300) {
    status_string = "OK";
  } else {
    status_string = "DOWN";
  }
  printf("%s - Status: %d (%s) - Last Checked: %s", site.url, site.status, status_string, ctime(&site.last_checked));
}

int main() {
  website_t websites[] = {
    {"https://www.google.com", 0, 0},
    {"https://www.github.com", 0, 0},
    {"https://www.nonexistentwebsite123.com", 0, 0}
  };
  int num_websites = sizeof(websites) / sizeof(websites[0]);

  while(1) {
    for (int i = 0; i < num_websites; i++) {
      website_t site = websites[i];
      time_t current_time = time(NULL);
      double time_since_last_check = difftime(current_time, site.last_checked);
      if (time_since_last_check > MAX_TIME_SEARCH) {
        update_status(&site);
        websites[i] = site;
      }
      print_website_status(site);
      usleep(100000);
    }
  }
  return 0;
}