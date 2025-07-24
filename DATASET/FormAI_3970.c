//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void wait(int seconds) {
  clock_t end_wait;
  end_wait = clock() + seconds * CLOCKS_PER_SEC;
  while (clock() < end_wait) {}
}

void check_website(char *website, int interval) {
  FILE *fp;
  char command[1000];
  char line[1000];
  sprintf(command, "ping -c 1 %s", website);
  
  while (1) {
    fp = popen(command, "r");
    fgets(line, sizeof(line), fp);
    pclose(fp);

    if (strstr(line, "64 bytes from") != NULL) {
      printf("%s is up\n", website);
    } else {
      printf("%s is down\n", website);
    }
    wait(interval);
  }
}

int main() {
  check_website("www.google.com", 5);
  return 0;
}