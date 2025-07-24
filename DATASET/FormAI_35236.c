//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: secure
#include<stdio.h>
#include<string.h>

// function to check for malicious activity
int check_activity(char* activity) {
  int flag = 0;
  char keywords[5][15] = {"rm", "mkdir", "ls", "ps", "kill"};

  // check if activity contains any of the keywords
  for(int i=0; i<5; i++) {
    if(strstr(activity, keywords[i]) != NULL) {
      flag = 1;
      break;
    }
  }
  
  return flag;
}

int main() {
  char activity[50];
  
  printf("Enter activity: ");
  fgets(activity, 50, stdin);

  int activity_flag = check_activity(activity);

  if(activity_flag) {
    printf("Warning: Malicious activity detected!\n");
  } else {
    printf("Activity is safe.\n");
  }

  return 0;
}