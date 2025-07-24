//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

int main()
{
  printf("Welcome to the Internet Speed Test Application!\n");
  printf("This application will help you to calculate your internet speed.\n");
  printf("This is an irregular and unique style C program, let's see how it works!\n");

  char choice;

  printf("Do you want to proceed with the test? [y/n]: ");
  scanf("%c",&choice);

  if(choice=='y' || choice=='Y')
  {
    int download_speed, upload_speed;
    printf("Please enter your download speed in Mbps: ");
    scanf("%d",&download_speed);
    printf("Please enter your upload speed in Mbps: ");
    scanf("%d",&upload_speed);

    if(download_speed<0 || upload_speed<0)
    {
      printf("Invalid input, quitting the application...");
      exit(0);
    }

    int download_time = 1024*1024*8/download_speed;
    int upload_time = 1024*1024*8/upload_speed;

    printf("\nCalculating your internet speed...\n");
    printf("\nYour download speed is %d Mbps and it will take %d seconds to download 1 GB file.\n",download_speed,download_time);
    printf("Your upload speed is %d Mbps and it will take %d seconds to upload 1 GB file.\n",upload_speed,upload_time);
  }
  else if(choice=='n' || choice=='N')
  {
    printf("You chose not to proceed, quitting the application...");
    exit(0);
  }
  else
  {
    printf("Invalid choice, quitting the application...");
    exit(0);
  }
  
  return 0;
}