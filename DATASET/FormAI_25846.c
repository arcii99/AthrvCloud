//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_URLS 100
#define TIMEOUT 30
#define LOGFILE "website_monitor.log"

int num_urls = 0;
char urls[MAX_URLS][100];

int check_url(char* url) {
  // implementation of website checking goes here
  // returns 1 if website is up, 0 if website is down
  return rand() % 2;
}

void log_result(char* url, int status) {
  FILE* log;
  log = fopen(LOGFILE, "a");
  time_t now;
  time(&now);
  fprintf(log, "%s - [%s] - %s\n", asctime(localtime(&now)), url, status == 1 ? "UP" : "DOWN");
  fclose(log);
}

int main() {
  srand(time(NULL));
  printf("Enter website URLs to monitor (up to %d URLs):\n", MAX_URLS);
  char input[100];
  while (num_urls < MAX_URLS) {
    printf("URL %d: ", num_urls+1);
    fgets(input, sizeof(input), stdin);
    if (input[0] == '\n') {
      break;
    }
    input[strcspn(input, "\n")] = 0;
    strcpy(urls[num_urls], input);
    num_urls++;
  }
  printf("Monitoring %d websites...\n", num_urls);
  while (1) {
    for (int i = 0; i < num_urls; i++) {
      int status = check_url(urls[i]);
      log_result(urls[i], status);
      if (status == 0) {
        printf("%s is DOWN!\n", urls[i]);
      }
    }
    printf("Waiting %d seconds to check again...\n", TIMEOUT);
    sleep(TIMEOUT);
  }
  return 0;
}