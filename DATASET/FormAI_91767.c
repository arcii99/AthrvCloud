//FormAI DATASET v1.0 Category: String manipulation ; Style: creative
#include <stdio.h>
#include <string.h>
int main() {
  char input[100], output[100];
  printf("Enter a string : ");
  gets(input);
  int length = strlen(input);

  printf("Input string : %s\n", input);
  int position1,position2,length_removed;
  printf("Enter starting position for removing : ");
  scanf("%d",&position1);
  printf("Enter position to stop removing : ");
  scanf("%d",&position2);
  length_removed = position2-position1+1;
  if(position1 < position2 && position2<=length && position1>=0){
      for(int i=0;i<position1;i++) output[i]=input[i];
      int k=position2+1;
      for(int i=position1-1;k<length;i++,k++) output[i]=input[k];
      printf("Output string : %s\n", output);
  }
  else {
      printf("Invalid positions \n");
  }
  return 0;
}