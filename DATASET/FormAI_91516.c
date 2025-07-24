//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int userList[10] = {0}; // initialize to zero
  int sum = 0;

  printf("INTRUSION DETECTION SYSTEM 3000. Welcome to your worst nightmare:\n"); 
  printf("Please enter 10 user IDs to confirm access:\n"); 

  for(int i = 0; i < 10; i++) {
    scanf("%d", &userList[i]);
    sum += userList[i];
  }

  if(sum % 2 == 0) {
    printf("Access granted! Even sum detected.\n"); 
  } else {
    printf("Access denied! Odd sum detected. Alerting authorities...\n"); 
    system("start cmd /c \"echo \"Intruder Alert!\" && shred /dev/random\""); // Just kidding! Don't actually run this lol
  }

  return 0; 

}