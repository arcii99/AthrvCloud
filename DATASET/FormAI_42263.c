//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include <signal.h>

#define INTERVAL 60 // Time interval to check website status in seconds
#define MAX_FAILURES 5 // Number of consecutive failures before notifying user
#define URL "https://www.example.com" // Website URL

volatile int consecutive_failures; // Counter for consecutive failures
volatile int run; // Flag for whether to keep running program

void handle_alarm(int sig) {
  struct timeval tv; 
  gettimeofday(&tv, NULL); // Get current time
  printf("Checking website status at %d.%06d...\n", tv.tv_sec, tv.tv_usec);
  int ret = system("curl -sf -o /dev/null " URL); // Check website status with curl
  if (ret != 0) { // Website is down
    consecutive_failures++;
    if (consecutive_failures >= MAX_FAILURES) { // Notify user after too many consecutive failures
      printf("ERROR: Website is down!\n");
    }
  } else { // Website is up
    if (consecutive_failures > 0) { // If website was down before, notify user that it is back up
      printf("SUCCESS: Website is back up!\n");
    }
    consecutive_failures = 0;
  }
  alarm(INTERVAL); // Reset alarm to check website status again later
}

int main() {
  printf("Starting website uptime monitor for %s...\n", URL);
  consecutive_failures = 0;
  run = 1;
  signal(SIGALRM, handle_alarm); // Register alarm signal handler
  alarm(INTERVAL); // Set first alarm to check website status
  while (run) {
    sleep(1); // Wait for signal interrupt
  }
  printf("Stopping website uptime monitor.\n");
  return 0;
}