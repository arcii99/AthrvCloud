//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <curl/curl.h>

// Function to randomly generate a number between min and max
int random_num(int min, int max) {
  static bool seeded = false;
  if (!seeded) {
    srand(time(NULL));
    seeded = true;
  }
  return rand() % (max - min + 1) + min;
}

// Function to check if a website is up
bool check_website(char* url) {
  CURL* curl = curl_easy_init();
  CURLcode res;
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    if (res == CURLE_OK) {
      return true;
    }
  }
  return false;
}

int main() {
  char* website = "https://www.crypticwebsite.com";
  int uptime = 0;
  while (true) {
    int rand_num = random_num(1, 60);
    if (rand_num == 1) { // 1 in 60 chance of checking the website
      bool is_up = check_website(website);
      if (is_up) {
        uptime++;
      } else {
        uptime = 0;
        // Send a notification that the website is down
      }
    }
    if (uptime >= 10) { // Send a notification that the website is up
      uptime = 0;
    }
    sleep(60);
  }
  return 0;
}