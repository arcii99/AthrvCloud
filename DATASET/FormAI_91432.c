//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: future-proof
#include<stdio.h>
#include<time.h>
#define MAX_SIZE 100
int main()
{
  time_t t;
  srand((unsigned) time(&t));  // to get truly random numbers
  int arr[MAX_SIZE];
  int i, j, temp;
  int threshold = 10;  // threshold number of failed logins
  int failed_logs = 0;  // current number of failed logins
  int max_interval = 300;  // maximum time interval in seconds between logins
  int min_interval = 60;  // minimum time interval in seconds between logins
  int time_diff;
  
  //initialise the array with random values
  for(i=0;i<MAX_SIZE;i++)
  {
    arr[i] = rand() % 100 + 1;
  }
  
  //sort the array in ascending order
  for(i=0;i<MAX_SIZE;i++)
  {
    for(j=i+1;j<MAX_SIZE;j++)
    {
      if(arr[j]<arr[i])
      {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  //check for failed logins and time intervals
  for(i=0;i<MAX_SIZE-1;i++)
  {
    time_diff = (arr[i+1]-arr[i]);  // calculate time difference between consecutive logins
    if(time_diff>max_interval || time_diff<min_interval)  // check if time interval is within limits
    {
      failed_logs++;  //increment failed login count
      if(failed_logs>=threshold)
      {
        printf("INTRUSION DETECTED!");
        break;
      }
    }
    else
    {
      failed_logs = 0; //reset failed login count if time interval is within limits
    }
  }
  return 0;
}