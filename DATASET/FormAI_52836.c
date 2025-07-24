//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: surprised
#include<stdio.h>
#include<string.h>

int main(){
  char str[100];
  int checksum = 0;

  printf("Enter the string for which you want to calculate checksum: ");
  fgets(str, 100, stdin);

  for(int i = 0; i < strlen(str); i++){
    checksum += (int)str[i]; // add the ASCII value of each character
  }

  printf("The checksum for the string is: %d \n", checksum);

  return 0;
}