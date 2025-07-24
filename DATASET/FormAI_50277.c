//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: synchronous
#include<stdio.h>
#include<time.h>  //including header file time.h a standard header file
//function _sleep with millisecond precision
void _sleep(void)
{
  struct timespec tim; //timespec structure from time library 
  tim.tv_sec = 0;
  tim.tv_nsec = 100000000L; //nanoseconds. L is to indicate the number is long integer.
  if(nanosleep(&tim , &tim) < 0 )   
  {
     printf("failed");   //if nanosleep fails in delaying the process.
  }
}

//function to generate random speed values
int generateSpeed(void)
{
  int speed;
  srand(time(NULL));  //srand helps to get the same array of random numbers on every execution.
  speed = rand()%100 + 1;   //random speed generation from 1 to 100
  return speed;
}

int main()
{
    int download_speed, upload_speed, ping, i;
    printf("Testing internet speed. Please wait\n\n");
    for(i=3; i>0; i--)
    {
        _sleep();  //delay of 1 sec using _sleep() function
        printf("%d...\n",i);  //printing countdown
    }
    printf("\nSpeed Test Complete!\n\n");
    download_speed = generateSpeed();  //random download speed generated
    printf("Download Speed: %d Mbps\n", download_speed);
    upload_speed = generateSpeed();  //random upload speed generated
    printf("Upload Speed: %d Mbps\n", upload_speed);
    ping = rand()%50 + 1;  //ping value generated randomly from 1 to 50
    printf("Ping: %d ms\n", ping);
    return 0;
}