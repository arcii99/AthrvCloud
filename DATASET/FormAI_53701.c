//FormAI DATASET v1.0 Category: Educational ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main(){
  
  // Declare an array of 10 integers
  int arr[10];
  
  // Randomly populate the array with 10 integers between 1 and 100
  for(int i=0; i<10; i++){
    arr[i] = rand() % 100 + 1;
  }
  
  // Surrealist code begins here
  printf("The neon elephant ");
  
  // Use a switch case statement to determine which adjective to use for the elephant
  switch(arr[0]){
    case 1:
    case 2:
    case 3:
      printf("is a magnificent ");
      break;
    case 4:
    case 5:
    case 6:
      printf("is a wobbly ");
      break;
    case 7:
    case 8:
    case 9:
      printf("is an ethereal ");
      break;
    default:
      printf("is a chaotic ");
  }
  
  // Use the second number in the array to determine the color of the elephant
  switch(arr[1]){
    case 1:
    case 2:
    case 3:
      printf("purple ");
      break;
    case 4:
    case 5:
    case 6:
      printf("green ");
      break;
    case 7:
    case 8:
    case 9:
      printf("orange ");
      break;
    default:
      printf("pink ");
  }
  
  // Use the third number in the array to determine the texture of the elephant
  switch(arr[2]){
    case 1:
    case 2:
    case 3:
      printf("elephant with fur ");
      break;
    case 4:
    case 5:
    case 6:
      printf("elephant with feathers ");
      break;
    case 7:
    case 8:
    case 9:
      printf("elephant with scales ");
      break;
    default:
      printf("elephant made of jelly ");
  }
  
  // Use the fourth number in the array to determine the emotion of the elephant
  switch(arr[3]){
    case 1:
    case 2:
    case 3:
      printf("who is joyous ");
      break;
    case 4:
    case 5:
    case 6:
      printf("who is perplexed ");
      break;
    case 7:
    case 8:
    case 9:
      printf("who is melancholic ");
      break;
    default:
      printf("who is enraged ");
  }
  
  // Surrealist code ends here
  printf("is floating in the void.\n");
  
  return 0;
}