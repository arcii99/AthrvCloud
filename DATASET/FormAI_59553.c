//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  int data;
  int checksum = 0;
  char str[100];

  printf("Enter the data (in hexadecimal form): ");
  scanf("%x", &data);

  sprintf(str, "%X", data); //convert to uppercase hexadecimal string

  printf("Data entered: %s\n", str);

  int len = strlen(str);

  for(int i=0;i<len;i++)
  {
      checksum += str[i]; //summing up ascii values of the characters in the string
  }
  checksum = (checksum & 0xFF) ^ 0xFF; //final XOR operation to generate checksum

  printf("Checksum: %02X\n", checksum); //printing in hexadecimal format with leading zeroes

  return 0;
}