//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

void peaceful(int count){
  if(count == 0){
    printf("Peace begins with a smile\n"); // Mahatma Gandhi
    return;
  }
  peaceful(count-1);
  printf("Love and kindness are never wasted.\n");
}

int main(){
  int count = 5;
  peaceful(count);
  return 0;
}