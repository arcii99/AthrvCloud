//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void check_website_status(char website[]){
  srand(time(NULL));
  int status_code = rand() % 5;
  if(status_code == 0){
    printf("%s is up and running smoothly!\n", website);
  } else if(status_code == 1){
    printf("%s is experiencing some minor connectivity issues.\n", website);
  } else if(status_code == 2){
    printf("Uh oh! %s is down.\n", website);
  } else if(status_code == 3){
    printf("We're having trouble accessing %s. It could be a server issue.\n", website);
  } else{
    printf("It seems %s is taking longer than usual to respond.\n", website);
  }
}

int main(){
  char website[100];
  int interval, i;

  printf("Welcome to the Website Uptime Monitor!\n\n");
  
  printf("Please enter the website URL you would like to monitor: ");
  scanf("%s", website);

  printf("How often (in seconds) would you like to check %s's status: ", website);
  scanf("%d", &interval);

  printf("\nThank you! Website uptime checks for %s will begin in %d second intervals.\n\n", website, interval);

  for(i=1; i<=10; i++){
    check_website_status(website);
    sleep(interval);
  }

  return 0;
}