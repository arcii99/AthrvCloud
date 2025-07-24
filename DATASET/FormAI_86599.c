//FormAI DATASET v1.0 Category: Recursive ; Style: post-apocalyptic
#include <stdio.h>

void apocalypse(int daysLeft){
  if(daysLeft <= 0){
    printf("The world as we know it is gone");
  }else{
    apocalypse(daysLeft-1);
    printf("Only %d days left until the apocalypse\n", daysLeft);
  }
}

int main(){
  int days = 50;
  apocalypse(days);
  return 0;
}