//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  printf("Welcome to the Internet Speed Test!\n");

  time_t t;

  // Intializes random number generator 
  srand((unsigned) time(&t));

  int download_speed = rand() % 101;
  int upload_speed = rand() % 101;

  printf("Your download speed is %d Mbps\n", download_speed);
  printf("Your upload speed is %d Mbps\n", upload_speed);

  if (download_speed > 50 && upload_speed > 50) {
    printf("Wow! You have an amazing internet connection. Stream, download and browse at ease!\n");
  } else if (download_speed > 30 && upload_speed > 30) {
    printf("Your internet connection is good, but needs some improvement. Consider upgrading your internet plan.\n");
  } else {
    printf("Uh-oh! It looks like you have a slow internet connection. Consider troubleshooting your internet or contacting your internet service provider.\n");
  }

  return 0;
}