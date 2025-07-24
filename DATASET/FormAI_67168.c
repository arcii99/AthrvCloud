//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  printf("Welcome to the Internet Speed Test Application!\n");
  
  int download_speed, upload_speed, ping;
  
  //generate random download and upload speeds
  download_speed = rand()%100 + 1;
  upload_speed = rand()%100 + 1;
  
  //simulate ping by adding random delay time between 20-100ms
  sleep(rand()%80 +20);
  ping = rand()%50 + 1;

  printf("Your download speed is %d Mbps\n", download_speed);
  printf("Your upload speed is %d Mbps\n", upload_speed);
  printf("Your ping is %d ms\n", ping);
  
  if(download_speed>=50 && upload_speed>=50 && ping<=20){
    printf("Awesome! Your internet speed is lightning fast!\n");
  }
  else if(download_speed>=20 && upload_speed>=20 && ping<=50){
    printf("Your internet speed is decent, but could be better!\n");
  }
  else{
    printf("Uh oh, it looks like your internet speed needs some improvement!\n");
  }

  return 0;

}