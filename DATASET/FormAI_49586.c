//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int download_speed() {
  int speed = 0;
  printf("Welcome to the Internet Speed Test Application!\n");
  printf("Testing download speed...\n");
  srand(time(NULL));
  for(int i=1;i<=10;i++) {
    int temp_speed = rand() % 101;
    printf("Download speed: %d Mbps\n", temp_speed);
    if(temp_speed > speed) {
      speed = temp_speed;
    }
  }
  return speed;  
}

int upload_speed() {
  int speed = 0;
  printf("Testing upload speed...\n");
  srand(time(NULL));
  for(int i=1;i<=10;i++) {
    int temp_speed = rand() % 101;
    printf("Upload speed: %d Mbps\n", temp_speed);
    if(temp_speed > speed) {
      speed = temp_speed;
    }
  }
  return speed;  
}

int main() {
  int download = download_speed();
  int upload = upload_speed();
  printf("\n\n");
  printf("Your Internet speed test results:\n");
  printf("Download speed: %d Mbps\n", download);
  printf("Upload speed: %d Mbps\n", upload);
  printf("\n\n");
  if(download > upload) {
    printf("Looks like you are a download kind of person! Nothing wrong with that :)\n");
  } else if(upload > download) {
    printf("Looks like you are an uploader! Keep sharing those memes and cat videos :D\n");
  } else {
    printf("Wow, you have symmetric internet speed! You are balanced like a see-saw :)\n");
  }
  return 0;
}