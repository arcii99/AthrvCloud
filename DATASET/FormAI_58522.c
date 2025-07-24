//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  //initialize variables
  int num_attempts = 5;
  int attempt_count = 0;
  int successful_attempts = 0;
  int failed_attempts = 0;
  int max_attempts_per_hour = 10;
  int max_failed_attempts_before_lockout = 3;
  int lockout_seconds = 60;
  int lockout_countdown = 0;
  
  //seed randomization to simulate attacks
  srand(time(NULL));
  
  //loop through attempts
  while (attempt_count < num_attempts)
  {
    //simulate attack by generating random number
    int attack = rand() % 2;
    
    if (attack == 0) //successful attack
    {
      successful_attempts++;
      
      //if successful attempts exceed maximum per hour, trigger alarm
      if (successful_attempts > max_attempts_per_hour)
      {
        printf("ALERT: Maximum successful attempts per hour exceeded!");
      }
    }
    else //failed attack
    {
      failed_attempts++;
      
      //if failed attempts exceed maximum before lockout, log and continue
      if (failed_attempts >= max_failed_attempts_before_lockout)
      {
        printf("WARNING: Maximum failed attempts before lockout exceeded!");
        failed_attempts = 0;
        lockout_countdown = lockout_seconds;
      }
    }
    
    //if lockout countdown is in progress, decrement by one second
    if (lockout_countdown > 0)
    {
      printf("ALERT: System has been locked out due to excessive failed attempts. %d seconds remaining.", lockout_countdown);
      lockout_countdown--;
      
      //if lockout countdown reaches zero, reset counters and allow attempts again
      if (lockout_countdown == 0)
      {
        printf("ALERT: Lockout has been lifted. Attempts can now be made again.");
        successful_attempts = 0;
        failed_attempts = 0;
      }
    }
    
    attempt_count++;
  }
  
  return 0;
}