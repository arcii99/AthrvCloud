//FormAI DATASET v1.0 Category: Firewall ; Style: happy
#include<stdio.h>
#include<stdlib.h>

int main() {

  printf("Welcome to the Happy Firewall Program!!\n");
  printf("We are here to protect you and your computer from any unwanted access.\n");
  printf("Let's start by inputting the IP address of your computer:\n");

  char ipAddress[15];
  fgets(ipAddress, 15, stdin);

  printf("Thank You! Now, let's check if your IP address is allowed or not.\n");

  if(strcmp(ipAddress, "192.168.0.1") == 0) {
    printf("Sorry, your IP address is blocked by the firewall. Please contact the system administrator.\n");
  }
  else if(strcmp(ipAddress, "127.0.0.1") == 0) {
    printf("Your IP address is allowed. Welcome back Captain!\n");
  }
  else {
    printf("Your IP address is not recognized by the firewall. Please provide appropriate credentials to access this system.\n");
  }

  printf("Thank you for using our Happy Firewall Program. Have a great day and stay safe!!\n");

  return 0;
}