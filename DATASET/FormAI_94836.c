//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Define the website URL to monitor
#define WEBSITE_URL "https://www.example.com/"

// Define the number of seconds to wait between tests
const int TEST_INTERVAL = 60;

bool check_website_availability(const char* url) {
  // Simulate sending an HTTP request by waiting for random number of seconds
  int random_num_seconds = rand() % 10 + 1;
  printf("Sending request to %s...\n", url);
  printf("Waiting for %d seconds...\n", random_num_seconds);
  sleep(random_num_seconds);

  // Simulate random website availability
  bool is_available = (rand() % 100) < 80;
  printf("Website is %s\n", is_available ? "available" : "unavailable");
  return is_available;
}

int main() {
  printf("Starting website uptime monitor...\n");
  srand(time(NULL)); // Seed the random generator with current time
  bool is_website_available = true;

  while (true) {
    if (check_website_availability(WEBSITE_URL)) {
      if (!is_website_available) {
        printf("Website is back online!\n");
        // TODO: send a notification to website admin
      }
      is_website_available = true;
    } else {
      if (is_website_available) {
        printf("Website is down!\n");
        // TODO: send a notification to website admin
      }
      is_website_available = false;
    }

    printf("Waiting for %d seconds before next test...\n", TEST_INTERVAL);
    sleep(TEST_INTERVAL);
  }

  return 0;
}