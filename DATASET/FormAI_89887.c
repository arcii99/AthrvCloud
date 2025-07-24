//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <unistd.h>

int main() {
  printf("Welcome to the Surrealist Website Uptime Monitor!\n");
  while(1) {
    int status = system("ping -c 1 google.com > /dev/null");
    if(status == 0) {
      printf("The website is up.\n");
    } else {
      printf("The website is down.\n");
      printf("Please grab your umbrella and try again.\n");
    }
    sleep(5);
  }
  return 0;
}