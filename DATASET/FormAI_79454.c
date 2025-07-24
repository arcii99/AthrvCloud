//FormAI DATASET v1.0 Category: System administration ; Style: bold
/* Emergency Shutdown Program */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  char answer;
  printf("Are you sure you want to shut down the system? (y/n)\n");
  scanf("%c", &answer);
  if(answer == 'y' || answer == 'Y'){
    printf("Shutting down the system...\n");
    sleep(3);
    system("shutdown -h now");
  }
  else if(answer == 'n' || answer == 'N'){
    printf("Shutdown process canceled.\n");
    exit(0);
  }
  else{
    printf("Invalid option. Please try again.\n");
    main();
  }
  return 0;
}