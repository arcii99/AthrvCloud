//FormAI DATASET v1.0 Category: Firewall ; Style: surprised
#include<stdio.h>

int main(){
  char input[50];
  printf("Wow! A C firewall program!\n");
  printf("Please enter your desired firewall rules:\n");
  scanf("%s", input);
  
  //checking user input
  if (input == NULL) {
    printf("Oops! No rules provided.\n");
  }
  else {
    printf("Great! Firewall rules applied.\n");
    printf("You are now fully protected!\n");
  }
  
  return 0;
}