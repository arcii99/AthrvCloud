//FormAI DATASET v1.0 Category: Spam Detection System ; Style: visionary
/* Spam Detection System */

#include<stdio.h>
#include<string.h>

int main() {

  char email[50];
  int i, j, flag;
  char spam[] = "fake";
  
  printf("Enter your email: ");
  scanf("%s", email);
  
  for(i=0; i<strlen(email); i++) {
    switch(email[i]) {
      case '@':
        flag = 1;
        break;
      case '.':
        flag = 2;
        break;
    }
  }
  
  if(flag != 2) {
    printf("Invalid email\n");
    return 0;
  }
  
  for(i=0; i<strlen(email); i++) {
    if(email[i] == '@') {
      for(j=i+1; j<strlen(email); j++) {
        if(email[j] == '.') {
          if(strncmp((email+i+1), spam, j-i-1) == 0) {
            printf("Spam detected\n");
            return 0;
          }
        }
      }
    }
  }
  
  printf("Email is valid\n");
  
  return 0;
}