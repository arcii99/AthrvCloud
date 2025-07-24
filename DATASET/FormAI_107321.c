//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i, num, sum = 0, checksum;
  char arr[50];

  printf("Enter the string: ");
  scanf("%s", arr);

  //Calculating the sum of ASCII values of the characters
  for(i=0;arr[i]!='\0';i++)
  {
      sum += arr[i];
  }

  //Calculating the checksum
  checksum = 255 - sum + 1;

  //Displaying the original string and checksum
  printf("\nEntered string: %s\nChecksum: %d\n", arr, checksum);

  return 0;
}