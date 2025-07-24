//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char *website = "https://example.com";
  FILE *fp;

  while(1) {
    fp = popen("ping -c 1 example.com | grep \"64 bytes\"", "r");

    if(fp == NULL) {
      printf("Error while executing ping command\n");
      exit(1);
    }

    char buffer[1024];
    fread(buffer, 1, sizeof(buffer), fp);

    if(strlen(buffer) > 0) {
      printf("Website is up!\n");
    } else {
      printf("Website is down!\n");
    }

    pclose(fp);
    sleep(5);
  }
  
  return 0;
}