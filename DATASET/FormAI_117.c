//FormAI DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>

void errorMsg(int errNum){
  switch(errNum){
    case 1:
      printf("Oh my goodness! An error has occurred.\n");
      break;
    case 2:
      printf("Holy cow! This shouldn't happen.\n");
      break;
    default:
      printf("Oops! Something went wrong.\n");
  }
}

int main(){
  int num = 10;
  int arr[5] = {1,2,3,4,5};
  
  if(num > 5){
    printf("Wow! Everything is running smoothly.\n");
  } else {
    printf("Uh oh! Something's not right.\n");
    errorMsg(1);
    return 1;
  }
  
  printf("Accessing invalid array element...\n");
  
  if(arr[10] != NULL){
    printf("This line should never execute.\n");
  } else {
    errorMsg(2);
    return 1;
  }

  return 0;
}